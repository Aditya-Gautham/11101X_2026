#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/subsystems/intake.hpp"
#include "lemlib/timer.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
//

void odomTest() {
    chassis.setPose(0,0,0);
    //chassis.turnToHeading(90, 5000);
    chassis.turnToPoint(48, 0, 2000, {.minSpeed = 5, .earlyExitRange = 1});
    chassis.waitUntilDone();
    pros::screen::print(pros::E_TEXT_MEDIUM, 5, "settled");

    //chassis.turnToPoint(72, 0, 5000);
    /*chassis.turnToPoint(48, 48, 5000);
    chassis.moveToPoint(48, 48, 5000);
    chassis.turnToPoint(48, 0, 3000);
    chassis.moveToPoint(48, 0, 5000);
    chassis.turnToPoint(0, 0, 3000);
    chassis.moveToPoint(0, 0, 5000);
    chassis.turnToHeading(0, 3000);
    */
    
}
void leftFourLongFourMiddle() {
    /*chassis.turnToPoint(-13, 36, 1500, {.forwards = false, .minSpeed = 15});
    chassis.moveToPoint(-13, 36, 2000, {.forwards = false, .minSpeed = 15});
    chassis.waitUntil(35);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    pros::delay(1000);
    chassis.moveToPoint(-10, 28, 2000);
    intake.intakePneumaticV(0);

    /*chassis.setPose(-17.25, 0.5, -12);
    intake.intakeBlock();
    chassis.moveToPoint(-23.25, 23, 2000);
    chassis.waitUntil(10);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.moveToPoint(-42, 40, 2000, {.maxSpeed = 100, .pidSelector = 1});
    pros::delay(150);
    matchload.matchloadV(0);
    //grab 4th ball
    //chassis.moveToPoint(-40, 30, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 3, .pidSelector = 1});
    //chassis.swingToPoint(-48, 0, DriveSide::LEFT, 1000, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 30});

    chassis.moveToPoint(-26, 23, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .clampDistance = false});
    chassis.turnToPoint(-50, 4, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-50, 4, 2000, {.forwards = false, .minSpeed = 5});
    chassis.turnToPoint(-50.25, 19.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-50.25, 19.5, 2000, {.forwards = false, .minSpeed = 20});
    chassis.waitUntil(5);
    intake.scoreHighGoal();
    pros::delay(1300);
    chassis.turnToPoint(-49.75, -13, 600, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-49.75, -13, 1300, {.maxSpeed = 80});
    matchload.matchloadV(1);
    intake.intakeBlock();
    pros::delay(1300);
    chassis.moveToPoint(-49.75, 0, 2000, {.forwards = false, .minSpeed = 10});
    /*chassis.turnToPoint(-13, 36, 1500, {.forwards = false, .minSpeed = 15});
    chassis.moveToPoint(-13, 36, 2000, {.forwards = false, .minSpeed = 15});
    chassis.waitUntil(35);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    pros::delay(1000);
    chassis.moveToPoint(-10, 28, 2000);
    intake.intakePneumaticV(0);*/

    
    //matchload #1
    //score long goal
    chassis.setPose(-18.5, -3.6, 270);
    chassis.moveToPoint(-48, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.9, -13, 1500, {.minSpeed = 8, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(-48.9, -13, 1030, {.maxSpeed = 100, .minSpeed = 30, .clampDistance = false});
    pros::delay(1030);
    //matchload #1
    chassis.moveToPoint(-49.25, 19.75, 2000, {.forwards = false});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1200);
    chassis.moveToPoint(-49.25, 11.5, 1500, {.minSpeed = 15, .earlyExitRange = 1, .clampDistance = false});
    intake.intakeBlock();
    chassis.turnToPoint(-24.2, 22.5, 1500, {.minSpeed = 5, .earlyExitRange = 1, .pidSelector = 2});
    chassis.moveToPoint(-24.2, 22.5, 2000,{.maxSpeed = 50, .minSpeed = 5, .earlyExitRange = 1});
    //chassis.waitUntil(13);
    //matchload.matchloadV(1);
    intake.moveTopIntake(10);
    //chassis.turnToPoint(-41.25, 37.1, 2000, {.minSpeed = 15});
    //chassis.moveToPoint(-41.25, 37.1, 2000, {.minSpeed = 15});
    //chassis.moveToPoint(-24, 24, 2000, {.forwards = false, .minSpeed = 15});
    chassis.turnToPoint(-11.4, 35.35, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 3});
    //intake.outtakeBlock();
    //pros::delay(150);
    //intake.stopIntake();
    chassis.moveToPoint(-11.4, 35.35, 2000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    //chassis.moveToPose(-11.75, 35.6, 225, 2000);
    chassis.waitUntil(13.25);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    matchload.matchloadV(0);
    pros::delay(3000);
    intake.intakePneumaticV(0);
    intake.stopIntake();
    chassis.moveToPoint(-19, 28, 2000, {.minSpeed = 15});
    chassis.waitUntilDone();
    descore.descoreV(1);
    chassis.moveToPoint(-11.4, 35.1, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    /*chassis.turnToPoint(-37.4, 20, 1000, {.minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
    wing.wingV(1);
    chassis.moveToPoint(-37.4, 20, 1500);
    chassis.turnToPoint(-37.4, 31.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntilDone();
    wing.wingV(0);
    pros::delay(75);
    chassis.moveToPoint(-37.4, 31.5, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 60});
    chassis.turnToHeading(210, 15000, {.minSpeed = 40});
    */

}

void leftFourLongFourMiddleWing() {
    chassis.setPose(-18.1, -3.6, 270);
    chassis.moveToPoint(-47.7, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.85, -12.5, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(-48.85, -12.5, 880, {.maxSpeed = 80, .minSpeed = 40});
    pros::delay(880);
    //matchload #1
    chassis.moveToPoint(-49.4, 19.75, 2000, {.forwards = false, .minSpeed = 35});
    chassis.waitUntil(24.75);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1100);
    chassis.moveToPoint(-49.4, 11.5, 1500, {.minSpeed = 35, .earlyExitRange = 2});
    //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
    chassis.turnToPoint(-23, 24, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-28, 17.75, 2000,{.minSpeed = 25, .earlyExitRange = 2});
    chassis.moveToPoint(-23, 24, 2000,{.maxSpeed = 25, .minSpeed = 5, .earlyExitRange = 2});
    intake.intakeBlock();
    intake.moveTopIntake(20);
    chassis.turnToPoint(-40.25, 38, 2000, {.minSpeed = 25, .earlyExitRange = 2});
    chassis.moveToPoint(-40.25, 38, 2000, {.minSpeed = 15});
    chassis.moveToPoint(-26, 22, 2000, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    chassis.turnToPoint(-12.25, 34.2, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    intake.outtakeBlock();
    pros::delay(100);
    intake.stopIntake();
    chassis.moveToPoint(-12.25, 34.2, 2000, {.forwards = false, .minSpeed = 35});
    chassis.waitUntil(12.6);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    pros::delay(1150);
    chassis.turnToPoint(-37.3, 20, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    wing.wingV(1);
    chassis.moveToPoint(-37.3, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    intake.stopIntake();
    chassis.turnToPoint(-37.6, 31.5, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    chassis.waitUntilDone();
    wing.wingV(0);
    pros::delay(75);
    chassis.moveToPoint(-37.6, 31.5, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 60});
    chassis.turnToHeading(205, 15000, {.minSpeed = 40});
}

void leftFourLong() {
    chassis.setPose(-18.1, -3.6, 270);
    chassis.moveToPoint(-47.4, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.3, -12.5, 1500, {.minSpeed = 25, .earlyExitRange = 1});
    intake.intakeBlock();
    chassis.moveToPoint(-48.3, -12.5, 925, {.maxSpeed = 75, .minSpeed = 40});
    pros::delay(925);
    //matchload #1
    chassis.moveToPoint(-48.5, 19.75, 2000, {.forwards = false, .minSpeed = 35});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(900);
    //chassis.moveToPoint(-38.5, 16, 1500, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    chassis.swingToPoint(-24, 8, DriveSide::LEFT, 2000, {.minSpeed = 45, .earlyExitRange = 5});
    chassis.turnToPoint(-37.5, 32, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    chassis.moveToPoint(-37.5, 32, 1500, {.forwards = false, .minSpeed = 60});
    chassis.turnToHeading(195, 2000, {.minSpeed = 40});
}

void leftSevenLong() {
    chassis.setPose(-17, 0, -12);
    intake.intakeBlock();
    chassis.moveToPoint(-23, 22.5, 2000);
    chassis.waitUntil(10.25);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(-49.4, 0.5, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(-49.4, 0.5, 2000, {.minSpeed = 5});
    chassis.turnToPoint(-50, -12.5, 600, {.shortTurn = true});
    chassis.moveToPoint(-50, -12.5, 850, {.maxSpeed = 80});
    intake.intakeBlock();
    pros::delay(850);
    intake.stopIntake();
    chassis.moveToPoint(-50.25, 21.5, 2000, {.forwards = false, .minSpeed = 20});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1350);
    chassis.moveToPoint(-39.5, 12, 1500, {.minSpeed = 10, .earlyExitRange = 1, .pidSelector = 1});
    chassis.turnToPoint(-40.5, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 1});
    chassis.moveToPoint(-40.5, 34, 1500, {.forwards = false, .maxSpeed = 100, .minSpeed = 60, .earlyExitRange = 1});
    chassis.turnToHeading(210, 15000, {.minSpeed = 40});
    /*
    chassis.setPose(9.5, 1.7, 0);
    intake.intakeBlock();
    chassis.turnToPoint(3, 24.5, 1500, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(3, 24.5, 2500);
    chassis.waitUntil(12);
    matchload.matchloadV(1);
    chassis.turnToPoint(14.25, 36.3, 1500, {.forwards = false, .minSpeed = 10});
    chassis.moveToPoint(14.25, 36.3, 1500, {.forwards = false});
    intake.moveBottomIntake(-600);
    pros::delay(150);
    intake.stopIntake();
    pros::delay(550);
    intake.intakePneumaticV(1);
    intake.intakeOut();
    chassis.turnToPoint(-23.5, -2, 2000);
    pros::delay(1400);
    intake.intakePneumaticV(0);
    chassis.moveToPoint(7, 35.3, 1500, {.forwards = false, .minSpeed = 10});
    chassis.moveToPoint(14.5, 36.3, 1500, {.forwards = false, .minSpeed = 25});
    chassis.turnToPoint(-23.5, -2, 2000);
    //score middle goal
    chassis.moveToPoint(-23.5, -2, 3000);
    intake.intakeBlock();
    chassis.turnToPoint(-23.2, -13.75, 1500, {.minSpeed = 5});
    pros::delay(650);
    matchload.matchloadV(1);
    pros::delay(150);
    chassis.moveToPoint(-23.2, -13.75, 975, {.maxSpeed = 50, .minSpeed = 40});
    pros::delay(975);
    //chassis.moveToPoint(-23.2, -7, 1200, {.maxSpeed = 80, .minSpeed = 20});
    //chassis.moveToPoint(-23.2, -13.5, 1200, {.maxSpeed = 50, .minSpeed = 40});
    //pros::delay(200);
    //finish matchload #1
    chassis.turnToPoint(-23, 21, 1500, {.forwards = false, .minSpeed = 5});
    chassis.moveToPoint(-23, 21, 2500, {.forwards = false});
    pros::delay(1200);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(2100);
    intake.stopIntake();
    //finish score high goal
    /*chassis2.moveToPoint(-14.3, 12, 3000, {.minSpeed = 25, .earlyExitRange = 1});
    chassis2.turnToPoint(-13.2, 31.5, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 1});
    chassis2.moveToPoint(-13.2, 31.5, 2000, {.forwards = false, .maxSpeed = 65, .minSpeed = 60, .earlyExitRange = 1});*/
}

void rightFourLongThreeLow() {
    //new swp
    chassis.setPose(18.1, -3.6, 90);
    chassis.moveToPoint(46.9, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(47.5, -12.5, 1500, {.minSpeed = 25, .earlyExitRange = 1});
    intake.intakeBlock();
    chassis.moveToPoint(47.5, -12.5, 950, {.maxSpeed = 55, .minSpeed = 40});
    pros::delay(1000);
    //matchload #1
    chassis.moveToPoint(47.7, 19.75, 2000, {.forwards = false, .minSpeed = 30});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(950);
    chassis.moveToPoint(47.75, 14, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    intake.outtakeBlock();
    //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
    chassis.turnToPoint(23.75, 24, 1500, {.minSpeed = 10});
    chassis.moveToPoint(23.75, 24, 2000,{.maxSpeed = 70, .minSpeed = 5, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.waitUntil(13.9);
    matchload.matchloadV(1);
    chassis.turnToPoint(14.2, 35.5, 1500, {.minSpeed = 10});
    pros::delay(500);
    matchload.matchloadV(0);
    chassis.moveToPoint(14.2, 35.5, 1500);
    chassis.waitUntil(10);
    intake.moveBottomIntake(-250);
    pros::delay(1200);
    chassis.turnToPoint(36.5, 20, 2000, {.forwards = false, .minSpeed = 20, .earlyExitRange = 3});
    chassis.moveToPoint(36.5, 20, 1500, {.forwards = false});
    intake.stopIntake();
    chassis.turnToPoint(37, 32, 2000, {.minSpeed = 10});
    chassis.moveToPoint(37, 32, 1500, {.maxSpeed = 65, .minSpeed = 50});
    chassis.turnToHeading(340, 2000, {.minSpeed = 40});
}

void rightFourLong() {
        chassis.setPose(18.1, -3.6, 90);
        chassis.moveToPoint(47, -3.6, 1500);
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.75, 855, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
        pros::delay(855);
        //matchload #1
        chassis.moveToPoint(48.1, 19.75, 1900, {.forwards = false, .minSpeed = 25, .clampDistance = false});
        chassis.waitUntil(24);
        matchload.matchloadV(0);
        intake.scoreHighGoal();
        pros::delay(830);
        chassis.moveToPoint(58.75, 12, 1500, {.minSpeed = 10, .earlyExitRange = 1.5, .pidSelector = 1});
        chassis.turnToPoint(58.5, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 1});
        chassis.moveToPoint(58.5, 34, 1500, {.forwards = false, .maxSpeed = 100, .minSpeed = 60, .earlyExitRange = 1});
        chassis.turnToHeading(210, 15000, {.minSpeed = 40});
    /*
    chassis.setPose(18.1, -3.6, 90);
    chassis.moveToPoint(47.5, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(47.8, -12.5, 855, {.maxSpeed = 80, .minSpeed = 40});
    pros::delay(855);
    //matchload #1
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 35});
    pros::delay(100);
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(925);
    chassis.swingToPoint(72, 12, DriveSide::LEFT, 2000, {.minSpeed = 45, .earlyExitRange = 5});
    chassis.turnToPoint(58, 31.5, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2});
    chassis.moveToPoint(58, 31.5, 1500, {.forwards = false, .minSpeed = 60});
    chassis.turnToHeading(205, 15000, {.minSpeed = 40});
    */

}

void rightSevenLong() {
    chassis.setPose(17, 0, 12);
    intake.intakeBlock();
    chassis.moveToPoint(23, 22.5, 2000);
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(47.25, 0.5, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.25, 0.5, 2000, {.minSpeed = 5});
    chassis.turnToPoint(47.75, -12.5, 800, {.shortTurn = true});
    chassis.moveToPoint(47.75, -12.5, 875, {.maxSpeed = 80, .clampDistance = false});
    intake.intakeBlock();
    pros::delay(875);
    intake.stopIntake();
    chassis.moveToPoint(48.2, 21.5, 2000, {.forwards = false, .minSpeed = 20});
    chassis.waitUntil(24);
    intake.moveBottomIntake(-600);
    pros::delay(75);
    intake.scoreHighGoal();
    matchload.matchloadV(0);
    pros::delay(1500);
    chassis.moveToPoint(58.75, 12, 1500, {.minSpeed = 10, .earlyExitRange = 1.5, .pidSelector = 1});
    pros::delay(100);
    intake.stopIntake();
    chassis.turnToPoint(58.75, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 1});
    chassis.moveToPoint(58.75, 34, 1500, {.forwards = false, .maxSpeed = 100, .minSpeed = 60, .earlyExitRange = 1});
    chassis.turnToHeading(210, 15000, {.minSpeed = 40});
    /*chassis.turnToPoint(-13, 36, 1500, {.forwards = false, .minSpeed = 15});
    chassis.moveToPoint(-13, 36, 2000, {.forwards = false, .minSpeed = 15});
    chassis.waitUntil(35);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    pros::delay(1000);
    chassis.moveToPoint(-10, 28, 2000);
    intake.intakePneumaticV(0);
    /*
    chassis.setPose(20, -15, 22);
    intake.intakeBlock();
    chassis.moveToPoint(18, 20, 2000, {.minSpeed = 35, .earlyExitRange = 1});
    chassis.moveToPoint(22, 24.5, 2000, {.maxSpeed = 30, .earlyExitRange = 1});
    chassis.waitUntil(2);
    matchload.matchloadV(1);
    chassis.waitUntilDone();
    pros::delay(150);
    //grab 3 stack
    chassis.turnToPoint(48, 4, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(48, 4, 2000, {.forwards = false, .minSpeed = 10});
    chassis.turnToPoint(48.2, 19.5, 1500, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 25});
    chassis.waitUntil(6);
    intake.scoreHighGoal();
    pros::delay(1100);
    chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    intake.intakeBlock();
    matchload.matchloadV(1);
    chassis.moveToPoint(47.8, -12.5, 2000, {.maxSpeed = 80, .minSpeed = 30});
    chassis.waitUntil(25);
    pros::delay(500);
    //matchload #1
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 25});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    //score long goal
    /*swp setup
    chassis.setPose(18.1, -3.6, 90);
    chassis.moveToPoint(47.65, -3.6, 1500);
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(47.8, -12.5, 900, {.maxSpeed = 80, .minSpeed = 40});
    pros::delay(900);
    //matchload #1
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 35});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1000);
    chassis.moveToPoint(48.2, 13, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
    chassis.turnToPoint(23, 25, 1500, {.minSpeed = 10});
    chassis.moveToPoint(23, 25, 2000,{.maxSpeed = 35, .minSpeed = 5});
    intake.intakeBlock();
    intake.moveTopIntake(20);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(49.4, 13, 1500, {.forwards = false});
    chassis.turnToPoint(48.15, 19.5, 2000, {.forwards = false, .minSpeed = 15});
    chassis.moveToPoint(48.15, 19.5, 2000, {.forwards = false, .minSpeed = 35});
    chassis.waitUntil(2);
    intake.scoreHighGoal();
    pros::delay(1200);
    intake.stopIntake();
    chassis.moveToPoint(48.15, 12.5, 2000, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.moveToPoint(48.15, 19.5, 2000, {.forwards = false, .minSpeed = 50});
    pros::delay(150);
    intake.scoreHighGoal();
    */
}

void rightNineLong() {
    chassis.setPose(15.5, 1.5, 45);
    intake.intakeBlock();
    chassis.moveToPoint(18, 20, 2000, {.minSpeed = 35, .earlyExitRange = 1});
    chassis.moveToPoint(22, 24.5, 2000, {.maxSpeed = 30, .earlyExitRange = 1});
    chassis.waitUntil(2);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.moveToPoint(41, 38, 2000, {.minSpeed = 10});
    pros::delay(100);
    matchload.matchloadV(0);
    //grab 4th ball
    chassis.moveToPoint(24, 21, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.turnToPoint(48, 2, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(48, 2, 2000, {.forwards = false, .minSpeed = 10});
    chassis.turnToPoint(48.2, 19.5, 1500, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 25});
    chassis.waitUntil(7);
    intake.scoreHighGoal();
    pros::delay(1300);
    chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    intake.intakeBlock();
    matchload.matchloadV(1);
    chassis.moveToPoint(47.8, -12.5, 2000, {.maxSpeed = 80, .minSpeed = 30});
    chassis.waitUntil(25);
    pros::delay(500);
    //matchload #1
    chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 25});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    chassis.moveToPoint(-39.5, 12, 1500, {.minSpeed = 10, .earlyExitRange = 1, .pidSelector = 1});
    chassis.turnToPoint(-40.5, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 1});
    chassis.moveToPoint(-40.5, 34, 1500, {.forwards = false, .maxSpeed = 100, .minSpeed = 60, .earlyExitRange = 1});
    //score long goal

}

void soloWinPoint() {
        //new swp
        chassis.setPose(18.1, -3.6, 90);
        chassis.moveToPoint(47, -3.6, 1500);
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.75, 855, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
        pros::delay(855);
        //matchload #1
        chassis.moveToPoint(48.1, 19.75, 1900, {.forwards = false, .minSpeed = 25, .clampDistance = false});
        chassis.waitUntil(24);
        matchload.matchloadV(0);
        intake.scoreHighGoal();
        pros::delay(830);
        chassis.moveToPoint(48.1, 14, 1500, {.minSpeed = 35, .earlyExitRange = 1, .clampDistance = false});
        //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
        chassis.turnToPoint(24.1, 25, 1500, {.minSpeed = 10, .shortTurn = true});
        chassis.moveToPoint(24.1, 25, 2000,{.maxSpeed = 65});
        intake.intakeBlock();
        intake.moveTopIntake(20);
        //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
        chassis.turnToPoint(-22.75, 26.8, 2000, {.minSpeed = 20, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-22.75, 26.8, 2000, {.maxSpeed = 100});
        chassis.waitUntil(28.1);
        matchload.matchloadV(1);
        chassis.turnToPoint(-11.75, 37, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2, .shortTurn = true, .turnClamping = false});
        intake.outtakeBlock();
        pros::delay(150);
        intake.stopIntake();
        chassis.moveToPoint(-11.75, 37, 2000, {.forwards = false, .minSpeed = 40});
        chassis.waitUntil(12.8);
        intake.intakePneumaticV(1);
        intake.intakeOutAuton();
        chassis.turnToPoint(-47.2, -0.5, 600, {.minSpeed = 15, .earlyExitRange = 1});
        pros::delay(600);
        intake.stopIntake();
        chassis.moveToPoint(-47.2, -0.5, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 1.85, .clampDistance = false});
        pros::delay(300);
        intake.intakePneumaticV(0);
        intake.intakeBlock();
        chassis.turnToPoint(-48, -12.5, 1500,{.minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-48, -12.5, 825, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
        pros::delay(825);
        //matchload #1
        chassis.moveToPoint(-48.1, 20.5, 2000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        chassis.waitUntil(24);
        intake.scoreHighGoal();
}

void skills() {
    //     intake.moveTopIntake(50);
    //     /*chassis.setPose(17.1, -4.1, 90);
    //     chassis.moveToPoint(47.5, -4.1, 1500);
    //     matchload.matchloadV(1);
    //     wing.wingV(1);
    //     chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    //     intake.intakeBlock();
    //     chassis.moveToPoint(47.8, -12.5, 2000, {.maxSpeed = 70, .minSpeed = 40});
    //     pros::delay(2000);
    //     //matchload #1
    //     chassis.moveToPoint(48.2, -5, 2000, {.forwards = false, .minSpeed = 35});
    //     matchload.matchloadV(0);
    //     intake.stopIntake();
    //     chassis.turnToPoint(59.5, 20, 2000, {.forwards = false, .minSpeed = 35});
    //     chassis.moveToPoint(59.5, 20, 2000, {.forwards = false, .minSpeed = 35});

    //     chassis.turnToPoint(59.5, 70, 2000, {.forwards = false});
    //     chassis.moveToPoint(59.5, 70, 2000, {.forwards = false});

    //     chassis.turnToPoint(48, 85, 2000, {.forwards = false});
    //     chassis.moveToPoint(48, 85, 2000, {.forwards = false});

    //     chassis.turnToPoint(48, 70, 2000, {.forwards = false});
    //     chassis.moveToPoint(48, 70, 2000, {.forwards = false});
    //     pros::delay(3000);
    //     intake.scoreHighGoal();

    //     chassis.turnToPoint(48, 106, 2000);
    //     matchload.matchloadV(1);
    //     chassis.moveToPoint(48, 106, 2000);

    //     pros::delay(3000);
    //     /*
    //     //new swp
    //     chassis.setPose(18.1, -3.6, 90);
    //     chassis.moveToPoint(47.5, -3.6, 1500);
    //     matchload.matchloadV(1);
    //     chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    //     intake.intakeBlock();
    //     chassis.moveToPoint(47.8, -12.5, 2000, {.maxSpeed = 70, .minSpeed = 40});
    //     pros::delay(2000);
    //     //matchload #1
    //     chassis.moveToPoint(48.2, 19.5, 2000, {.forwards = false, .minSpeed = 35});
    //     chassis.waitUntil(24);
    //     matchload.matchloadV(0);
    //     intake.scoreHighGoal();
    //     pros::delay(2500);
    //     chassis.moveToPoint(48.2, 13, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    //     //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
    //     chassis.turnToPoint(25.5, 26.5, 1500, {.minSpeed = 15, .earlyExitRange = 1});
    //     chassis.moveToPoint(25.5, 26.5, 2000,{.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 2});
    //     intake.intakeBlock();
    //     intake.moveTopIntake(20);
    //     //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
    //     chassis.turnToPoint(-24, 25.75, 2000, {.minSpeed = 15, .earlyExitRange = 4});
    //     chassis.moveToPoint(-24, 25.75, 2000, {.maxSpeed = 50});
    //     chassis.waitUntil(27.4);
    //     //matchload.matchloadV(1);
    //     chassis.turnToPoint(-11.75, 37, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    //     intake.outtakeBlock();
    //     pros::delay(100);
    //     intake.stopIntake();
    //     chassis.moveToPoint(-11.75, 37, 2000, {.forwards = false, .minSpeed = 30});
    //     chassis.waitUntil(12.9);
    //     intake.intakePneumaticV(1);
    //     intake.intakeOutAuton();
    //     chassis.turnToPoint(-46.4, -0.5, 800, {.minSpeed = 15, .earlyExitRange = 1});
    //     pros::delay(900);
    //     intake.stopIntake();
    //     chassis.moveToPoint(-46.4, -0.5, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 2});
    //     pros::delay(300);
    //     intake.intakePneumaticV(0);
    //     intake.intakeBlock();
    //     chassis.turnToPoint(-48, -12.5, 1500,{.minSpeed = 25, .earlyExitRange = 1});
    //     chassis.moveToPoint(-48, -12.5, 2000, {.maxSpeed = 70, .minSpeed = 40});
    //     pros::delay(2000);
    //     //matchload #1
    //     chassis.moveToPoint(-48.3, 20, 2000, {.forwards = false, .minSpeed = 30});
    //     chassis.waitUntil(24);
    //     intake.scoreHighGoal();
    // /*
    // chassis.setPose(17.5, -48.375, 90);
    // chassis.moveToPoint(47, -48.375, 2000);
    // wing.wingV(1);
    // chassis.turnToPoint(47, -60, 2000);
    // intake.intakeBlock();
    // pros::delay(700);
    // matchload.matchloadV(1);
    // pros::delay(200);
    // chassis.moveToPoint(47, -58.5, 2000, {.maxSpeed = 50, .minSpeed = 40});
    // pros::delay(3000);
    // chassis.moveToPoint(47, -50, 2000, {.forwards = false, .minSpeed = 20});
    // chassis.moveToPoint(47, -58.5, 2000, {.maxSpeed = 50, .minSpeed = 40});
    // pros::delay(2000);
    // chassis.moveToPoint(47, -48, 2000, {.forwards = false});
    // chassis.turnToPoint(60, -48, 2000, {.minSpeed = 5});
    // matchload.matchloadV(0);
    // intake.stopIntake();
    // chassis.moveToPoint(61, -48, 2000, {.minSpeed = 5});
    // chassis.turnToPoint(61, 32, 2000, {.minSpeed = 5});
    // chassis.moveToPoint(60.5, 32, 4000, {.maxSpeed = 100, .minSpeed = 5});

    // chassis.turnToPoint(48, 48, 2000, {.minSpeed = 10});
    // chassis.moveToPoint(48, 48, 4000, {.minSpeed = 10});

    // chassis.turnToPoint(48, 26, 3000, {.forwards = false, .minSpeed = 5});
    // chassis.moveToPoint(48, 26, 3000, {.forwards = false, .minSpeed = 5});
    // pros::delay(700);
    // intake.scoreHighGoal();
    // pros::delay(7000);
    // matchload.matchloadV(1);
    // pros::delay(200);
    // intake.intakeBlock();
    // chassis.turnToPoint(48, 58.5, 2000, {.minSpeed = 5});
    // chassis.moveToPoint(48, 58.5, 2000, {.maxSpeed = 50, .minSpeed = 40});
    // pros::delay(3000);
    // chassis.moveToPoint(47.75, 50, 2000, {.forwards = false, .minSpeed = 20});
    // chassis.moveToPoint(47.75, 58.5, 2000, {.maxSpeed = 50, .minSpeed = 40});
    // pros::delay(2000);
    // chassis.turnToPoint(47.75, 26, 3000, {.forwards = false, .minSpeed = 5});
    // chassis.moveToPoint(47.75, 26, 3000, {.forwards = false, .minSpeed = 5});
    // pros::delay(700);
    // intake.scoreHighGoal();
    // pros::delay(7000);

    // chassis.moveToPoint(47.75, 48, 3000, {.forwards = true, .minSpeed = 5});

    // chassis.turnToPoint(61, 32, 2000, { .forwards = false, .minSpeed = 5,});
    // chassis.moveToPoint(60.5, 32, 4000, {.forwards = false, .maxSpeed = 100, .minSpeed = 5});

    // chassis.turnToPoint(60.5, -48, 2000, { .forwards = false, .maxSpeed = 100, .minSpeed = 5, });
    // chassis.moveToPoint(60.5, -48, 4000, {.forwards = false, .maxSpeed = 90, .minSpeed = 5});

    // matchload.matchloadV(0);

    // chassis.turnToPoint(24, -48, 2000, { .forwards = false, .minSpeed = 5});
    // chassis.moveToPoint(24, -48, 4000, {.forwards = false, .maxSpeed = 100, .minSpeed = 5});


    // chassis.turnToPoint(24, -65.5, 3000, {.forwards = false, .minSpeed = 5});
    // chassis.moveToPoint(24, -65.5, 3000, {.forwards = false, .minSpeed = 5});

    // chassis.turnToPoint(-3, -65, 3000, {.forwards = false});
    // chassis.moveToPoint(-3, -65, 2100, {.forwards = false, .minSpeed = 40});
    //  */

        //new swp
        chassis.setPose(18.1, -3.6, 90);
        chassis.moveToPoint(47, -3.6, 1500);
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.75, 1500, {.minSpeed = 20, .earlyExitRange = 2});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.75, 2500, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
        pros::delay(2500);
        //matchload #1
        chassis.moveToPoint(48.1, 19.75, 4000, {.forwards = false, .minSpeed = 25, .clampDistance = false});
        pros::delay(1500);
        
        intake.scoreHighGoal();
        pros::delay(5000);
        intake.outtakeBlock();
        pros::delay(200);
        intake.scoreHighGoal();
        pros::delay(4000);
        matchload.matchloadV(0);
        chassis.moveToPoint(48.1, 14, 1500, {.minSpeed = 35, .earlyExitRange = 1, .clampDistance = false});
        //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
        chassis.turnToPoint(24.1, 25, 1500, {.minSpeed = 10, .shortTurn = true});
        chassis.moveToPoint(24.1, 25, 2000,{.maxSpeed = 65});
        intake.intakeBlock();
        intake.moveTopIntake(20);
        //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
        chassis.turnToPoint(-22.75, 26.8, 2000, {.minSpeed = 20, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-22.75, 26.8, 2000, {.maxSpeed = 50});
        chassis.waitUntil(28.1);
        //matchload.matchloadV(1);
        chassis.turnToPoint(-11.5, 36.8, 1500, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2, .shortTurn = true, .turnClamping = false});
        //intake.outtakeBlock();
        pros::delay(150);
        intake.stopIntake();
        chassis.moveToPoint(-11.5, 36.8, 2000, {.forwards = false, .minSpeed = 30, .clampDistance = false});
        pros::delay(1200);
        intake.intakePneumaticV(1);
        intake.intakeOutAuton();
        chassis.turnToPoint(-47.7, -0.5, 3000, {.minSpeed = 15, .earlyExitRange = 1});
        matchload.matchloadV(1);
        pros::delay(4000);
        intake.stopIntake();
        chassis.moveToPoint(-47.7, -0.5, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 1.85, .clampDistance = false});
        pros::delay(300);
        intake.intakePneumaticV(0);
        intake.intakeBlock();
        chassis.turnToPoint(-48.4, -12.5, 1500,{.minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-48.4, -12.5, 2500, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
        pros::delay(2500);
        //matchload #1
        chassis.moveToPoint(-48.5, 20.5, 4000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        pros::delay(1500);
        intake.scoreHighGoal();
        matchload.matchloadV(0);
        pros::delay(5000);
        chassis.moveToPoint(-48.5, 0, 1500);
        chassis.turnToPoint(-17, -18, 4000, {.shortTurn = true});
        chassis.moveToPoint(-17, -18, 4000);
        chassis.turnToPoint(6, -18, 4000, {.shortTurn = true});
        chassis.moveToPoint(6, -18, 2100, {.minSpeed = 100});
        
}