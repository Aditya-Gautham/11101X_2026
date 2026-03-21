#include <math.h>
#include "pros/imu.hpp"
#include "pros/motors.h"
#include "pros/rtos.h"
#include "lemlib/logger/logger.hpp"
#include "lemlib/util.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/rtos.hpp"

lemlib::OdomSensors::OdomSensors(TrackingWheel* vertical1, TrackingWheel* vertical2, TrackingWheel* horizontal1,
                                 TrackingWheel* horizontal2, pros::Imu* imu, pros::Distance* distanceLeft, pros::Distance* distanceRight, pros::Distance* distanceFront)
    : vertical1(vertical1),
      vertical2(vertical2),
      horizontal1(horizontal1),
      horizontal2(horizontal2),
      imu(imu),
      distanceLeft(distanceLeft),
      distanceRight(distanceRight),
      distanceFront(distanceFront) {}

lemlib::Drivetrain::Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors, float trackWidth,
                               float wheelDiameter, float rpm, float horizontalDrift)
    : leftMotors(leftMotors),
      rightMotors(rightMotors),
      trackWidth(trackWidth),
      wheelDiameter(wheelDiameter),
      rpm(rpm),
      horizontalDrift(horizontalDrift) {}

lemlib::Chassis::Chassis(Drivetrain drivetrain, ControllerSettings linearSettings, ControllerSettings angularSettings,
                         ControllerSettings linearSettingsCurve, ControllerSettings angularSettingsShort, ControllerSettings angularSettings135, ControllerSettings angularSettings180, ControllerSettings headingSettingsCurve,
                         OdomSensors sensors, DriveCurve* throttleCurve, DriveCurve* steerCurve)
    : drivetrain(drivetrain),
      lateralSettings(linearSettings),
      angularSettings(angularSettings),
      headingSettings(angularSettings), // Use angularSettings for heading when not specified
      lateralSettingsCurve(linearSettingsCurve),
      angularSettingsShort(angularSettingsShort),
      angularSettings135(angularSettings135),
      angularSettings180(angularSettings180),
      headingSettingsCurve(headingSettingsCurve),
      sensors(sensors),
      throttleCurve(throttleCurve),
      steerCurve(steerCurve),
      lateralPID(linearSettings.kP, linearSettings.kI, linearSettings.kD, linearSettings.windupRange, true),
      angularPID(angularSettings.kP, angularSettings.kI, angularSettings.kD, angularSettings.windupRange, true),
      headingPID(angularSettings.kP, angularSettings.kI, angularSettings.kD, angularSettings.windupRange, true), // Use angularSettings for heading
      lateralLargeExit(lateralSettings.largeError, lateralSettings.largeErrorTimeout),
      lateralSmallExit(lateralSettings.smallError, lateralSettings.smallErrorTimeout),
      angularLargeExit(angularSettings.largeError, angularSettings.largeErrorTimeout),
      angularSmallExit(angularSettings.smallError, angularSettings.smallErrorTimeout),
      headingLargeExit(angularSettings.largeError, angularSettings.largeErrorTimeout), // Use angularSettings for heading exit conditions
      headingSmallExit(angularSettings.smallError, angularSettings.smallErrorTimeout) {} // Use angularSettings for heading exit conditions

lemlib::Chassis::Chassis(Drivetrain drivetrain, ControllerSettings linearSettings, ControllerSettings angularSettings, ControllerSettings headingSettings,
                         ControllerSettings linearSettingsCurve, ControllerSettings angularSettingsShort, ControllerSettings angularSettings135, ControllerSettings angularSettings180, ControllerSettings headingSettingsCurve,
                         OdomSensors sensors, DriveCurve* throttleCurve, DriveCurve* steerCurve)
    : drivetrain(drivetrain),
      lateralSettings(linearSettings),
      angularSettings(angularSettings),
      headingSettings(headingSettings),
      lateralSettingsCurve(linearSettingsCurve),
      angularSettingsShort(angularSettingsShort),
      angularSettings135(angularSettings135),
      angularSettings180(angularSettings180),
      headingSettingsCurve(headingSettingsCurve),
      sensors(sensors),
      throttleCurve(throttleCurve),
      steerCurve(steerCurve),
      lateralPID(linearSettings.kP, linearSettings.kI, linearSettings.kD, linearSettings.windupRange, true),
      angularPID(angularSettings.kP, angularSettings.kI, angularSettings.kD, angularSettings.windupRange, true),
      headingPID(headingSettings.kP, headingSettings.kI, headingSettings.kD, headingSettings.windupRange, true),
      lateralLargeExit(lateralSettings.largeError, lateralSettings.largeErrorTimeout),
      lateralSmallExit(lateralSettings.smallError, lateralSettings.smallErrorTimeout),
      angularLargeExit(angularSettings.largeError, angularSettings.largeErrorTimeout),
      angularSmallExit(angularSettings.smallError, angularSettings.smallErrorTimeout),
      headingLargeExit(headingSettings.largeError, headingSettings.largeErrorTimeout),
      headingSmallExit(headingSettings.smallError, headingSettings.smallErrorTimeout) {}

