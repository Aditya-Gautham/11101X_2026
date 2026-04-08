#include "main.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "pros/distance.hpp"
#include "pros/motors.h"
#include "pros/screen.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotors({-18, -16, -6}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({1, 13, 2}, pros::MotorGearset::blue);
pros::Motor bottomIntakeMotor(12, pros::MotorGearset::blue);
pros::Motor middleIntakeMotor(-15, pros::MotorGearset::blue);
//pros::Motor bottomIntakeMotors(-18, -19, pros::MotorGearset::blue);
pros::Motor topIntakeMotor(11, pros::MotorGearset::blue);
// middleIntakeMotors removed — now part of bottomIntakeMotors MotorGroup


pros::adi::DigitalOut matchLoadPneumatic('a');//h
pros::adi::DigitalOut intakePneumatic('d');//f
pros::adi::DigitalOut wingPneumatic('c');//e
pros::adi::DigitalOut descorePneumatic('e');
pros::adi::DigitalOut intakeLiftPneumatic('b');//g

pros::Imu imu(7);

pros::Optical colorSensor(2);

// horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
pros::Rotation horizontalEnc(-14);
// vertical tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation verticalEnc(-17);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, 1.99, -3.25);
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, 1.99, -0.375);

pros::Distance distanceLeft(20);
pros::Distance distanceRight(8);
pros::Distance distanceFront(9);

