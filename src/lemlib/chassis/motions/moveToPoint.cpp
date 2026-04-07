#include <cmath>
#include "lemlib/timer.hpp"
#include "main.h"
#include "math.h"
using namespace std;

void lemlib::Chassis::moveToPoint(float x, float y, int timeout, MoveToPointParams params, bool async) {
    params.earlyExitRange = fabs(params.earlyExitRange);
    this->requestMotionStart();
    // were all motions cancelled?
    if (!this->motionRunning) return;
    // if the function is async, run it in a new task
    if (async) {
        pros::Task task([&]() { moveToPoint(x, y, timeout, params, false); });
        this->endMotion();
        pros::delay(10); // delay to give the task time to start
        return;
    }

    // select PID settings based on pidSelector
    ControllerSettings selectedLateralSettings = (params.pidSelector == 0) ? lateralSettings : lateralSettingsCurve;
    ControllerSettings selectedHeadingSettings = (params.pidSelector == 0) ? headingSettings : headingSettingsCurve;

    // create local PIDs and exit conditions
    PID localLateralPID(selectedLateralSettings.kP, selectedLateralSettings.kI, selectedLateralSettings.kD, selectedLateralSettings.windupRange, true);
    // localHeadingPID uses selectedHeadingSettings
    PID localHeadingPID(selectedHeadingSettings.kP, selectedHeadingSettings.kI, selectedHeadingSettings.kD, selectedHeadingSettings.windupRange, true);
    ExitCondition localLateralLargeExit(selectedLateralSettings.largeError, selectedLateralSettings.largeErrorTimeout);
    ExitCondition localLateralSmallExit(selectedLateralSettings.smallError, selectedLateralSettings.smallErrorTimeout);

    // reset local PIDs and exit conditions
    localLateralPID.reset();
    localLateralLargeExit.reset();
    localLateralSmallExit.reset();
    localHeadingPID.reset();

    // initialize vars used between iterations
    Pose lastPose = getPose();
    distTraveled = 0;
    Timer timer(timeout);
    bool close = false;
    float prevLateralOut = 0; // previous lateral power
    float prevHeadingOut = 0; // previous heading power
    const int compState = pros::competition::get_status();
    std::optional<bool> prevSide = std::nullopt;

    // calculate target pose in standard form
    Pose target(x, y);
    const float pathAngle = lastPose.angle(target);

    // main loop
    while (!timer.isDone() && ((!localLateralSmallExit.getExit() && !localLateralLargeExit.getExit()) || !close) &&
           this->motionRunning) {
        // update position
        const Pose pose = getPose(true, true);
        
        // update distance traveled
        distTraveled += pose.distance(lastPose);
        lastPose = pose;

        // calculate distance to the target point
        const float distTarget = pose.distance(target);

        // check if the robot is close enough to the target to start settling
        if (distTarget < 7.5 && close == false) {
            close = true;
            params.maxSpeed = fmax(fabs(prevLateralOut), 60);
        }

        // motion chaining
        const bool side =
            (pose.y - target.y) * -sin(pose.angle(target)) <= (pose.x - target.x) * cos(pose.angle(target)) + params.earlyExitRange;
        if (prevSide == std::nullopt) prevSide = side;
        const bool sameSide = side == prevSide;
        // exit if close
        if (!sameSide && params.minSpeed != 0) break;
        prevSide = side;

        // calculate error
        const float adjustedRobotTheta = params.forwards ? pose.theta : pose.theta + M_PI;
        
        // Decide if we chase the "Carrot" or stay on the "Rail"
        float targetHeading;
        float lateralError;
        if (params.chasePoint) {
            targetHeading = pose.angle(target); // Carrot (Standard)
            lateralError = distTarget * cos(angleError(pose.theta, targetHeading));
        } else {
            targetHeading = pathAngle; // Rail (Stable Reverse)
            lateralError = params.forwards ? distTarget : -distTarget;
        }

        // recalculate angular error dynamically relative to the point or line
        const float headingError = angleError(adjustedRobotTheta, targetHeading);

        // update exit conditions
        localLateralSmallExit.update(lateralError);
        localLateralLargeExit.update(lateralError);

        // get output from PIDs
        float lateralOut = localLateralPID.update(lateralError);
        float headingOut = localHeadingPID.update(radToDeg(headingError));
        
        // stop angular correction when very close to target to prevent jitter
        if (distTarget < 6.5) {
            headingOut = 0;
        }
        // apply drive clamping only if we are stopping or have passed the early exit point
        if (params.clampDistance) {
            if (distTarget < (distTraveled / 3.0)) {
                float clampLimit = distTarget * 4.0; 
                lateralOut = std::clamp(lateralOut, -clampLimit, clampLimit);

                // provide minimum voltage to ensure the robot reaches the target
                if (params.forwards && lateralOut < 6 && lateralOut > 0) lateralOut = 6;
                if (!params.forwards && lateralOut > -6 && lateralOut < 0) lateralOut = -6;
            }
        }

        // apply restrictions on heading speed
        headingOut = std::clamp(headingOut, -params.maxSpeed, params.maxSpeed);

        // apply restrictions on lateral speed
        lateralOut = std::clamp(lateralOut, -params.maxSpeed, params.maxSpeed);
        // constrain lateral output by max accel
        // but not for decelerating, since that would interfere with settling
        if (!close) lateralOut = slew(lateralOut, prevLateralOut, selectedLateralSettings.slew);

        // prevent moving in the wrong direction
        if (params.forwards && !close) lateralOut = std::fmax(lateralOut, 0);
        else if (!params.forwards && !close) lateralOut = std::fmin(lateralOut, 0);

        // constrain lateral output by the minimum speed
        if (params.forwards && lateralOut < fabs(params.minSpeed) && lateralOut > 0) lateralOut = fabs(params.minSpeed);
        if (!params.forwards && -lateralOut < fabs(params.minSpeed) && lateralOut < 0)
            lateralOut = -fabs(params.minSpeed);

        // update previous output
        prevHeadingOut = headingOut;
        prevLateralOut = lateralOut;

        // ratio the speeds to respect the max speed and prioritize heading
        float leftPower = lateralOut + headingOut;
        float rightPower = lateralOut - headingOut;
        const float maxMag = std::max(std::fabs(leftPower), std::fabs(rightPower));
        if (maxMag > params.maxSpeed) {
            float excess = maxMag - params.maxSpeed;
            lateralOut -= (lateralOut > 0) ? excess : -excess;
            leftPower = lateralOut + headingOut;
            rightPower = lateralOut - headingOut;
        }

        // move the drivetrain
        drivetrain.leftMotors->move(leftPower);
        drivetrain.rightMotors->move(rightPower);

        // delay to save resources
        pros::delay(10);
    }

    // stop the drivetrain
    drivetrain.leftMotors->move(0);
    drivetrain.rightMotors->move(0);
    // set distTraveled to -1 to indicate that the function has finished
    distTraveled = -1;
    this->endMotion();
}