/**
 * @brief calibrate the IMU given a sensors struct
 *
 * @param sensors reference to the sensors struct
 */
void calibrateIMU(lemlib::OdomSensors& sensors) {
    int attempt = 1;
    bool calibrated = false;
    // calibrate inertial, and if calibration fails, then repeat 5 times or until successful
    while (attempt <= 5) {
        sensors.imu->reset();
        // wait until IMU is calibrated
        do pros::delay(10);
        while (sensors.imu->get_status() != pros::ImuStatus::error && sensors.imu->is_calibrating());
        // exit if imu has been calibrated
        if (!isnanf(sensors.imu->get_heading()) && !isinf(sensors.imu->get_heading())) {
            calibrated = true;
            break;
        }
        // indicate error
        pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, "---");
        lemlib::infoSink()->warn("IMU failed to calibrate! Attempt #{}", attempt);
        attempt++;
    }
    // check if calibration attempts were successful
    if (attempt > 5) {
        sensors.imu = nullptr;
        lemlib::infoSink()->error("IMU calibration failed, defaulting to tracking wheels / motor encoders");
    }
}

void lemlib::Chassis::calibrate(bool calibrateImu) {
    // calibrate the IMU if it exists and the user doesn't specify otherwise
    if (sensors.imu != nullptr && calibrateImu) calibrateIMU(sensors);
    // initialize odom
    if (sensors.vertical1 == nullptr)
        sensors.vertical1 = new lemlib::TrackingWheel(drivetrain.leftMotors, drivetrain.wheelDiameter,
                                                      -(drivetrain.trackWidth / 2), drivetrain.rpm);
    if (sensors.vertical2 == nullptr)
        sensors.vertical2 = new lemlib::TrackingWheel(drivetrain.rightMotors, drivetrain.wheelDiameter,
                                                      drivetrain.trackWidth / 2, drivetrain.rpm);
    sensors.vertical1->reset();
    sensors.vertical2->reset();
    if (sensors.horizontal1 != nullptr) sensors.horizontal1->reset();
    if (sensors.horizontal2 != nullptr) sensors.horizontal2->reset();
    setSensors(sensors, drivetrain);
    init();
    // rumble to controller to indicate success
    pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, ".");
}

void lemlib::Chassis::setPose(float x, float y, float theta, bool radians) {
    lemlib::setPose(lemlib::Pose(x, y, theta), radians);
}

void lemlib::Chassis::setPose(Pose pose, bool radians) { lemlib::setPose(pose, radians); }

lemlib::Pose lemlib::Chassis::getPose(bool radians, bool standardPos) {
    Pose pose = lemlib::getPose(true);
    if (standardPos) pose.theta = M_PI_2 - pose.theta;
    if (!radians) pose.theta = radToDeg(pose.theta);
    return pose;
}

void lemlib::Chassis::waitUntil(float dist) {
    // repeatedly yield so other tasks (motion thread) can run
    do {
        pros::delay(10);
    } while (distTraveled <= dist && distTraveled != -1);
}

void lemlib::Chassis::waitUntilDone() {
    // repeatedly yield until motion indicates completion
    do {
        pros::delay(10);
    } while (distTraveled != -1);
}

void lemlib::Chassis::requestMotionStart() {
    if (this->isInMotion()) this->motionQueued = true; // indicate a motion is queued
    else this->motionRunning = true; // indicate a motion is running

    // wait until this motion is at front of "queue"
    this->mutex.take(TIMEOUT_MAX);

    // this->motionRunning should be true
    // and this->motionQueued should be false
    // indicating this motion is running
}

