#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/subsystems/intake.hpp"
#include "lemlib/timer.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
//

void odomTest() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 5000);
    //chassis.turnToPoint(48, 0, 2000, {.minSpeed = 5, .earlyExitRange = 1});
    //chassis.waitUntilDone();
    //pros::screen::print(pros::E_TEXT_MEDIUM, 5, "settled");
    //chassis.moveToPoint(0, 48, 5000);
    //chassis.resetPositionRight();
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
    intake.intakeBlock();
    chassis.moveToPoint(-47.5, -12.25, 1120, {.maxSpeed = 100, .minSpeed = 40, .clampDistance = false});
    pros::delay(1120);
    //matchload #1
    chassis.moveToPoint(-47.75, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    chassis.waitUntil(25.25);
    //pros::delay(900);
    intake.intakePneumaticV(1);
    intake.scoreHighGoal();
    pros::delay(1200);
    matchload.matchloadV(0);
    intake.stopIntake();
    chassis.turnToPoint(-23.5, 24.1, 2000, {.minSpeed = 15, .earlyExitRange = 3});
    intake.intakeBlock();
    chassis.moveToPoint(-23.5, 24.1, 2000, {.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 1});
    intake.intakePneumaticV(0);
    chassis.waitUntil(6);
    matchload.matchloadV(1);
    chassis.turnToPoint(-8.5, 37.75, 2000, {.forwards = false, .pidSelector = 2});
    chassis.moveToPoint(-8.5, 37.75, 2000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    matchload.matchloadV(0);
    //intake.moveBottomIntake(-30);
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
    /*chassis.turnToPoint(-13, 36, 1500, {.forwards = false, .minSpeed = 15});
    chassis.moveToPoint(-13, 36, 2000, {.forwards = false, .minSpeed = 15});
    chassis.waitUntil(35);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    pros::delay(1000);
    chassis.moveToPoint(-10, 28, 2000);
    intake.intakePneumaticV(0);*/

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
/*
    
    //matchload #1
    //score long goal
    chassis.setPose(-18.1, -3.6, 270);
    chassis.moveToPoint(-47, -3.6, 1500, {.minSpeed = 15, .earlyExitRange = 1});
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.75, -13, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(-48.75, -13, 860, {.maxSpeed = 100, .minSpeed = 45, .clampDistance = false});
    pros::delay(860);
    //matchload #1
    chassis.moveToPoint(-49.4, 19.75, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1000);
    intake.stopIntake();
    chassis.moveToPoint(-49.4, 0, 1500, {.minSpeed = 15, .earlyExitRange = 1, .clampDistance = false});
    intake.intakeBlock();
    chassis.turnToPoint(-23.8, 23.75, 1000, {.pidSelector = 2});
    chassis.moveToPoint(-23.8, 23.75, 2000,{.maxSpeed = 50});
    chassis.waitUntil(25.5);
    matchload.matchloadV(1);
    //chassis.waitUntil(13);
    //matchload.matchloadV(1);
    intake.moveTopIntake(10);
    //chassis.turnToPoint(-40.85, 37.1, 2000, {.minSpeed = 15});
    //chassis.moveToPoint(-40.85, 37.1, 2000, {.minSpeed = 15});
    //chassis.moveToPoint(-23.6, 24, 2000, {.forwards = false, .minSpeed = 15});
    chassis.turnToPoint(-12, 37.5, 1000, {.forwards = false, .pidSelector = 3});
    intake.outtakeBlock();
    pros::delay(100);
    intake.stopIntake();
    chassis.moveToPoint(-12, 37.5, 2000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    //chassis.moveToPose(-11.35, 35.6, 225, 2000);
    chassis.waitUntil(13);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    matchload.matchloadV(0);
    pros::delay(1500);
    intake.intakePneumaticV(0);
    intake.stopIntake();
    chassis.moveToPoint(-18.1, 30.3, 2000, {.minSpeed = 10});
    chassis.waitUntilDone();
    descore.descoreV(1);
    pros::delay(125);
    chassis.moveToPoint(-12, 37.1, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    //chassis.moveToPoint(-18.1, 30.3, 2000, {.minSpeed = 10});
    //chassis.waitUntilDone();
    //pros::delay(200);
    //chassis.moveToPoint(-20, 28, 2000);
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
    chassis.moveToPoint(-47, -3.6, 1500, {.minSpeed = 15, .earlyExitRange = 1});
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.75, -13, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(-48.75, -13, 860, {.maxSpeed = 100, .minSpeed = 45, .clampDistance = false});
    pros::delay(860);
    //matchload #1
    chassis.moveToPoint(-49.4, 19.75, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1100);
    intake.stopIntake();
    chassis.moveToPoint(-49.4, 12, 1500, {.minSpeed = 20});
    intake.intakeBlock();
    chassis.turnToPoint(-23, 24.25, 1500, {.pidSelector = 2});
    chassis.moveToPoint(-23, 24.25, 2000,{.maxSpeed = 50});
    //chassis.waitUntil(25.5);
    //matchload.matchloadV(1);
    //chassis.waitUntil(13);
    //matchload.matchloadV(1);
    intake.moveTopIntake(10);
    chassis.turnToPoint(-41, 39.5, 2000, {.minSpeed = 20, .earlyExitRange = 35});
    chassis.moveToPoint(-41, 39.5, 2000, {.pidSelector = 1});
    chassis.moveToPoint(-23.6, 24, 2000, {.forwards = false, .pidSelector = 1});
    chassis.turnToPoint(-12, 37.1, 1500, {.forwards = false, .pidSelector = 3});
    matchload.matchloadV(1);
    chassis.moveToPoint(-12, 37.1, 2000, {.forwards = false, .minSpeed = 25, .clampDistance = false});
    intake.outtakeBlock();
    pros::delay(100);
    intake.stopIntake();
    //chassis.moveToPose(-11.35, 35.6, 225, 2000);
    chassis.waitUntil(13);
    intake.intakePneumaticV(1);
    intake.intakeOutAuton();
    matchload.matchloadV(0);
    pros::delay(1500);
    intake.intakePneumaticV(0);
    chassis.moveToPoint(-18.1, 30.3, 2000, {.minSpeed = 10});
    intake.stopIntake();
    chassis.waitUntilDone();
    descore.descoreV(1);
    pros::delay(120);
    chassis.moveToPoint(-12, 37.5, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    //chassis.moveToPoint(-17, 33, 2000);
    /*
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
    */
}

void leftFourLong() {
    chassis.setPose(-15.5, -1, 347.6);
    intake.intakeBlock();
    chassis.moveToPoint(-23, 22.5, 2000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(-47, 12, 2000, {.minSpeed = 10});
    chassis.moveToPoint(-47, 12, 2000, {.minSpeed = 40, .earlyExitRange = 4});
    chassis.turnToPoint(-48.25, 21.5, 800, {.forwards = false, .minSpeed = 25, .earlyExitRange = 1, .shortTurn = true});
    //chassis.moveToPoint(48.45, -12.5, 950, { .minSpeed = 45, .clampDistance = false});
    //intake.intakeBlock();
    //pros::delay(950);
    chassis.moveToPoint(-48.25, 21.5, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    chassis.waitUntil(6.5);
    intake.intakePneumaticV(1);
    //wing.wingV(1);
    intake.scoreHighGoal();
    pros::delay(1000);
    matchload.matchloadV(0);
    intake.stopIntake();
    
    //chassis.setPose(48.25, 21.5, 180);
    //wing.wingV(1);
    //chassis.turnToPoint(44, 70, 1500, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 3});
    //chassis.moveToPoint(40, 37, 1500, {.minSpeed = 60, .earlyExitRange = 1});
    //pros::delay(600);
    //wing.wingV(0);
    //chassis.turnToHeading(320, 15000, {.minSpeed = 60});
    chassis.moveToPoint(-37, 12, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.turnToPoint(57.75, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    //intake.intakePneumaticV(1);
    chassis.moveToPoint(-38, 33, 1200, {.forwards = false, .minSpeed = 60, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
    /*
    /*
    chassis.setPose(-18.1, -3.6, 270);
    chassis.moveToPoint(-47, -3.6, 1500, {.minSpeed = 15, .earlyExitRange = 1});
    matchload.matchloadV(1);
    chassis.turnToPoint(-48.75, -13, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    intake.intakeBlock();
    chassis.moveToPoint(-48.75, -13, 860, {.maxSpeed = 90, .minSpeed = 45, .clampDistance = false});
    pros::delay(860);
    //matchload #1
    chassis.moveToPoint(-49.4, 19.75, 2000, {.forwards = false, .minSpeed = 40, .clampDistance = false});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    pros::delay(1000);
    intake.stopIntake();
    chassis.moveToPoint(-39.25, 11, 1500, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.moveToPoint(-39.2, 12, 1500, {.minSpeed = 10, .earlyExitRange = 1, .pidSelector = 1});
    chassis.turnToPoint(-41.75, 31.25, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(-41.75, 31.25, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 2, .clampDistance = false});
    chassis.turnToHeading(210, 2000, {.minSpeed = 40});
    */
}

void leftSevenLong() {
    chassis.setPose(-15.5, -1, 357.6);
    intake.intakeBlock();
    chassis.moveToPoint(-23, 22.5, 2000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(-47.25, -1, 2000, {.minSpeed = 10});
    chassis.moveToPoint(-47.25, -1, 2000, {.minSpeed = 40, .earlyExitRange = 4});
    chassis.turnToPoint(-48.45, -12.5, 800, {.minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(-48.45, -12.5, 950, {.minSpeed = 50, .clampDistance = false});
    intake.intakeBlock();
    pros::delay(950);
    chassis.moveToPoint(-48.25, 21.5, 2000, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(18);
    intake.moveBottomIntake(-200);
    pros::delay(100);
    intake.intakePneumaticV(1);
    //wing.wingV(1);
    intake.scoreHighGoal();
    pros::delay(1400);
    matchload.matchloadV(0);
    intake.stopIntake();
    
    //chassis.setPose(48.25, 21.5, 180);
    //wing.wingV(1);
    //chassis.turnToPoint(44, 70, 1500, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 3});
    //chassis.moveToPoint(40, 37, 1500, {.minSpeed = 60, .earlyExitRange = 1});
    //pros::delay(600);
    //wing.wingV(0);
    //chassis.turnToHeading(320, 15000, {.minSpeed = 60});
    chassis.moveToPoint(36.25, 12, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.turnToPoint(57.75, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    //intake.intakePneumaticV(1);
    chassis.moveToPoint(37.75, 33, 1200, {.forwards = false, .minSpeed = 60, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
    /*chassis.turnToPoint(-13, 36, 1500, {.forwards = false, .minSpeed = 15});
    /*
    chassis.setPose(-17, 0, -12);
    intake.intakeBlock();
    chassis.moveToPoint(-23, 22.5, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(-49.4, 0.5, 2000, {.minSpeed = 10, .earlyExitRange = 2});
    chassis.moveToPoint(-49.4, 0.5, 2000, {.minSpeed = 10});
    chassis.turnToPoint(-50.5, 21.5, 600, {.minSpeed = 5, .shortTurn = true});
    //chassis.moveToPoint(-50, -12.5, 850, {.maxSpeed = 90, .minSpeed = 45, .clampDistance = false});
    //intake.intakeBlock();
    //pros::delay(850);
    //intake.stopIntake();
    //chassis.moveToPoint(-50.5, 21.5, 2000, {.forwards = false, .minSpeed = 35, .clampDistance = false});
    chassis.waitUntil(6);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    intake.intakePneumaticV(1);
    pros::delay(800);
    intake.intakePneumaticV(0);
    intake.stopIntake();
    chassis.moveToPoint(-39.75, 13, 1500, {.minSpeed = 25, .earlyExitRange = 2, .pidSelector = 1});
    chassis.turnToPoint(-41.5, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(-41.5, 34, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 1});
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

void leftThreeGoal() {

}

void rightFourLongThreeLow() {
    chassis.setPose(16.875, -4, 90);
    chassis.moveToPoint(45.8, -4, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.75, -12.5, 1500, {.minSpeed = 5, .earlyExitRange = 3});
    intake.intakeBlock();
    chassis.moveToPoint(47.75, -12.5, 1100, {.minSpeed = 50, .clampDistance = false});
    pros::delay(1100);
    //matchload #1
    chassis.moveToPoint(48, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    chassis.waitUntil(25.25);
    //pros::delay(900);
    intake.intakePneumaticV(1);
    intake.scoreHighGoal();
    pros::delay(900);
    intake.stopIntake();
    matchload.matchloadV(0);
    chassis.turnToPoint(23.5, 24.1, 2000, {.minSpeed = 25, .earlyExitRange = 3});
    intake.moveBottomIntake(600);
    chassis.moveToPoint(23.5, 24.1, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    intake.intakePneumaticV(0);
    chassis.waitUntil(5.75);
    matchload.matchloadV(1);
    chassis.turnToPoint(12, 36, 2000, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(12, 36, 2000, {.minSpeed = 10});
    matchload.matchloadV(0);
    intake.stopIntake();
    pros::delay(550);
    matchload.matchloadV(1);
    intakeLift.intakeLiftV(1);
    intake.outtakeBlockAuton();
    pros::delay(1100);
    chassis.moveToPoint(32.5, 10, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3});
    intakeLift.intakeLiftV(0);
    matchload.matchloadV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(31, 32, 2000, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(34, 32, 1500, {.minSpeed = 60, .earlyExitRange = 2});
    chassis.turnToHeading(325, 2000, {.minSpeed = 60});
/*
    //new swp
    chassis.setPose(17, 0, 12);
    intake.intakeBlock();
    chassis.moveToPoint(23, 22.5, 2000);
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.moveToPoint(42, 40.75, 2000, {.maxSpeed = 100, .pidSelector = 1});
    pros::delay(150);
    matchload.matchloadV(0);
    //grab 4th ball
    chassis.moveToPoint(31, 21, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    chassis.turnToPoint(47.25, 6, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(47.25, 6, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .clampDistance = false});
    chassis.turnToPoint(47.5, 21.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.5, 21.5, 2000, {.forwards = false, .minSpeed = 25});
    matchload.matchloadV(1);
    intake.outtakeBlock();
    pros::delay(150);
    intake.stopIntake();
    pros::delay(350);
    intake.scoreHighGoal();
    pros::delay(1600);
    chassis.moveToPoint(47.3, 0, 2000, {.minSpeed = 10});
    intake.intakeBlock();
    chassis.turnToPoint(47.3, -12.5, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.3, -12.5, 750, {.maxSpeed = 90, .minSpeed = 35});
    pros::delay(750);
    chassis.moveToPoint(47.3, 0, 2000, {.forwards = false, .minSpeed = 10});
    chassis.turnToPoint(14.75, 35.5, 2000, {.pidSelector = 2});
    matchload.matchloadV(0);
    chassis.moveToPoint(15, 35.75, 2000, {.minSpeed = 10});
    chassis.waitUntilDone();
    intake.moveBottomIntake(-200);
    intake.moveTopIntake(200);
    //chassis.turnToPoint(37.25, 20, 2000, {.forwards = false, .shortTurn = true});
    //chassis.moveToPoint(37.25, 20, 1500, {.forwards = false});
    //chassis.turnToPoint(38, 32, 2000, {.shortTurn = true});
    //chassis.moveToPoint(38, 32, 1500, {.maxSpeed = 100, .minSpeed = 60});
    //chassis.turnToHeading(335, 2000, {.minSpeed = 40});
    */
}

void rightFourLong() {
    chassis.setPose(15.5, -1, 12.4);
    intake.intakeBlock();
    chassis.moveToPoint(23, 22.5, 2000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(47, 14, 2000, {.minSpeed = 10});
    chassis.moveToPoint(47, 14, 2000, {.minSpeed = 40, .earlyExitRange = 4});
    chassis.turnToPoint(48.25, 21.5, 800, {.forwards = false, .minSpeed = 25, .earlyExitRange = 1, .shortTurn = true});
    //chassis.moveToPoint(48.45, -12.5, 950, { .minSpeed = 45, .clampDistance = false});
    //intake.intakeBlock();
    //pros::delay(950);
    chassis.moveToPoint(48.25, 21.5, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    chassis.waitUntil(4.5);
    intake.intakePneumaticV(1);
    //wing.wingV(1);
    intake.scoreHighGoal();
    pros::delay(1000);
    matchload.matchloadV(0);
    intake.stopIntake();
    
    //chassis.setPose(48.25, 21.5, 180);
    //wing.wingV(1);
    //chassis.turnToPoint(44, 70, 1500, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 3});
    //chassis.moveToPoint(40, 37, 1500, {.minSpeed = 60, .earlyExitRange = 1});
    //pros::delay(600);
    //wing.wingV(0);
    //chassis.turnToHeading(320, 15000, {.minSpeed = 60});
    chassis.moveToPoint(59, 12, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.turnToPoint(57.75, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    //intake.intakePneumaticV(1);
    chassis.moveToPoint(58, 33, 1200, {.forwards = false, .minSpeed = 60, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
    /*
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
    chassis.setPose(15.5, -1, 12.4);
    intake.intakeBlock();
    chassis.moveToPoint(23, 22.5, 2000, {.minSpeed = 50, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(47.25, -1, 2000, {.minSpeed = 10});
    chassis.moveToPoint(47.25, -1, 2000, {.minSpeed = 40, .earlyExitRange = 4});
    chassis.turnToPoint(48.45, -12.5, 800, {.minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(48.45, -12.5, 950, {.minSpeed = 50, .clampDistance = false});
    intake.intakeBlock();
    pros::delay(950);
    chassis.moveToPoint(48.25, 21.5, 2000, {.forwards = false, .minSpeed = 50, .clampDistance = false});
    chassis.waitUntil(18);
    intake.moveBottomIntake(-200);
    pros::delay(100);
    intake.intakePneumaticV(1);
    //wing.wingV(1);
    intake.scoreHighGoal();
    pros::delay(1400);
    matchload.matchloadV(0);
    intake.stopIntake();
    
    //chassis.setPose(48.25, 21.5, 180);
    //wing.wingV(1);
    //chassis.turnToPoint(44, 70, 1500, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 25, .earlyExitRange = 3});
    //chassis.moveToPoint(40, 37, 1500, {.minSpeed = 60, .earlyExitRange = 1});
    //pros::delay(600);
    //wing.wingV(0);
    //chassis.turnToHeading(320, 15000, {.minSpeed = 60});
    chassis.moveToPoint(59.75, 12, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    //chassis.turnToPoint(57.75, 34, 1500, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    //intake.intakePneumaticV(1);
    chassis.moveToPoint(58.25, 33, 1200, {.forwards = false, .minSpeed = 60, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 50});
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

    chassis.setPose(17, 0, 12);
    intake.intakeBlock();
    chassis.moveToPoint(23, 22.5, 2000);
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.moveToPoint(42, 40.75, 2000, {.maxSpeed = 100, .pidSelector = 1});
    pros::delay(150);
    matchload.matchloadV(0);
    //grab 4th ball
    chassis.moveToPoint(31, 21, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .pidSelector = 1, .clampDistance = false});
    chassis.turnToPoint(47.25, 5, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1});
    chassis.moveToPoint(47.25, 5, 2000, {.forwards = false, .minSpeed = 15, .earlyExitRange = 1, .clampDistance = false});
    chassis.turnToPoint(47.5, 21.5, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.5, 21.5, 2000, {.forwards = false, .minSpeed = 25});
    matchload.matchloadV(1);
    intake.outtakeBlock();
    pros::delay(150);
    intake.stopIntake();
    pros::delay(350);
    intake.scoreHighGoal();
    pros::delay(1300);
    chassis.moveToPoint(47, 0, 2000, {.minSpeed = 10});
    intake.intakeBlock();
    chassis.turnToPoint(47, -12.5, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    chassis.moveToPoint(47.1, -12.5, 1100, {.maxSpeed = 80, .minSpeed = 25});
    pros::delay(1100);
    //matchload #1
    chassis.moveToPoint(47.2, 19.5, 2000, {.forwards = false, .minSpeed = 25});
    chassis.waitUntil(24);
    matchload.matchloadV(0);
    intake.scoreHighGoal();
    //score long goal
}

void rightThreeGoal() {
    chassis.setPose(16.875, -4, 90);
    chassis.moveToPoint(45.8, -4, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.75, -12.5, 1500, {.minSpeed = 5, .earlyExitRange = 3});
    intake.intakeBlock();
    chassis.moveToPoint(47.75, -12.5, 1100, {.minSpeed = 50, .clampDistance = false});
    pros::delay(1100);
    //matchload #1
    chassis.moveToPoint(48, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
    chassis.waitUntil(25.25);
    //pros::delay(900);
    intake.intakePneumaticV(1);
    intake.scoreHighGoal();
    pros::delay(900);
    intake.stopIntake();
    matchload.matchloadV(0);
    chassis.turnToPoint(23.5, 24.1, 2000, {.minSpeed = 25, .earlyExitRange = 3});
    intake.moveBottomIntake(600);
    chassis.moveToPoint(23.5, 24.1, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    intake.intakePneumaticV(0);
    chassis.waitUntil(5.75);
    matchload.matchloadV(1);
    chassis.turnToPoint(12, 36, 2000, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(12, 36, 2000, {.minSpeed = 10});
    matchload.matchloadV(0);
    intake.stopIntake();
    pros::delay(550);
    matchload.matchloadV(1);
    intakeLift.intakeLiftV(1);
    intake.outtakeBlockAuton();
    pros::delay(1100);
    chassis.moveToPoint(23.5, 24.1, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 1});
    intakeLift.intakeLiftV(0);
    matchload.matchloadV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(-22.5, 24.4, 1800, {.minSpeed = 5, .earlyExitRange = 1});
    intake.intakeBlock();
    chassis.moveToPoint(-22.5, 24.4, 1800, {.maxSpeed = 100, .pidSelector = 1});
    //matchload.matchloadV(0);
    chassis.waitUntil(25.25);
    //pros::delay(1000);
    matchload.matchloadV(1);
    //intake.moveMiddleIntake(0);
    //intake.moveTopIntake(0);
    chassis.turnToPoint(-10.25, 36.25, 800, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //intake.outtakeBlock();
    //pros::delay(125);
    //intake.stopIntake();
    chassis.moveToPoint(-10.25, 36.25, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 1, .clampDistance = false});
    intake.moveBottomIntake(-20);
    intake.moveMiddleIntake(-30);
    intake.moveTopIntake(-30);
    chassis.waitUntil(14.5);
    //pros::delay(600);
    //intake.intakePneumaticV(1);
    intake.intakeOutAutonSlow();
    

}

void soloWinPoint() {
        //new swp
        chassis.setPose(16.875, -4, 90);
        chassis.moveToPoint(46.6, -4, 1500, {.minSpeed = 10, .earlyExitRange = 1});
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.25, 1500, {.minSpeed = 20, .earlyExitRange = 1.5});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.25, 1050, {.maxSpeed = 100, .minSpeed = 50, .clampDistance = false});
        pros::delay(1050);
        //matchload #1
        chassis.moveToPoint(48, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        chassis.waitUntil(24.75);
        //pros::delay(900);
        intake.intakePneumaticV(1);
        matchload.matchloadV(0);
        intake.scoreHighGoal();
        pros::delay(1100);
        intake.stopIntake();
        chassis.turnToPoint(23.5, 24, 2000, {.minSpeed = 15, .earlyExitRange = 3});
        /*chassis.moveToPoint(48, 14, 1500, {.minSpeed = 25, .earlyExitRange = 1, .clampDistance = false});
        intake.intakePneumaticV(0);
        //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
        chassis.turnToPoint(23.5, 25, 1500, {.minSpeed = 5, .pidSelector = 2});
        */
        chassis.moveToPoint(23.5, 24, 2000);
        intake.intakePneumaticV(0);
        intake.intakeBlock();
        chassis.waitUntil(3.5);
        matchload.matchloadV(1);
        pros::delay(500);
        matchload.matchloadV(0);
        //pros::delay(250);
        //matchload.matchloadV(0);
        //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
        //chassis.turnToPoint(-22.5, 26.8, 1000, {.minSpeed = 20, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-22.5, 24.4, 1800, {.maxSpeed = 80, .pidSelector = 1});
        //matchload.matchloadV(0);
        chassis.waitUntil(25.25);
        //pros::delay(1000);
        matchload.matchloadV(1);
        //intake.moveMiddleIntake(0);
        //intake.moveTopIntake(0);
        chassis.turnToPoint(-10.25, 36.25, 800, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
        //intake.outtakeBlock();
        //pros::delay(125);
        //intake.stopIntake();
        chassis.moveToPoint(-10.25, 36.25, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 1, .clampDistance = false});
        intake.moveBottomIntake(-20);
        intake.moveMiddleIntake(-30);
        intake.moveTopIntake(-30);
        chassis.waitUntil(14.5);
        //pros::delay(600);
        //intake.intakePneumaticV(1);
        intake.intakeOutAutonSlow();
        chassis.turnToPoint(-45.8, -2, 1100, {.minSpeed = 15, .earlyExitRange = 1});
        pros::delay(900);
        intake.stopIntake();
        pros::delay(150);
        chassis.moveToPoint(-45.8, -2, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 1.85, .clampDistance = false});
        //intake.moveTopIntake(-300);
        //pros::delay(100);
        //intake.stopIntake();
        pros::delay(100);
        intake.moveTopIntake(300);
        intake.moveMiddleIntake(-300);
        pros::delay(150);
        //intake.stopIntake();
        intake.intakeBlock();
        chassis.turnToPoint(-46.7, -12.5, 1500, {.minSpeed = 5, .shortTurn = true});
        chassis.moveToPoint(-46.7, -12.5, 925, {.maxSpeed = 100, .minSpeed = 50, .clampDistance = false});
        pros::delay(925);
        chassis.turnToPoint(-46.9, 21.5, 300, {.forwards = false, .minSpeed = 20, .shortTurn = true});
        pros::delay(300);
        //matchload #1
        chassis.moveToPoint(-46.9, 21.5, 2000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        chassis.waitUntil(24);
        intake.intakePneumaticV(1);
        intake.scoreHighGoal();
}

void skills() {
        //new swp
        /*
        chassis.setPose(18.1, -3.6, 90);
        chassis.moveToPoint(47.25, -3.6, 1500);
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.65, 1500, {.minSpeed = 10, .earlyExitRange = 1});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.65, 2500, {.maxSpeed = 80, .minSpeed = 45, .clampDistance = false});
        pros::delay(2500);
        //matchload #1
        chassis.moveToPoint(48, 19.95, 2000, {.forwards = false});
        chassis.waitUntil(24.25);
        pros::delay(2500);
        intake.outtakeBlock();
        pros::delay(175);
        intake.scoreHighGoal();
        pros::delay(2500);
        matchload.matchloadV(0);
        chassis.moveToPoint(48, 14, 1500, {.minSpeed = 25, .earlyExitRange = 1, .clampDistance = false});
        //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
        chassis.turnToPoint(24.1, 25, 1500, {.minSpeed = 5, .shortTurn = true});
        chassis.moveToPoint(24.1, 25, 2000,{.maxSpeed = 70});
        intake.intakeBlock();
        intake.moveTopIntake(20);
        //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
        chassis.turnToPoint(-22.5, 26.8, 1000, {.minSpeed = 20, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-22.5, 26.8, 1900, {.maxSpeed = 100});
        chassis.waitUntil(28.1);
        //matchload.matchloadV(1);
        chassis.turnToPoint(-11.75, 37, 900, {.forwards = false, .minSpeed = 25, .earlyExitRange = 2, .shortTurn = true, .turnClamping = false});
        intake.outtakeBlock();
        pros::delay(150);
        intake.stopIntake();
        chassis.moveToPoint(-11.75, 37, 2000, {.forwards = false, .minSpeed = 50, .clampDistance = false});
        chassis.waitUntil(12.8);
        intake.intakePneumaticV(1);
        intake.intakeOutAuton();
        chassis.turnToPoint(-47.85, -0.25, 2000, {.minSpeed = 20, .earlyExitRange = 1});
        matchload.matchloadV(1);
        pros::delay(2000);
        chassis.moveToPoint(-47.85, -0.25, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 1.85, .clampDistance = false});
        intake.stopIntake();
        intake.intakePneumaticV(0);
        pros::delay(300);
        intake.intakeBlock();
        chassis.turnToPoint(-47.8, -12.5, 1500, {.minSpeed = 15, .shortTurn = true});
        chassis.moveToPoint(-47.8, -12.5, 2500, {.maxSpeed = 80, .minSpeed = 45, .clampDistance = false});
        pros::delay(2500);
        //matchload #1
        chassis.moveToPoint(-48.5, 21, 5000, {.forwards = false, .minSpeed = 25, .clampDistance = false});
        chassis.waitUntil(24);
        intake.scoreHighGoal();
        matchload.matchloadV(1);
        pros::delay(2500);
        intake.outtakeBlock();
        pros::delay(175);
        intake.scoreHighGoal();
        pros::delay(2500);
        */
            //new swp
        chassis.setPose(16.875, -4, 90);
        chassis.moveToPoint(46.6, -4, 1500, {.minSpeed = 10, .earlyExitRange = 1});
        matchload.matchloadV(1);
        chassis.turnToPoint(47.8, -12.25, 1500, {.minSpeed = 20, .earlyExitRange = 1.5});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.25, 3050, {.maxSpeed = 100, .minSpeed = 50, .clampDistance = false});
        pros::delay(3050);
        //matchload #1
        chassis.moveToPoint(48, 19.95, 1900, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        chassis.waitUntil(24.75);
        //pros::delay(900);
        intake.intakePneumaticV(1);
        matchload.matchloadV(0);
        intake.scoreHighGoal();
        pros::delay(4000);
        intake.stopIntake();
        chassis.turnToPoint(23.5, 24, 2000, {.minSpeed = 15, .earlyExitRange = 3});
        /*chassis.moveToPoint(48, 14, 1500, {.minSpeed = 25, .earlyExitRange = 1, .clampDistance = false});
        intake.intakePneumaticV(0);
        //chassis.swingToPoint(24, 24.4, DriveSide::RIGHT, 2000, {.maxSpeed = 100, .minSpeed = 5});
        chassis.turnToPoint(23.5, 25, 1500, {.minSpeed = 5, .pidSelector = 2});
        */
        chassis.moveToPoint(23.5, 24, 2000);
        intake.intakePneumaticV(0);
        intake.intakeBlock();
        chassis.waitUntil(3.5);
        //matchload.matchloadV(1);
        pros::delay(500);
        matchload.matchloadV(0);
        //pros::delay(250);
        //matchload.matchloadV(0);
        //chassis.moveToPoint(-24, 24.5, 2000, {.maxSpeed = 100, .pidSelector = 1});
        //chassis.turnToPoint(-22.5, 26.8, 1000, {.minSpeed = 20, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(-22.5, 24.4, 1800, {.maxSpeed = 80, .pidSelector = 1});
        //matchload.matchloadV(0);
        chassis.waitUntil(25.25);
        //pros::delay(1000);
        //matchload.matchloadV(1);
        //intake.moveMiddleIntake(0);
        //intake.moveTopIntake(0);
        chassis.turnToPoint(-10.25, 36.25, 800, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
        //intake.outtakeBlock();
        //pros::delay(125);
        //intake.stopIntake();
        chassis.moveToPoint(-10.25, 36.25, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 1, .clampDistance = false});
        intake.moveBottomIntake(-20);
        intake.moveMiddleIntake(-30);
        intake.moveTopIntake(-30);
        chassis.waitUntil(14.5);
        //pros::delay(600);
        //intake.intakePneumaticV(1);
        intake.intakeOutSkills();
        chassis.turnToPoint(-45.8, -2, 1100, {.minSpeed = 15, .earlyExitRange = 1});
        pros::delay(2000);
        intake.stopIntake();
        matchload.matchloadV(1);
        pros::delay(150);
        chassis.moveToPoint(-45.8, -2, 2000, {.maxSpeed = 105, .minSpeed = 10, .earlyExitRange = 1.85, .clampDistance = false});
        //intake.moveTopIntake(-300);
        //pros::delay(100);
        //intake.stopIntake();
        pros::delay(100);
        intake.moveTopIntake(300);
        intake.moveMiddleIntake(-300);
        pros::delay(150);
        //intake.stopIntake();
        intake.intakeBlock();
        chassis.turnToPoint(-46.7, -12.5, 1500, {.minSpeed = 5, .shortTurn = true});
        chassis.moveToPoint(-46.7, -12.5, 2000, {.maxSpeed = 100, .minSpeed = 50, .clampDistance = false});
        pros::delay(2000);
        chassis.turnToPoint(-46.9, 21.5, 300, {.forwards = false, .minSpeed = 20, .shortTurn = true});
        pros::delay(300);
        //matchload #1
        chassis.moveToPoint(-46.9, 21.5, 2000, {.forwards = false, .minSpeed = 20, .clampDistance = false});
        chassis.waitUntil(24);
        intake.intakePneumaticV(1);
        intake.scoreHighGoal();
        pros::delay(4000);
        chassis.moveToPoint(-46.9, 2, 2000, {.minSpeed = 5});
        matchload.matchloadV(0);
        chassis.turnToPoint(-33, -17, 1500, {.minSpeed = 5, .shortTurn = true});
        chassis.moveToPoint(-33, -17, 2000, {.minSpeed = 5});
        chassis.turnToPoint(2, -17, 1500, {.minSpeed = 5, .shortTurn = true});
        chassis.moveToPoint(2, -17, 2500, {.minSpeed = 127, .clampDistance = false});
        /*
        chassis.setPose(18.1, -3.6, 90);
        chassis.moveToPoint(47, -3.6, 1500);
        matchload.matchloadV(1);
        wing.wingV(1);
        chassis.turnToPoint(47.8, -12.5, 1500, {.minSpeed = 20, .earlyExitRange = 2});
        intake.intakeBlock();
        chassis.moveToPoint(47.8, -12.5, 2000, {.maxSpeed = 60, .minSpeed = 60, .clampDistance = false});
        pros::delay(2000);
        //matchload #1
        chassis.moveToPoint(48.1, 0, 2000, {.forwards = false, .minSpeed = 20});
        intake.stopIntake();
        chassis.turnToPoint(37.5, 20, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(37.5, 20, 2000, {.forwards = false, .minSpeed = 5});

        chassis.turnToPoint(41, 68, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(41, 68, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 1});
        chassis.swingToPoint(48, 106, DriveSide::LEFT, 2500, {.direction = AngularDirection::CW_CLOCKWISE, .minSpeed = 75});
        chassis.moveToPoint(48, 70, 2000, {.forwards = false, .minSpeed = 40});
        intake.scoreHighGoal();
        */

        /*chassis.turnToPoint(36, 75, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(36, 75, 2000, {.forwards = false, .maxSpeed = 90, .minSpeed = 5});

        chassis.turnToPoint(49, 85, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
        chassis.moveToPoint(49, 85, 2000, {.forwards = false, .minSpeed = 5});

        chassis.turnToPoint(49, 70, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .pidSelector = 2});
        chassis.moveToPoint(49, 70, 2000, {.forwards = false, .minSpeed = 15, .clampDistance = false});
        pros::delay(1500);
        intake.scoreHighGoal();
        pros::delay(2500);
        intake.stopIntake();
        chassis.moveToPoint(47.5, 95, 2000, {.minSpeed = 5});
        chassis.turnToPoint(47.5, 105, 2000, {.maxSpeed = 100});
        chassis.moveToPoint(48, 105, 2000, {.maxSpeed = 100, .clampDistance = false});
        //pros::delay(2000);
/*
        chassis.turnToPoint(48, 106, 2000);
        matchload.matchloadV(1);
        chassis.moveToPoint(48, 106, 2000);

        pros::delay(3000);

        chassis.moveToPoint(48, 70, 2000, {.forwards = false});
        intake.scoreHighGoal();
        pros::delay(3000);
        intake.stopIntake();
        matchload.matchloadV(0);
       
        chassis.moveToPoint(48, 82, 2000, {});
        chassis.turnToPoint(-48, 82, 2000, {});
        chassis.moveToPoint(-48, 82, 2000, {});

        chassis.turnToPoint(-48, 105, 2000, {});
        matchload.matchloadV(1);
        chassis.moveToPoint(-48, 105, 2000, {});
        intake.intakeBlock();
        pros::delay(3000);

        chassis.moveToPoint(-48, 82, 2000, {.forwards = false});
        chassis.turnToPoint(-59.5, 82, 2000, {.forwards = false});
        chassis.moveToPoint(-59.5, 82, 2000, {.forwards = false});

        chassis.turnToPoint(-59.5, 20, 2000, {.forwards = false});
        chassis.moveToPoint(-59.5, 20, 2000, {.forwards = false});

        chassis.turnToPoint(-48, 10, 2000, {.forwards = false});
        chassis.moveToPoint(-48, 10, 2000, {.forwards = false});

        chassis.turnToPoint(-48, 48, 2000, {.forwards = false});
        chassis.moveToPoint(-48, 48, 2000, {.forwards = false});
        intake.scoreHighGoal();
        pros::delay(3000);

        intake.stopIntake();
        matchload.matchloadV(1);
        chassis.turnToPoint(-48, -12, 2000, {});
        intake.intakeBlock();
        chassis.moveToPoint(-48, -12, 2000, {});
        pros::delay(3000);

        chassis.moveToPoint(48, 5, 2000, {.forwards = false});
        chassis.turnToPoint(0, -12, 2000, {});
        chassis.moveToPoint(0, -12, 2000, {.minSpeed = 65});*/

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

      /*  //new swp
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
        */
}