lemlib::Drivetrain drivetrain(&leftMotors,
                            &rightMotors,
                              10.325, // 11.05 inch track width
                              lemlib::Omniwheel::OLD_325, // using old 3.25" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(3.94, // (kP) 4.067
                                            0, // (kI)
                                            4, // (kD)
                                            0, //
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches`
                                            300, // large error range timeout, in milliseconds
                                            15 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(1.82, // (kP) 1.82
                                             0, // (kI)
                                            11, // (kD)11 10.5
                                             0, // anti windup
                                             2, // small error range, in degrees 1, 100, 2, 500
                                             200, // small error range timeout, in milliseconds
                                             4, // large error range, in degrees
                                             250, // large error range timeout, in milliseconds
                                             20 // maximum acceleration (slew)
);


// heading motion controller
lemlib::ControllerSettings headingController(1, // (kP) 2 1
                                             0, // (kI)
                                             30, // (kD) 20 1
                                             0, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             2, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// extra lateral motion controller
lemlib::ControllerSettings linearControllerCurve(4, // (kP) 4.067
                                                 0, // (kI)
                                                 4, // (kD)
                                                 0, //
                                                 1, // small error range, in inches
                                                 100, // small error range timeout, in milliseconds
                                                 3, // large error range, in inches
                                                 300, // large error range timeout, in milliseconds
                                                 15 // maximum acceleration (slew)
);

// extra angular motion controller
lemlib::ControllerSettings angularControllerShort(2.07, // (kP)1.7 1.6
                                                  0, // (kI)
                                                  11, // (kD)11 10.5
                                                  0, // anti windup
                                                  2, // small error range, in degrees
                                                  200, // small error range timeout, in milliseconds
                                                  4, // large error range, in degrees
                                                  250, // large error range timeout, in milliseconds
                                                  20 // maximum acceleration (slew)
);

// extra angular motion controller
lemlib::ControllerSettings angularController135(1.68, // (kP)1.7 1.6
                                                  0, // (kI)
                                                  11, // (kD)11 10.5
                                                  0, // anti windup
                                                  2, // small error range, in degrees
                                                  200, // small error range timeout, in milliseconds
                                                  4, // large error range, in degrees
                                                  250, // large error range timeout, in milliseconds
                                                  20 // maximum acceleration (slew)
);

// extra angular motion controller
lemlib::ControllerSettings angularController180(1.59, // (kP)1.7 1.6
                                                  0, // (kI)
                                                  11, // (kD)11 10.5
                                                  0, // anti windup
                                                  2, // small error range, in degrees
                                                  200, // small error range timeout, in milliseconds
                                                  4, // large error range, in degrees
                                                  250, // large error range timeout, in milliseconds
                                                  20 // maximum acceleration (slew)
);

// extra heading motion controller
lemlib::ControllerSettings headingControllerCurve(3, // (kP) 2 1
                                                  0, // (kI)
                                                  30, // (kD) 20 1
                                                  0, // anti windup
                                                  1, // small error range, in degrees
                                                  100, // small error range timeout, in milliseconds
                                                  2, // large error range, in degrees
                                                  500, // large error range timeout, in milliseconds
                                                  0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, 
                            nullptr, 
                            &horizontal, 
                            nullptr,
                            &imu,
                            &distanceLeft,
                            &distanceRight,
                            &distanceFront
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(10, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(10, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, headingController, linearControllerCurve, angularControllerShort, angularController135, angularController180, headingControllerCurve, sensors);

Intake intake(bottomIntakeMotor, middleIntakeMotor, topIntakeMotor, colorSensor, intakePneumatic);

Matchload matchload(matchLoadPneumatic);

Wing wing(wingPneumatic);

Descore descore(descorePneumatic);

IntakeLift intakeLift(intakeLiftPneumatic);

bool skillsFlag = true;

void initialize() {
    if(skillsFlag) {
       intakeLift.intakeLiftV(0);
    }
    pros::screen::set_eraser(pros::Color::black);
    pros::screen::set_pen(pros::Color::white);
    chassis.calibrate();
    // red alliance - true, blue alliance - false
    intake.calibrate(true);
    matchload.calibrate();
    wing.calibrate();
    descore.calibrate();
}

void disabled() {}

void competitionInitialize() {}

// get a path used for pure pursuit
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

void autonomous() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    intake.driverControl = false;
    //intake.intakeJam(true);
    bool runAuton = true;
    if (!horizontalEnc.is_installed()) {
        pros::screen::print(pros::E_TEXT_LARGE, 3, "Horizontal Encoder not installed");
        runAuton = false;
    }
    if (!verticalEnc.is_installed()) {
        pros::screen::print(pros::E_TEXT_LARGE, 4, "Vertical Encoder not installed");
        runAuton = false;
    }
    pros::Task printCoordsTask([]() {
        bool thetaExceeded90 = false; // Track if theta has ever exceeded 90
        while (true) {
            lemlib::Pose pose = chassis.getPose();
            pros::screen::print(pros::E_TEXT_MEDIUM, 0, "x: %.2f",pose.x);
            pros::screen::print(pros::E_TEXT_MEDIUM, 1, "y: %.2f", pose.y);
            pros::screen::print(pros::E_TEXT_MEDIUM, 2, "theta: %.2f", pose.theta);
            if (pose.theta > 136) {
                pros::screen::print(pros::E_TEXT_MEDIUM, 3, "Theta exceeded 91!");
            }
            pros::delay(20); // Update every 20ms
        }
    });

    if (runAuton)
    {
    //odomTest();
    //leftFourLongFourMiddle();
    //leftFourLongFourMiddleWing();
    //leftFourLong();
    //leftSevenLong();
    //leftSixLongThreeMiddle();
    //rightFourLongThreeLow();
    //rightSevenLong();
    //rightFourLong();
    //rightNineLong();
    //rightSixLongThreeMiddle();
    //rightThreeGoal();
    //soloWinPoint();
    skills();
    }
}

void opcontrol() {
    intake.driverControl = true;
    intake.colorSortActive = false;
    // intake hold state machine for L1/R2
    enum IntakeHoldState { IH_Off, IH_PreReverse, IH_Intake };
    IntakeHoldState holdState = IH_Off;
    unsigned long holdStart = 0;
    bool holdSourceL1 = false; // true if the current hold was started by L1, false if R2
    bool prevL1 = false;  // still track to identify transitions if needed
    bool prevR2 = false;
    while (true) {
        int vert = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int horz = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        if (abs(vert) < 7) vert = 0;
        chassis.arcade(vert, horz);

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake.outtake();
        }
        // handle holds on either L1 or R2 with non-blocking timer
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) ||
                controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
        {
            bool curL1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
            bool curR2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
            bool active = curL1 || curR2;

            if (active && holdSourceL1) {
                if (holdState == IH_Off) {
                    holdState = IH_PreReverse;
                    holdStart = pros::millis();
                    intake.moveBottomIntake(-300);
                    holdSourceL1 = curL1;
                }
                if (holdState == IH_PreReverse) {
                    if (pros::millis() - holdStart >= 100) {
                        holdState = IH_Intake;
                    }
                }
                if (holdState == IH_Intake) {
                        intake.intakePneumaticV(1);
                        intake.longGoal();
                }
            }

            if (active && !holdSourceL1) {
                if (holdState == IH_Off) {
                    holdState = IH_PreReverse;
                    holdStart = pros::millis();
                    intake.moveBottomIntake(-600);
                    intake.moveMiddleIntake(-600);
                    intake.moveTopIntake(-600);
                    holdSourceL1 = curL1;
                }
                if (holdState == IH_PreReverse) {
                    if (pros::millis() - holdStart >= 100) {
                        holdState = IH_Intake;
                    }
                }
                if (holdState == IH_Intake) {
                        intake.middleGoal();
                }
            }

            prevL1 = curL1; // track L1 now
            prevR2 = curR2;
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
        {
            intake.intakePneumaticV(0);
            intake.hoard();
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
        {
            intake.intakeOutSkills();
        }
        else {
            intake.stopIntake();
            // reset state and prev flags when no button is held
            holdState = IH_Off;
            prevL1 = prevR2 = false;
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            if(descore.descoreValue())
            {
                descore.descoreV(0);
                pros::delay(100);
            }
            matchload.matchloadChange();
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            if(matchload.matchloadValue())
            {
                matchload.matchloadV(1);
                pros::delay(100);
            }
            descore.descoreChange();
        }


        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            wing.wingChange();
        }
        pros::delay(10);

    }
}