void lemlib::Chassis::endMotion() {
    // move the "queue" forward 1
    this->motionRunning = this->motionQueued;
    this->motionQueued = false;

    // permit queued motion to run
    this->mutex.give();
}

void lemlib::Chassis::cancelMotion() {
    this->motionRunning = false;
    pros::delay(10); // give time for motion to stop
}

void lemlib::Chassis::cancelAllMotions() {
    this->motionRunning = false;
    this->motionQueued = false;
    pros::delay(10); // give time for motion to stop
}

bool lemlib::Chassis::isInMotion() const { return this->motionRunning; }

void lemlib::Chassis::resetLocalPosition() {
    float theta = this->getPose().theta;
    lemlib::setPose(lemlib::Pose(0, 0, theta), false);
}

void lemlib::Chassis::setBrakeMode(pros::motor_brake_mode_e mode) {
    drivetrain.leftMotors->set_brake_mode_all(mode);
    drivetrain.rightMotors->set_brake_mode_all(mode);
}

// Distance sensor reset logic
const float field_half_size = 70.25;

void lemlib::Chassis::resetPositionWithSensor(pros::Distance* sensor, 
    double sensor_offset, double sensor_angle_offset) {
    if (sensor == nullptr) return;
    
    // 1. SAFE READ FILTERING
    int rawMm = sensor->get_distance();
    // Reject error codes (0), out of range (9999), or values over 2000mm
    if (rawMm <= 20 || rawMm > 2000) return; 

    double sensorReading = rawMm / 25.4;
    
    // Reject readings under 1.5 inches (sensor blind spot)
    if (sensorReading < 1.5) return;

    // 2. Get current pose and normalize heading
    Pose pose = this->getPose(); 
    double headingRad = pose.theta * (M_PI / 180.0);
    double sensorAngleRad = sensor_angle_offset * (M_PI / 180.0);
    double totalAngleRad = headingRad + sensorAngleRad;

    double normalizedAngle = fmod(totalAngleRad, 2 * M_PI);
    if (normalizedAngle < 0) normalizedAngle += 2 * M_PI;

    // 3. Determine target wall 
    bool resettingX = false;
    double wallCoordinate = 0;
    double targetWallAngleRad = 0;

    if (normalizedAngle > M_PI_4 && normalizedAngle <= 3 * M_PI_4) {
        targetWallAngleRad = M_PI_2; // East Wall
        resettingX = true;
        wallCoordinate = field_half_size;
    } else if (normalizedAngle > 3 * M_PI_4 && normalizedAngle <= 5 * M_PI_4) {
        targetWallAngleRad = M_PI;   // South Wall
        resettingX = false;
        wallCoordinate = -field_half_size;
    } else if (normalizedAngle > 5 * M_PI_4 && normalizedAngle <= 7 * M_PI_4) {
        targetWallAngleRad = 3 * M_PI_2; // West Wall
        resettingX = true;
        wallCoordinate = -field_half_size;
    } else {
        targetWallAngleRad = 0;      // North Wall
        resettingX = false;
        wallCoordinate = field_half_size;
    }

    // 4. THE 5-DEGREE GUARD
    double angleDiff = fabs(totalAngleRad - targetWallAngleRad);
    if (angleDiff > M_PI) angleDiff = 2 * M_PI - angleDiff;
    if (angleDiff > (5.0 * M_PI / 180.0)) return; 

    // 5. COSINE CORRECTION
    double totalDist = sensorReading + sensor_offset;
    double correctedDist = totalDist * cos(angleDiff);
    
    // 6. AREA VALIDATION (Sanity Check)
    double calculatedPos = wallCoordinate - (correctedDist * (wallCoordinate > 0 ? 1 : -1));
    double currentPos = resettingX ? pose.x : pose.y;

    // Reject if the sensor data suggests a jump larger than 12 inches
    if (fabs(calculatedPos - currentPos) > 12.0) return;

    // 7. Apply to LemLib Pose - AXIS ISOLATED
    if (resettingX) {
        // Update X, keep Y exactly as it was
        this->setPose(calculatedPos, pose.y, pose.theta);
    } else {
        // Update Y, keep X exactly as it was
        this->setPose(pose.x, calculatedPos, pose.theta);
    }
}