#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/subsystems/intake.hpp"
#include "lemlib/timer.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
//

void odomTest() {
    //intake.setHold();
    /*intakeLift.intakeLiftV(1);
    intake.outtakeAutonSkills();
    pros::delay(1250);
    intake.outtakeAutonSkillsTop();
    pros::delay(2900);
    chassis.setDrive(1500, 1500);
    pros::delay(600);
    chassis.setDrive(0,0);
    intake.stopIntake();
    */
    chassis.setPose(-48, 24, 0);
    intakeLift.intakeLiftV(0);
    chassis.resetPositionLeftAlways();
    chassis.resetPositionFrontAlways();
    intake.stopIntake();
    chassis.moveToPoint(-48, 41.75, 1500, {.minSpeed = 40, .earlyExitRange = 2});
    chassis.turnToPoint(0, 42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    intake.intakePneumaticV(0);
    chassis.moveToPoint(0, 42, 1500, {.minSpeed = 7});
    chassis.turnToPoint(0, 72, 1000, {.minSpeed = 5, .earlyExitRange = 1});
    intake.hoard();
    chassis.waitUntilDone();
    //park zone #2
    chassis.setDrive(6500, 6500);
    pros::delay(850);
    chassis.setDrive(0,0);
    pros::delay(700);
    chassis.setDrive(5000, 5000);
    pros::delay(400);
    chassis.setDrive(0,0);
    pros::delay(800);
    chassis.setDrive(3000, 3000);
    pros::delay(450);
    chassis.setDrive(0,0);
    pros::delay(500);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(250);
    chassis.setDrive(-2000, -2000);
    pros::delay(150);
    chassis.setDrive(0,0);
    chassis.turnToHeading(0, 500, {.minSpeed = 7, .pidSelector = 1});
    chassis.waitUntilDone();
    chassis.resetPositionFrontAlways();
    chassis.resetPositionLeftAlways();
    pros::delay(10);
    chassis.turnToPoint(-24, 24, 1500, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-24, 24, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.turnToPoint(-11.65, 11.4, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-11.65, 11.4, 2000, {.minSpeed = 10});
    intakeLift.intakeLiftV(1);
    //chassis.turnToHeading(315, 1500, {.minSpeed = 15});
    //score low goal
    //intakeLift.intakeLiftV(1);
    pros::delay(500);
    intake.outtakeAutonSkills();
    pros::delay(1000);
    intake.outtakeAutonSkillsTop();
    pros::delay(2200);
    //chassis.setDrive(1500, 1500);
    //pros::delay(600);
    //chassis.setDrive(0,0);
    //intake.stopIntake();
    //get three balls
    chassis.moveToPoint(-24, 24, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    intakeLift.intakeLiftV(0);
    chassis.turnToPoint(22.5, 26, 1500, {.minSpeed = 10, .earlyExitRange = 2, .pidSelector = 1});
    intake.hoard();
    intake.intakePneumaticV(1);
    chassis.moveToPoint(22.5, 26, 1700, {.minSpeed = 30, .earlyExitRange = 3});
    chassis.turnToPoint(46, 47, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(46, 47, 2000, {.minSpeed = 15 , .earlyExitRange = 2});
    pros::delay(100);
    intake.intakePneumaticV(0);
    pros::delay(600);
    matchload.matchloadV(1);
    //matchload #1
    chassis.turnToPoint(47, 61, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(47, 61, 1900, {.minSpeed = 45, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(1900);
    //chassis.resetPositionRightSkills();
    //chassis.resetPositionFrontSkills();
    //go to long goal #1
    chassis.moveToPoint(58.75, 30, 1900, {.forwards = false, .minSpeed = 45, .earlyExitRange = 5, .pidSelector = 1, .clampDistance = false});
    //chassis.moveToPoint(57.5, -13, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1});
    chassis.turnToPoint(59.35, -16, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(59.35, -16, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    //chassis.moveToPoint(52, -17, 1900, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    matchload.matchloadV(0);
    //score long goal
    chassis.swingToHeading(180, DriveSide::LEFT, 1700, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 50, .earlyExitRange = 5});
    chassis.waitUntilDone();
    chassis.setDrive(-9000, -9000);
    matchload.matchloadV(1);
    intake.moveBottomIntake(-100);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(48, -62, 700, {.minSpeed = 15, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(700);
    intake.hoard();
    //matchload #2
    chassis.moveToPoint(48, -62, 2200, {.minSpeed = 30, .clampDistance = false});
    pros::delay(1000);
    intake.intakePneumaticV(0);
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(48, -28, 500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(500);
    //long goal #2
    chassis.moveToPoint(48, -28, 2500, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(15);
    intake.moveBottomIntake(-300);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-300);
    pros::delay(300);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1700);
    matchload.matchloadV(0);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.moveToPoint(24, -63.5, 1400, {.minSpeed = 25, .earlyExitRange = 4, .pidSelector = 1});
    pros::delay(500);
    intake.intakePneumaticV(0);
    chassis.swingToHeading(260, DriveSide::RIGHT, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    chassis.waitUntilDone();
    //park zone #2
    chassis.setDrive(9000, 9000);
    pros::delay(850);
    chassis.setDrive(0,0);


    
    //chassis.resetPositionLeft();
    //chassis.resetPositionFront();
/*
    matchload.matchloadV(1);
    intake.intakePneumaticV(1);
    intakeLift.intakeLiftV(0);
    pros::delay(400);
    intake.moveBottomIntake(-400);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-500);
    //chassis.turnToPoint(48, -48, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(350);
    intake.intakeOutSkills();
    pros::delay(2200);
    intake.intakeOutSkillsSlow();
    pros::delay(1000);
    intake.stopIntake();
    */
    /*

    chassis.setPose(48, -28, 180);
    chassis.resetPositionLeftAlways();
    chassis.resetPositionFrontAlways();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(48, -42, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.turnToPoint(0, -42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(0, -42, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    chassis.turnToPoint(0, -72, 1000, {.minSpeed = 5 , .earlyExitRange = 1});
    intake.hoard();
    chassis.waitUntilDone();
    chassis.setDrive(6000, 6000);
    pros::delay(850);
    chassis.setDrive(0,0);
    pros::delay(700);
    chassis.setDrive(4000, 4000);
    pros::delay(400);
    chassis.setDrive(0,0);
    pros::delay(800);
    //chassis.setDrive(-3000, -3000);
    //pros::delay(300);
    chassis.setDrive(4000, 4000);
    pros::delay(500);
    chassis.setDrive(0,0);
    pros::delay(600);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(250);
    chassis.setDrive(-2000, -2000);
    pros::delay(200);
    chassis.setDrive(0,0);
    chassis.turnToHeading(180, 500, {.minSpeed = 5, .pidSelector = 1});
    pros::delay(500);
    chassis.resetPositionFrontAlways();
    chassis.resetPositionRightAlways();
    pros::delay(100);
    chassis.turnToPoint(-9, -16.25, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    chassis.moveToPoint(-9, -16.25, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    intake.stopIntake();
    chassis.swingToHeading(225, DriveSide::LEFT, 1300, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 70, .earlyExitRange = 3});
    chassis.waitUntilDone();
    chassis.setDrive(-7000, -7000);
    pros::delay(200);
    chassis.setDrive(0,0);
    chassis.moveToPoint(-17.8, -17.8, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    intake.moveBottomIntake(600);
    chassis.moveToPoint(-10, -10, 2000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    pros::delay(400);
    matchload.matchloadV(1);
    intake.intakePneumaticV(1);
    pros::delay(300);
    intake.moveBottomIntake(-400);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-500);
    pros::delay(400);
    intake.intakeOutSkills();
    pros::delay(2400);
    intake.intakeOutSkillsSlow();
    matchload.matchloadV(0);
    pros::delay(1300);
    intake.stopIntake();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(-47.85, -47, 2000, {.minSpeed = 25, .earlyExitRange = 5, .clampDistance = false});
    intake.hoard();
    pros::delay(400);
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.75, -60.25, 900, {.minSpeed = 20, .earlyExitRange = 10, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-47.75, -60.25, 1900, {.minSpeed = 40, .clampDistance = false});
    pros::delay(1900);
    chassis.resetPositionRightSkills();
    chassis.resetPositionFrontSkills();

    /*chassis.turnToPoint(0, -42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(0, -42, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    chassis.turnToPoint(0, -72, 1000, {.minSpeed = 5 , .earlyExitRange = 1});
    intake.hoard();
    chassis.waitUntilDone();
    chassis.setDrive(8000, 8000);
    pros::delay(650);
    chassis.setDrive(0,0);
    pros::delay(700);
    chassis.setDrive(4000, 4000);
    pros::delay(400);
    chassis.setDrive(0,0);
    pros::delay(500);
    chassis.setDrive(-3000, -3000);
    pros::delay(300);
    chassis.setDrive(5000, 5000);
    pros::delay(500);
    chassis.setDrive(0,0);
    pros::delay(600);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(250);
    chassis.setDrive(-2000, -2000);
    pros::delay(200);
    chassis.setDrive(0,0);
    chassis.turnToHeading(0, 500, {.minSpeed = 5, .pidSelector = 1});
    pros::delay(500);
    chassis.resetPositionFrontAlways();
    chassis.resetPositionRightAlways();
    pros::delay(100);
    chassis.turnToPoint(9, 17, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    chassis.moveToPoint(9, 17, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.swingToHeading(45, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 50, .earlyExitRange = 3});
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    /*chassis.turnToPoint(-24, -24, 2000, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(-24, -24, 2000, {.minSpeed = 25, .earlyExitRange = 3});
    intake.moveBottomIntake(600);
    intake.moveMiddleIntake(0);
    intake.moveTopIntake(0);
    chassis.turnToPoint(-11, -10.75, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-11, -10.75, 4000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    matchload.matchloadV(1);
    pros::delay(100);
    */
   /*
    intake.moveTopIntake(-600);
    intake.moveBottomIntake(-600);
    intake.moveMiddleIntake(-600);
    //chassis.turnToPoint(48, -48, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(400);
    intake.intakeOutSkills();
    pros::delay(1000);
    intake.intakeOutSkillsSlow();
    pros::delay(1000);
    //chassis.setDrive(1500, 1500);
    //pros::delay(500);
    //chassis.setDrive(0,0);
    //chassis.resetPositionLeftAlways();
    //chassis.resetPositionFrontAlways();
    //pros::delay(2000);
    //chassis.resetPositionFrontSkills();
    //chassis.resetPositionRightSkills();
    //chassis.moveToPoint(0, 48, 5000);
    //chassis.turnToHeading(45, 2000);
    //chassis.waitUntilDone();
    //pros::screen::print(pros::E_TEXT_MEDIUM, 5, "settled");
    //chassis.moveToPoint(0, 48, 5000);
    //pros::delay(2000);
    //while(true)
    //{
    //    chassis.resetPositionRight();
    //pros::delay(20);
    //}
    //chassis.turnToPoint(72, 0, 5000);
    /*chassis.moveToPoint(0, 48, 5000);
    chassis.turnToPoint(48, 48, 5000);
    chassis.moveToPoint(48, 48, 5000);
    chassis.turnToPoint(48, 0, 3000);
    chassis.moveToPoint(48, 0, 5000);
    chassis.turnToPoint(0, 0, 3000);
    chassis.moveToPoint(0, 0, 5000);
    chassis.turnToHeading(0, 3000);
    */
}
void leftFourLongFourMiddle() {
    chassis.setPose(-16.875, -4, 270);
    chassis.moveToPoint(-46.1, -4, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.5, -12.25, 1500, {.minSpeed = 20, .earlyExitRange = 1.5});
    intake.hoard();
    chassis.moveToPoint(-47.5, -12.25, 1120, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
    pros::delay(1120);
    //matchload #1
    chassis.moveToPoint(-47.75, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    chassis.waitUntil(25.25);
    //pros::delay(900);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1200);
    matchload.matchloadV(0);
    intake.stopIntake();
    chassis.turnToPoint(-23.5, 24.1, 2000, {.minSpeed = 15, .earlyExitRange = 3});
    intake.hoard();
    chassis.moveToPoint(-23.5, 24.1, 2000, {.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 1});
    intake.intakePneumaticV(0);
    chassis.waitUntil(6);
    matchload.matchloadV(1);
    chassis.turnToPoint(-8.5, 37.75, 2000, {.forwards = false, .pidSelector = 2});
    chassis.moveToPoint(-8.5, 37.75, 2000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    matchload.matchloadV(0);
    intake.moveMiddleIntake(-25);
    chassis.waitUntil(18.75);
    intake.intakeOutAuton();
    wing.wingV(1);
    pros::delay(1600);
    intake.stopIntake();
    chassis.moveToPoint(-35.75, 13, 1500);
    chassis.turnToPoint(-37, 32, 2000, {.forwards = false, .shortTurn = true});
    chassis.waitUntilDone();
    wing.wingV(0);
    pros::delay(50);
    chassis.moveToPoint(-37, 32, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 1});
    chassis.turnToHeading(225, 2000, {.minSpeed = 15});
}

void leftFourLongFourMiddleWing() {
    chassis.setPose(-16.875, 20, 270);
    chassis.moveToPoint(-47.2, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.8, 11.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(-47.8, 11.75, 800, {.minSpeed = 50, .clampDistance = false});
    pros::delay(800);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(-48, 43.95, 1900, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(22.5);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(900);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    intake.stopIntake();
    //grab three stack
    chassis.turnToPoint(-23.5, 48.25, 850, {.maxSpeed = 85});
    chassis.moveToPoint(-23.5, 48.25, 2000, {.minSpeed = 35, .earlyExitRange = 3, .pidSelector = 1});
    intake.intakePneumaticV(0);
    intake.hoard();
    chassis.waitUntil(3.25);
    matchload.matchloadV(1);
    //score middle goal
    chassis.turnToPoint(-11, 60.75, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 2});
    chassis.moveToPoint(-11, 60.75, 2000, {.forwards = false, .minSpeed = 55, .clampDistance = false});
    matchload.matchloadV(0);
    //intake.moveBottomIntake(-50);
    intake.moveMiddleIntake(-250);
    intake.moveTopIntake(-350);
    pros::delay(250);
    intake.stopIntake();
    pros::delay(425);
    intake.middleGoalSplit();
    pros::delay(1200);
    //wing long goal
    chassis.moveToPoint(-33.25, 34, 1500, {.minSpeed = 40, .earlyExitRange = 3});
    chassis.turnToPoint(-34.75, 56, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(-36.5, 56, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2});
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
}

void leftSixLongSixThreeMiddle() {
    chassis.setPose(-15.5, 23, 347.6);
    wing.wingV(1);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(-42, 63, 2000, {.minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1});
    pros::delay(100);
    matchload.matchloadV(0);
    pros::delay(475);
    matchload.matchloadV(1);
    chassis.swingToHeading(262, DriveSide::LEFT, 800, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 10});
    //chassis.swingToPoint(42, 53, DriveSide::RIGHT, 1500, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 2});
    //chassis.turnToPoint(43, 53, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(-39, 53, 1900, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 75, .earlyExitRange = 5});
    //chassis.waitUntil(11);
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    intake.intakePneumaticV(1);
    intake.longGoal();
    matchload.matchloadV(0);
    wing.wingV(0);
    pros::delay(850);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-47.25, 10, 400, {.minSpeed = 25, .earlyExitRange = 4, .shortTurn = true});
    pros::delay(400);
    intake.intakePneumaticV(0);
    //matchload #2
    chassis.moveToPoint(-47.25, 10, 1350, {.minSpeed = 45, .clampDistance = false});
    pros::delay(1350);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.moveToPoint(-47.25, 24, 2000, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2});
    //chassis.turnToPoint(-12.5, 60.25, 800, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    //middle goal
    chassis.moveToPoint(-12.5, 60.25, 1500, {.forwards = false, .minSpeed = 35, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    intake.moveBottomIntake(0);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-450);
    pros::delay(250);
    intake.stopIntake();
    pros::delay(700);
    //intake.intakeOutAutonSlow();
    intake.intakeOutAuton();
    intake.intakePneumaticV(1);
}


void leftFourLong() {
    chassis.setPose(-15.5, 23, 347.6);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    chassis.turnToPoint(-47, 36, 2000, {.minSpeed = 10});
    chassis.moveToPoint(-47, 36, 2000, {.minSpeed = 50, .earlyExitRange = 3, .clampDistance = false});
    chassis.turnToPoint(-48, 44, 800, {.forwards = false, .minSpeed = 25, .earlyExitRange = 1, .shortTurn = true});
    //score long goal
    chassis.moveToPoint(-48, 44, 2000, {.forwards = false, .minSpeed = 70, .clampDistance = false});
    chassis.waitUntil(6.5);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1000);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    intake.stopIntake();
    //wing goal
    chassis.moveToPoint(-37, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-38, 57, 1200, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
}



void leftSixLong() {
    chassis.setPose(-15.5, 23, 347.6);
    wing.wingV(1);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(-42, 63, 2000, {.minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1});
    pros::delay(100);
    matchload.matchloadV(0);
    pros::delay(475);
    matchload.matchloadV(1);
    chassis.swingToHeading(262, DriveSide::LEFT, 800, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 10});
    //chassis.swingToPoint(42, 53, DriveSide::RIGHT, 1500, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 2});
    //chassis.turnToPoint(43, 53, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(-39, 53, 1900, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 75, .earlyExitRange = 5});
    //chassis.waitUntil(11);
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    intake.intakePneumaticV(1);
    intake.longGoal();
    matchload.matchloadV(0);
    wing.wingV(0);
    pros::delay(1250);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(-37.75, 34, 1500, {.minSpeed = 60, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-37.25, 57, 1200, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
}

void leftSevenLong() {
    chassis.setPose(-15.5, 23, 347.6);
    intake.hoard();
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 95, .earlyExitRange = 5});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(-45.25, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5, .pidSelector = 1});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-48.25, 11.75, 650, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(700);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-48.25, 44, 200, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .shortTurn = true});
    pros::delay(200);
    //long goal #1
    chassis.moveToPoint(-48.25, 44, 2000, {.forwards = false, .minSpeed = 80, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
    //chassis.resetPositionLeft();
    //chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
   //chassis.setDrive(-6000, -6000);


    /*chassis.setPose(-15.5, 23, 347.6);
    intake.hoard();
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 127, .earlyExitRange = 9, .clampDistance = false});
    chassis.waitUntil(10);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(-42.25, 23, 2000, {.minSpeed = 127, .earlyExitRange = 7, .pidSelector = 1, .clampDistance = false});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-48.25, 11.75, 650, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(650);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-48.25, 44, 350, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .shortTurn = true});
    pros::delay(350);
    //long goal #1
    chassis.moveToPoint(-48.25, 44, 2000, {.forwards = false, .minSpeed = 127, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1500);
    //chassis.resetPositionLeft();
    //chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
    chassis.setDrive(-12000, -12000);
    */
}

void leftSevenLongWing() {
    chassis.setPose(-15.5, 23, 347.6);
    intake.hoard();
    chassis.moveToPoint(-23, 46.5, 2000, {.minSpeed = 95, .earlyExitRange = 5});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(-45.25, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5, .pidSelector = 1});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-48.25, 11.75, 650, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(700);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-48.25, 44, 200, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .shortTurn = true});
    pros::delay(200);
    //long goal #1
    chassis.moveToPoint(-48.25, 44, 2000, {.forwards = false, .minSpeed = 80, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
    //chassis.resetPositionLeft();
    //chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(-37, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-37.5, 57, 1200, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    //intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 20});
}

void rightFourLongThreeLow() {
    chassis.setPose(16.875, 21.5, 90);
    //chassis.resetPositionFront();
    //chassis.resetPositionRight();
    //pros::delay(10);
    chassis.moveToPoint(47.2, 21.5, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11.75, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11.75, 810, {.minSpeed = 50, .clampDistance = false});
    pros::delay(810);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1900, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(24);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(900);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    //grab 3 stack
    chassis.turnToPoint(23.5, 48, 850, {.maxSpeed = 85});
    chassis.moveToPoint(23.5, 48, 2000, {.minSpeed = 35, .earlyExitRange = 2, .pidSelector = 1});
    intake.intakePneumaticV(0);
    intake.moveBottomIntake(600);
    chassis.waitUntil(3.25);
    matchload.matchloadV(1);
    //score low goal
    chassis.turnToPoint(11.5, 59, 2000, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(11.5, 59, 2000, {.minSpeed = 5});
    matchload.matchloadV(0);
    intake.stopIntake();
    intakeLift.intakeLiftV(1);
    pros::delay(550);
    intake.outtakeAuton();
    pros::delay(1600);
    //wing long goal
    chassis.moveToPoint(32.5, 34, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3});
    intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(33, 56.25, 2000, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(35.25, 56.25, 1500, {.minSpeed = 60, .earlyExitRange = 2});
    chassis.turnToHeading(325, 15000, {.minSpeed = 60});
}

void rightSixLongThreeLow() {
    chassis.setPose(15.5, 23, 12.4);
    wing.wingV(1);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(40.6, 62.75, 2000, {.minSpeed = 5, .earlyExitRange = 2, .pidSelector = 1});
    pros::delay(100);
    matchload.matchloadV(0);
    pros::delay(500);
    matchload.matchloadV(1);
    //chassis.swingToHeading(72, DriveSide::RIGHT, 800, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 10});
    //chassis.swingToPoint(42, 53, DriveSide::RIGHT, 1500, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 2});
    //chassis.turnToPoint(43, 53, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(39, 53, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::RIGHT, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 65, .earlyExitRange = 5});
    //chassis.waitUntil(11);
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    intake.intakePneumaticV(1);
    intake.longGoal();
    wing.wingV(0);
    pros::delay(850);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    chassis.turnToPoint(47.25, 9, 400, {.minSpeed = 25, .earlyExitRange = 4, .shortTurn = true});
    pros::delay(400);
    intake.intakePneumaticV(0);
    //matchload #2
    chassis.moveToPoint(47.25, 9, 1400, {.minSpeed = 40, .clampDistance = false});
    pros::delay(1400);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    chassis.moveToPoint(47.25, 24, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.turnToPoint(11.5, 59, 2000, {.minSpeed = 5, .earlyExitRange = 1, .pidSelector = 2});
    chassis.moveToPoint(11.5, 59, 2000);
    matchload.matchloadV(0);
    intake.stopIntake();
    pros::delay(850);
    intakeLift.intakeLiftV(1);
    intake.outtakeAuton();
    pros::delay(2100);
    //wing long goal
    chassis.moveToPoint(34.75, 34, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 3});
    intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(35, 56, 2000, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(35, 56, 1500, {.minSpeed = 60, .earlyExitRange = 2});
    chassis.turnToHeading(325, 15000, {.minSpeed = 60});
}

void rightFourLong() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    chassis.turnToPoint(42, 44, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 3});
    chassis.moveToPoint(42, 44, 2000, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::RIGHT, 1000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.waitUntil(50);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1000);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(59, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2.5, .pidSelector = 1});
    chassis.moveToPoint(59, 57, 1200, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
    /*chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(47, 36, 2000, {.minSpeed = 10});
    chassis.moveToPoint(47, 36, 2000, {.minSpeed = 50, .earlyExitRange = 3, .clampDistance = false});
    chassis.turnToPoint(48, 44, 800, {.forwards = false, .minSpeed = 25, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 70, .clampDistance = false});
    chassis.waitUntil(6);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1000);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(59, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(58.5, 57, 1200, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
    */
}

void rightSixLong() {
    chassis.setPose(15.5, 23, 12.4);
    wing.wingV(1);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(40.6, 62.75, 2000, {.minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1});
    pros::delay(100);
    matchload.matchloadV(0);
    pros::delay(500);
    matchload.matchloadV(1);
    //chassis.swingToHeading(80, DriveSide::RIGHT, 800, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 10});
    //chassis.swingToPoint(42, 53, DriveSide::RIGHT, 1500, {.forwards = false, .direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 25, .earlyExitRange = 2});
    //chassis.turnToPoint(43, 53, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.moveToPoint(39, 53, 1900, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::RIGHT, 2000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed = 70, .earlyExitRange = 5});
    //chassis.waitUntil(11);
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    intake.intakePneumaticV(1);
    intake.longGoal();
    matchload.matchloadV(0);
    wing.wingV(0);
    pros::delay(1250);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(58.25, 33.5, 1500, {.minSpeed = 45, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(58.75, 57, 1200, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
}

void rightSevenLong() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 95, .earlyExitRange = 5});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5, .pidSelector = 1});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(47.75, 11.75, 900, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(900);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
   //long goal #1
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 80, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
   //chassis.resetPositionLeft();
   //chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(59, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(58.5, 57, 1200, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    //intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 20});

    /*
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 127, .earlyExitRange = 9, .clampDistance = false});
    chassis.waitUntil(10);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(42, 23, 2000, {.minSpeed = 127, .earlyExitRange = 7, .pidSelector = 1, .clampDistance = false});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(47.75, 11.75, 950, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(950);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 127, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1500);
    //chassis.resetPositionLeft();
    //chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
    chassis.setDrive(-12000, -12000);
    //intake.stopIntake();
    //wing long goal
    //chassis.moveToPoint(59, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.moveToPoint(58.5, 57, 1200, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    //intake.intakePneumaticV(1);
    //chassis.turnToHeading(210, 15000, {.minSpeed = 30});
    */
}

void rightSevenLongWing() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 95, .earlyExitRange = 5});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    //chassis.turnToPoint(45, 23, 2000, {.minSpeed = 10});
    //chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(45, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5, .pidSelector = 1});
    //chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(47.75, 11.75, 900, {.minSpeed = 50, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(850);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
   //long goal #1
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 80, .clampDistance = false});
    chassis.waitUntil(14);
    intake.moveTopIntake(-300);
    intake.moveMiddleIntake(-300);
    intake.moveBottomIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    chassis.waitUntilDone();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(59, 34, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(58.5, 57, 1200, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    //intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 20});
}

void rightNineLong() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(42, 63.25, 2000, {.maxSpeed = 100, .pidSelector = 1});
    pros::delay(150);
    matchload.matchloadV(0);
    /*
    chassis.moveToPoint(31, 45, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    chassis.turnToPoint(47.25, 23, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(47.25, 23, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .clampDistance = false});
    chassis.turnToPoint(47.75, 11.75, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.75, 11.75, 2000, {.forwards = false, .minSpeed = 25});
    matchload.matchloadV(1);
    pros::delay(800);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //intake.outtake();
    //pros::delay(150);
    //intake.stopIntake();
    //pros::delay(350);
    //matchload #1
    //score long goal
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.longGoal();
    */

}

void halfSWPRight() {
    chassis.setPose(16.875, 20, 90);
    chassis.moveToPoint(46.8, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11.75, 800, {.minSpeed = 50, .clampDistance = false});
    pros::delay(800);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1800, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(815);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    chassis.turnToPoint(23.5, 47.75, 1000, {.maxSpeed = 60});
    intake.hoard();
    chassis.moveToPoint(23.5, 48, 2000, {.minSpeed = 30, .earlyExitRange = 1.5});
    intake.intakePneumaticV(0);
    intake.moveBottomIntake(600);
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    //score low goal
    chassis.turnToPoint(11.5, 59, 1500, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(11.5, 59, 2000, {.minSpeed = 5});
    matchload.matchloadV(0);
    intake.stopIntake();
    intakeLift.intakeLiftV(1);
    pros::delay(550);
   // intakeLift.intakeLiftV(1);
    intake.outtakeAuton();
    pros::delay(1700);
    chassis.moveToPoint(23.5, 48, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    intakeLift.intakeLiftV(0);
    //intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(600);
    //three ball stack #2
    chassis.turnToPoint(-22.5, 48.4, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-22.5, 48.4, 1800, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    chassis.waitUntil(25.75);
    matchload.matchloadV(1);
    //grab balls under goal
    //chassis.turnToPoint(-43.5, 63.25, 1500, {.minSpeed = 10, .earlyExitRange = 40, .shortTurn = true});
    //chassis.turnToHeading(347.6, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    //chassis.moveToPoint(-43.5, 63.25, 1500, {.minSpeed = 20, .earlyExitRange = 1.5, .pidSelector = 1});
    //matchload.matchloadV(0);
    //chassis.waitUntil(26);
    //matchload.matchloadV(1);
    //score middle goal
    //chassis.turnToPoint(-18, 61, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    //chassis.moveToPoint(-18, 61, 2000, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    chassis.turnToPoint(-10.5, 60.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-10.5, 60.5, 2000, {.forwards = false, .minSpeed = 30});
    //chassis.swingToHeading(225, DriveSide::RIGHT, 1500,{.minSpeed = 40});
    chassis.waitUntil(11);
    //intake.intakeOutAuton();
    intake.intakeOutAuton();
    pros::delay(1200);
    matchload.matchloadV(0);
    chassis.moveToPoint(-18, 53, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.waitUntilDone();
    descore.descoreV(1);
    pros::delay(150);
    chassis.moveToPoint(-13.5, 59.5, 2000, {.forwards = false, .minSpeed = 40});
}

void halfSWPLeft() {
    chassis.setPose(-16.875, 20, 270);
    chassis.moveToPoint(-47.2, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.8, 11.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(-47.8, 11.75, 800, {.minSpeed = 50, .clampDistance = false});
    pros::delay(800);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(-48, 43.95, 1800, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(815);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    intake.stopIntake();
    chassis.turnToPoint(-23.5, 47.75, 1000, {.maxSpeed = 60});
    intake.hoard();
    chassis.moveToPoint(-23.5, 48, 2000, {.minSpeed = 30, .earlyExitRange = 1.5});
    intake.intakePneumaticV(0);
    intake.moveBottomIntake(600);
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    //score low goal
    chassis.turnToPoint(11.5, 59, 1500, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(11.5, 59, 2000, {.minSpeed = 5});
    matchload.matchloadV(0);
    intake.stopIntake();
    intakeLift.intakeLiftV(1);
    pros::delay(550);
   // intakeLift.intakeLiftV(1);
    intake.outtakeAuton();
    pros::delay(1700);
    chassis.moveToPoint(23.5, 48, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    intakeLift.intakeLiftV(0);
    //intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(600);
    //three ball stack #2
    chassis.turnToPoint(-22.5, 48.4, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-22.5, 48.4, 1800, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    chassis.waitUntil(25.75);
    matchload.matchloadV(1);
    //grab balls under goal
    //chassis.turnToPoint(-43.5, 63.25, 1500, {.minSpeed = 10, .earlyExitRange = 40, .shortTurn = true});
    //chassis.turnToHeading(347.6, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    //chassis.moveToPoint(-43.5, 63.25, 1500, {.minSpeed = 20, .earlyExitRange = 1.5, .pidSelector = 1});
    //matchload.matchloadV(0);
    //chassis.waitUntil(26);
    //matchload.matchloadV(1);
    //score middle goal
    //chassis.turnToPoint(-18, 61, 1000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    //chassis.moveToPoint(-18, 61, 2000, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    chassis.turnToPoint(-10.5, 60.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-10.5, 60.5, 2000, {.forwards = false, .minSpeed = 30});
    //chassis.swingToHeading(225, DriveSide::RIGHT, 1500,{.minSpeed = 40});
    chassis.waitUntil(11);
    //intake.intakeOutAuton();
    intake.intakeOutAuton();
    pros::delay(1200);
    matchload.matchloadV(0);
    chassis.moveToPoint(-18, 53, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.waitUntilDone();
    descore.descoreV(1);
    pros::delay(150);
    chassis.moveToPoint(-13.5, 59.5, 2000, {.forwards = false, .minSpeed = 40});
}

void soloWinPoint() {
    /*chassis.setPose(48, 43.95, 180);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    pros::delay(100);
    chassis.turnToPoint(23.5, 47.75, 1100, {.minSpeed = 60});
    //three ball stack #1
    chassis.moveToPoint(23.5, 47.75, 2000, {.minSpeed = 60, .earlyExitRange = 3, .clampDistance = false});
    */
    chassis.setPose(16.875, 20, 90);
    chassis.moveToPoint(47.2, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11, 825, {.minSpeed = 50, .clampDistance = false});
    pros::delay(825);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1800, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(815);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    chassis.turnToPoint(23.5, 47.75, 900, {.maxSpeed = 75});
    //three ball stack #1
    //chassis.moveToPoint(23.5, 47.75, 2000, {.minSpeed = 60, .earlyExitRange = 3, .clampDistance = false});
    intake.hoard();
    //chassis.waitUntil(3.5);
    //matchload.matchloadV(1);
    //pros::delay(300);
    //matchload.matchloadV(0);
    //three ball stack #2
    chassis.moveToPoint(-22.5, 47.75, 1800, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    intake.intakePneumaticV(0);
    chassis.waitUntil(47);
    matchload.matchloadV(1);
    chassis.turnToPoint(-46.5, 30, 1100, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-46.5, 30, 2000, {.minSpeed = 15, .earlyExitRange = 2});
    chassis.turnToPoint(-47.5, 44.5, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});
    //long goal #2
    chassis.moveToPoint(-47.5, 44.5, 1300, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(6.5);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(800);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-47.5, 9.5, 500, {.minSpeed = 15, .earlyExitRange = 3, .shortTurn = true});
    pros::delay(500);
    //matchload #2
    chassis.moveToPoint(-47.5, 9.5, 1425, {.minSpeed = 25, .clampDistance = false});
    pros::delay(500);
    intake.intakePneumaticV(0);
    pros::delay(925);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.moveToPoint(-47.5, 24, 2000, {.forwards = false, .minSpeed = 40, .earlyExitRange = 2});
    //chassis.turnToPoint(-12.5, 60.25, 800, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    //middle goal
    chassis.moveToPoint(-12.25, 59.5, 1700, {.forwards = false, .minSpeed = 35, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    intake.moveBottomIntake(0);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-450);
    pros::delay(250);
    intake.stopIntake();
    pros::delay(900);
    //intake.intakeOutAutonSlow();
    intake.intakeOutAutonSWP();
    intake.intakePneumaticV(1);
}

void skills() {
    //park zone balls
    chassis.setPose(0, -50, 180);
    intake.hoard();
    intakeLift.intakeLiftV(0);
    chassis.setDrive(2000, 2000);
    pros::delay(250);
    chassis.setDrive(0,0);
    pros::delay(500);
    chassis.setDrive(5500, 5500);
    pros::delay(350);
    //chassis.setDrive(0,0);
    //chassis.wiggle(2, 5000);
    chassis.setDrive(0,0);
    pros::delay(800);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(200);
    chassis.setDrive(-2000, -2000);
    pros::delay(150);
    chassis.setDrive(0,0);
    chassis.turnToHeading(180, 500, {.minSpeed = 7, .pidSelector = 1});
    chassis.waitUntilDone();
    chassis.resetPositionFrontAlways();
    chassis.resetPositionRightAlways();
    pros::delay(10);
    chassis.turnToPoint(-8.25, -16.75, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    chassis.moveToPoint(-8.25, -16.75, 2000, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    intake.stopIntake();
    //middle goal
    chassis.swingToHeading(225, DriveSide::LEFT, 1300, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 70, .earlyExitRange = 3});
    chassis.moveToPoint(-17.7, -17.7, 1500, {.maxSpeed = 100});
    intake.moveBottomIntake(600);
    chassis.moveToPoint(-10, -11, 3000, {.forwards = false, .minSpeed = 30, .clampDistance = false});
    pros::delay(300);
    matchload.matchloadV(1);
    intake.intakePneumaticV(1);
    pros::delay(300);
    intake.outtakeForSkillsMiddleGoal();
    //intake.moveBottomIntake(-600);
    //intake.moveMiddleIntake(-600);
    //intake.moveTopIntake(-600);
    pros::delay(500);
    intake.intakeOutSkills();
    pros::delay(1800);
    intake.intakeOutSkillsSlow();
    matchload.matchloadV(0);
    pros::delay(950);
    intake.intakeOutSkillsSuperSlow();
    pros::delay(950);
    intake.stopIntake();
    //get seventh low goal ball
    //chassis.turnToPoint(15.25, -29, 1500, {.minSpeed = 15, .earlyExitRange = 2, .pidSelector = 2});
    //chassis.moveToPoint(15.25, -29, 2000, {.minSpeed = 30, .earlyExitRange = 2});
    //chassis.turnToPoint(12.5, -10.5, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    //chassis.moveToPoint(12.5, -10.5, 2000, {.minSpeed = 10});
    //chassis.turnToHeading(315, 1500, {.minSpeed = 15});
    //score low goal
    //intakeLift.intakeLiftV(1);
    //intake.outtakeAutonSkills();
    //pros::delay(1250);
    //intake.outtakeAutonSkillsTop();
    //pros::delay(2900);
    //chassis.setDrive(1500, 1500);
    //pros::delay(600);
    //chassis.setDrive(0,0);
    //intake.stopIntake();
    //get three balls
    //chassis.moveToPoint(24, -24, 1500, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3});
    //chassis.turnToPoint(-22.5, -26, 1500, {.minSpeed = 15, .earlyExitRange = 4, .pidSelector = 1});
    //intake.hoard();
    //intake.intakePneumaticV(1);
    //intakeLift.intakeLiftV(0);
    //chassis.moveToPoint(-22.5, -26, 1700, {.minSpeed = 50, .earlyExitRange = 4, .clampDistance = false});
    //pros::delay(500);
    //chassis.turnToPoint(-47.85, -47, 1500, {.minSpeed = 10, .earlyExitRange = 3, .shortTurn = true});
    chassis.moveToPoint(-44.75, -47, 2000, {.minSpeed = 15, .earlyExitRange = 2});
    pros::delay(150);
    intake.hoard();
    pros::delay(550);
    matchload.matchloadV(1);
    intake.intakePneumaticV(0);
    //matchload #1
    chassis.turnToPoint(-46.25, -61.25, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-46.25, -61.25, 1900, {.minSpeed = 45, .clampDistance = false});
    intake.hoard();
    pros::delay(1900);
    chassis.resetPositionRightSkills();
    chassis.resetPositionFrontSkills();
    //go to long goal #1
    chassis.moveToPoint(-58.75, -30, 1900, {.forwards = false, .minSpeed = 45, .earlyExitRange = 5, .pidSelector = 1, .clampDistance = false});
    chassis.turnToPoint(-59, 15, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .pidSelector = 1});
    //intake.moveBottomIntake(-200);
    //pros::delay(150);
    //intake.hoard();
    chassis.moveToPoint(-59, 15, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    //chassis.moveToPoint(-56.5, 15, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1});
    //chassis.moveToPoint(-52, 17, 1900, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    matchload.matchloadV(0);
    //score long goal
    chassis.swingToHeading(0, DriveSide::LEFT, 1700, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 45, .earlyExitRange = 5});
    chassis.waitUntilDone();
    chassis.setDrive(-9000, -9000);
    matchload.matchloadV(1);
    intake.moveBottomIntake(-100);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(-48, 62, 700, {.minSpeed = 15, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(700);
    intake.hoard();
    //matchload #2
    chassis.moveToPoint(-48, 62, 2200, {.minSpeed = 25, .clampDistance = false});
    pros::delay(1000);
    intake.intakePneumaticV(0);
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(-48, 28, 500, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(500);
    //long goal #2
    chassis.moveToPoint(-48, 28, 2000, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(15);
    intake.moveBottomIntake(-300);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-300);
    pros::delay(300);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1700);
    matchload.matchloadV(0);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    intake.stopIntake();
    chassis.moveToPoint(-48, 41.75, 1500, {.minSpeed = 40, .earlyExitRange = 2});
    chassis.turnToPoint(0, 42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    intake.intakePneumaticV(0);
    chassis.moveToPoint(0, 42, 1500, {.minSpeed = 7});
    chassis.turnToPoint(0, 72, 1000, {.minSpeed = 5, .earlyExitRange = 1});
    intake.hoard();
    chassis.waitUntilDone();
    //park zone #2
    chassis.setDrive(6500, 6500);
    pros::delay(850);
    chassis.setDrive(0,0);
    pros::delay(700);
    chassis.setDrive(5000, 5000);
    pros::delay(400);
    chassis.setDrive(0,0);
    pros::delay(800);
    chassis.setDrive(3000, 3000);
    pros::delay(450);
    chassis.setDrive(0,0);
    pros::delay(500);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(250);
    chassis.setDrive(-2000, -2000);
    pros::delay(150);
    chassis.setDrive(0,0);
    chassis.turnToHeading(0, 500, {.minSpeed = 7, .pidSelector = 1});
    chassis.waitUntilDone();
    chassis.resetPositionFrontAlways();
    chassis.resetPositionLeftAlways();
    pros::delay(10);
    chassis.turnToPoint(-24, 24, 1500, {.forwards = false, .minSpeed = 15, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-24, 24, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.turnToPoint(-11.65, 11.4, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-11.65, 11.4, 2000, {.minSpeed = 10});
    intakeLift.intakeLiftV(1);
    //chassis.turnToHeading(315, 1500, {.minSpeed = 15});
    //score low goal
    //intakeLift.intakeLiftV(1);
    pros::delay(500);
    intake.outtakeAutonSkills();
    pros::delay(1000);
    intake.outtakeAutonSkillsTop();
    pros::delay(2200);
    //chassis.setDrive(1500, 1500);
    //pros::delay(600);
    //chassis.setDrive(0,0);
    //intake.stopIntake();
    //get three balls
    chassis.moveToPoint(-24, 24, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    intakeLift.intakeLiftV(0);
    chassis.turnToPoint(22.5, 26, 1500, {.minSpeed = 10, .earlyExitRange = 2, .pidSelector = 1});
    intake.hoard();
    intake.intakePneumaticV(1);
    chassis.moveToPoint(22.5, 26, 1700, {.minSpeed = 30, .earlyExitRange = 3});
    chassis.turnToPoint(46, 47, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(46, 47, 2000, {.minSpeed = 15 , .earlyExitRange = 2});
    pros::delay(100);
    intake.intakePneumaticV(0);
    pros::delay(600);
    matchload.matchloadV(1);
    //matchload #1
    chassis.turnToPoint(47, 61, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(47, 61, 1900, {.minSpeed = 45, .pidSelector = 1, .clampDistance = false});
    intake.hoard();
    pros::delay(1900);
    chassis.resetPositionRightSkills();
    chassis.resetPositionFrontSkills();
    //go to long goal #1
    chassis.moveToPoint(58.75, 30, 1900, {.forwards = false, .minSpeed = 45, .earlyExitRange = 5, .pidSelector = 1, .clampDistance = false});
    //chassis.moveToPoint(57.5, -13, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1});
    chassis.turnToPoint(59, -15.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(59, -15.5, 1900, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    //chassis.moveToPoint(52, -17, 1900, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    matchload.matchloadV(0);
    //score long goal
    chassis.swingToHeading(180, DriveSide::LEFT, 1700, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 50, .earlyExitRange = 5});
    chassis.waitUntilDone();
    chassis.setDrive(-9000, -9000);
    matchload.matchloadV(1);
    intake.moveBottomIntake(-100);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-300);
    pros::delay(200);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(48, -62, 700, {.minSpeed = 15, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(700);
    intake.hoard();
    //matchload #2
    chassis.moveToPoint(48, -62, 2200, {.minSpeed = 30, .clampDistance = false});
    pros::delay(1000);
    intake.intakePneumaticV(0);
    pros::delay(1200);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(48, -28, 500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(500);
    //long goal #2
    chassis.moveToPoint(48, -28, 2500, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(15);
    intake.moveBottomIntake(-300);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-300);
    pros::delay(300);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1700);
    matchload.matchloadV(0);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.moveToPoint(24, -63.5, 1400, {.minSpeed = 25, .earlyExitRange = 4, .pidSelector = 1});
    pros::delay(500);
    intake.intakePneumaticV(0);
    chassis.swingToHeading(260, DriveSide::RIGHT, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    chassis.waitUntilDone();
    //park zone #2
    chassis.setDrive(9000, 9000);
    pros::delay(850);
    chassis.setDrive(0,0);

    //pros::delay(500);
    /*chassis.turnToPoint(9, 16.25, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    chassis.moveToPoint(9, 16.25, 2000, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    intake.stopIntake();
    //middle goal
    chassis.swingToHeading(45, DriveSide::LEFT, 1300, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 80, .earlyExitRange = 3});
    chassis.waitUntilDone();
    chassis.setDrive(-5000, -5000);
    matchload.matchloadV(1);
    intake.intakePneumaticV(1);
    pros::delay(300);
    intake.moveBottomIntake(-400);
    intake.moveMiddleIntake(-400);
    intake.moveTopIntake(-500);
    pros::delay(400);
    intake.intakeOutSkills();
    pros::delay(2900);
    intake.intakeOutSkillsSlow();
    matchload.matchloadV(0);
    pros::delay(1500);
    intake.stopIntake();
    intake.intakePneumaticV(0);
    /*chassis.moveToPoint(-47.85, -47, 2000, {.minSpeed = 25, .earlyExitRange = 5, .clampDistance = false});
    intake.hoard();
    pros::delay(700);
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.75, -60.25, 900, {.minSpeed = 20, .earlyExitRange = 10, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-47.75, -60.25, 1900, {.minSpeed = 40, .clampDistance = false});
    pros::delay(1900);
    chassis.resetPositionRightSkills();
    chassis.resetPositionFrontSkills();

    /*intakeLift.intakeLiftV(0);
    intake.intakePneumaticV(0);
    chassis.moveToPoint(-48, 42, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.turnToPoint(0, 42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(0, 42, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    chassis.turnToPoint(0, 72, 1000, {.minSpeed = 5 , .earlyExitRange = 1});
    intake.hoard();
    chassis.waitUntilDone();
    chassis.setDrive(8000, 8000);
    pros::delay(650);
    chassis.setDrive(0,0);
    pros::delay(700);
    chassis.setDrive(4000, 4000);
    pros::delay(400);
    chassis.setDrive(0,0);
    pros::delay(500);
    chassis.setDrive(-3000, -3000);
    pros::delay(300);
    chassis.setDrive(5000, 5000);
    pros::delay(500);
    chassis.setDrive(0,0);
    pros::delay(600);
    //drive back and reset odometry
    chassis.setDrive(-8000, -8000);
    pros::delay(600);
    chassis.setDrive(-4000, -4000);
    pros::delay(250);
    chassis.setDrive(-2000, -2000);
    pros::delay(200);
    chassis.setDrive(0,0);
    chassis.turnToHeading(0, 500, {.minSpeed = 5, .pidSelector = 1});
    pros::delay(500);
    chassis.resetPositionFrontAlways();
    chassis.resetPositionRightAlways();
    pros::delay(100);
    chassis.turnToPoint(9, 17, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3, .pidSelector = 1});
    chassis.moveToPoint(9, 17, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.swingToHeading(45, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 50, .earlyExitRange = 3});
    chassis.waitUntilDone();
    chassis.setDrive(-4000, -4000);
    /*chassis.turnToPoint(-24, -24, 2000, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(-24, -24, 2000, {.minSpeed = 25, .earlyExitRange = 3});
    intake.moveBottomIntake(600);
    intake.moveMiddleIntake(0);
    intake.moveTopIntake(0);
    chassis.turnToPoint(-11, -10.75, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-11, -10.75, 4000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    matchload.matchloadV(1);
    pros::delay(100);
    */
   /*
    intake.moveTopIntake(-600);
    intake.moveBottomIntake(-600);
    intake.moveMiddleIntake(-600);
    //chassis.turnToPoint(48, -48, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    pros::delay(400);
    intake.intakeOutSkills();
    pros::delay(1000);
    intake.intakeOutSkillsSlow();
    pros::delay(1000);
    //chassis.setDrive(1500, 1500);
    //pros::delay(500);
    //chassis.setDrive(0,0);
    /*chassis.moveToPoint(47.85, 47, 2000, {.minSpeed = 25, .earlyExitRange = 5, .clampDistance = false});
    pros::delay(700);
    matchload.matchloadV(1);
    chassis.turnToPoint(47.75, 60.25, 900, {.minSpeed = 20, .earlyExitRange = 10, .shortTurn = true});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.75, 60.25, 1900, {.minSpeed = 40, .clampDistance = false});
    pros::delay(1900);
    chassis.resetPositionRightSkills();
    chassis.resetPositionFrontSkills();
    chassis.moveToPoint(58, 30, 1900, {.forwards = false, .minSpeed = 30, .earlyExitRange = 3, .pidSelector = 1, .clampDistance = false});
    chassis.moveToPoint(54.5, -16, 1900, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    //chassis.moveToPoint(-58, 24, 1900, {.forwards = false, .minSpeed = 30, .earlyExitRange = 2, .pidSelector = 1, .clampDistance = false});
    //chassis.moveToPoint(-47.5, 42, 1900, {.forwards = false, .minSpeed = 10, .pidSelector = 1});
    matchload.matchloadV(0);
    //chassis.turnToPoint(-48, 28, 800, {.forwards = false, .pidSelector = 2});
    //score long goal
    //chassis.moveToPoint(-48, 28, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.swingToHeading(180, DriveSide::LEFT, 2000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 75, .earlyExitRange = 5});
    //chassis.waitUntil(11);
    chassis.waitUntilDone();
    matchload.matchloadV(1);
    intake.moveBottomIntake(-300);
    intake.moveMiddleIntake(-600);
    pros::delay(150);
    intake.moveTopIntake(-600);
    pros::delay(200);
    chassis.setDrive(-4000, -4000);
    pros::delay(300);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(800);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(47.75, 60.25, 700, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    pros::delay(700);
    intake.intakePneumaticV(0);
    //chassis.moveToPoint(-47.75, 48, 2000, {.minSpeed = 20, .earlyExitRange = 1});
    //chassis.turnToPoint(-47.75, 60.25, 800, {.minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    intake.hoard();
    //matchload #2
    chassis.moveToPoint(47.75, 60.25, 1950, {.minSpeed = 30, .clampDistance = false});
    pros::delay(1900);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    chassis.turnToPoint(48, 28, 700, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    pros::delay(700);
    //chassis.moveToPoint(-48, 40, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 1});
    //chassis.turnToPoint(-48, 28, 800, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(48, 28, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.waitUntil(15);
    intake.moveBottomIntake(-300);
    intake.moveMiddleIntake(-600);
    intake.moveTopIntake(-600);
    pros::delay(300);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1700);
    matchload.matchloadV(0);
    chassis.resetPositionLeftSkills();
    chassis.resetPositionFrontSkills();
    intake.intakePneumaticV(0);
    chassis.moveToPoint(48, 42, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.turnToPoint(1, 42, 1500, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(1, 42, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    chassis.turnToPoint(1, 72, 1000, {.minSpeed = 10 , .earlyExitRange = 2});
    chassis.waitUntilDone();
    chassis.setDrive(8000, 8000);
    pros::delay(1400);
 
    //chassis.moveToPoint(0, 48, 1500, {.minSpeed = 25, .earlyExitRange = 2});


    //intake.stopIntake();
    */

}