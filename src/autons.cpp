#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/odom.hpp"
#include "lemlib/subsystems/intake.hpp"
#include "lemlib/timer.hpp"
#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
//

void odomTest() {
    chassis.setPose(48, 24, 180);
    pros::delay(3000);
    chassis.resetPositionFront();
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
    chassis.moveToPoint(-47.2, 20, 1500, {.minSpeed = 15, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(-47.8, 11.75, 1500, {.minSpeed = 25, .earlyExitRange = 2});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(-47.8, 11.75, 800, {.minSpeed = 50, .clampDistance = false});
    pros::delay(825);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(-48, 43.95, 1900, {.forwards = false, .minSpeed = 45, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(775);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    intake.stopIntake();
    //grab three stack
    chassis.turnToPoint(-23.5, 48.25, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(-23.5, 48.25, 2000, {.minSpeed = 30, .earlyExitRange = 1.5});
    intake.intakePneumaticV(0);
    intake.hoard();
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    pros::delay(300);
    //score middle goal
    chassis.turnToPoint(-11, 60.75, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .pidSelector = 2});
    chassis.moveToPoint(-11, 60.75, 2000, {.forwards = false, .minSpeed = 20});
    matchload.matchloadV(0);
    //intake.moveBottomIntake(-50);
    intake.moveMiddleIntake(-250);
    intake.moveTopIntake(-350);
    chassis.waitUntil(12);
    intake.intakeOutAuton();
    pros::delay(1200);
    //wing long goal
    chassis.moveToPoint(-34, 34, 1500, {.minSpeed = 40, .earlyExitRange = 3});
    intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(-34.75, 56, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(-36.5, 56, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 2});
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
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

void leftSevenLong() {
    chassis.setPose(-15.5, 23, 347.6);
    intake.hoard();
    chassis.moveToPoint(-23.5, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(-46.75, 23, 2000, {.minSpeed = 10});
    chassis.moveToPoint(-46.75, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.turnToPoint(-47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(-47.75, 11.75, 950, {.minSpeed = 50, .clampDistance = false});
    intake.hoard();
    pros::delay(950);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(-48, 44, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    chassis.waitUntil(18);
    intake.moveBottomIntake(-200);
    pros::delay(100);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(-37, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(-37.5, 57, 1200, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
}

void rightFourLongThreeLow() {
    chassis.setPose(16.875, 20, 90);
    chassis.moveToPoint(47.2, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11.75, 1500, {.minSpeed = 20, .earlyExitRange = 1.5});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11.75, 1050, {.minSpeed = 50, .clampDistance = false});
    pros::delay(750);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1900, {.forwards = false, .minSpeed = 45, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(775);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    //grab 3 stack
    chassis.turnToPoint(23.5, 48, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.moveToPoint(23.5, 48, 2000, {.minSpeed = 10, .earlyExitRange = 1});
    intake.intakePneumaticV(0);
    intake.moveBottomIntake(600);
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    pros::delay(300);
    //score low goal
    chassis.turnToPoint(11.75, 58.75, 2000, {.minSpeed = 5, .shortTurn = true});
    chassis.moveToPoint(11.75, 58.75, 2000, {.minSpeed = 10});
    matchload.matchloadV(0);
    intake.stopIntake();
    pros::delay(550);
    intakeLift.intakeLiftV(1);
    intake.outtakeAuton();
    pros::delay(1200);
    //wing long goal
    chassis.moveToPoint(32.75, 34, 1500, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3});
    intakeLift.intakeLiftV(0);
    intake.moveBottomIntake(-30);
    chassis.turnToPoint(31.5, 56, 2000, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    intake.stopIntake();
    chassis.moveToPoint(34.5, 56, 1500, {.minSpeed = 60, .earlyExitRange = 2});
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

void rightSevenLong() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    chassis.moveToPoint(23.5, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(11);
    matchload.matchloadV(1);
    //grab 3 stack
    chassis.turnToPoint(46.75, 23, 2000, {.minSpeed = 10});
    chassis.moveToPoint(46.75, 23, 2000, {.minSpeed = 40, .earlyExitRange = 5});
    chassis.turnToPoint(47.75, 11.75, 800, {.minSpeed = 5, .earlyExitRange = 3, .shortTurn = true});
    //matchload #1
    chassis.moveToPoint(47.75, 11.75, 950, {.minSpeed = 50, .clampDistance = false});
    intake.hoard();
    pros::delay(950);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 44, 2000, {.forwards = false, .minSpeed = 60, .clampDistance = false});
    chassis.waitUntil(18);
    intake.moveBottomIntake(-200);
    pros::delay(100);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1400);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    matchload.matchloadV(0);
    intake.stopIntake();
    //wing long goal
    chassis.moveToPoint(59, 36, 1500, {.minSpeed = 65, .earlyExitRange = 2, .pidSelector = 1});
    chassis.moveToPoint(58.5, 57, 1200, {.forwards = false, .minSpeed = 40, .earlyExitRange = 3, .pidSelector = 1,.clampDistance = false});
    intake.intakePneumaticV(1);
    chassis.turnToHeading(210, 15000, {.minSpeed = 30});
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

void rightSixLongThreeMiddle() {
    chassis.setPose(15.5, 23, 12.4);
    intake.hoard();
    //grab 3 stack
    chassis.moveToPoint(23, 46.5, 2000, {.minSpeed = 65, .earlyExitRange = 2});
    chassis.waitUntil(10.5);
    matchload.matchloadV(1);
    //grab balls under goal
    chassis.moveToPoint(41.5, 63.25, 2000, {.maxSpeed = 110, .minSpeed = 10, .earlyExitRange = 1.5, .pidSelector = 1});
    pros::delay(150);
    matchload.matchloadV(0);
    pros::delay(450);
    matchload.matchloadV(1);
    chassis.turnToHeading(90, 1000, {.minSpeed = 20});
}

void rightThreeGoal() {
    chassis.setPose(16.875, 20, 90);
    chassis.moveToPoint(46.6, 20, 1500, {.minSpeed = 10, .earlyExitRange = 1});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11.75, 1500, {.minSpeed = 25, .earlyExitRange = 1.5});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11.75, 825, {.minSpeed = 50, .clampDistance = false});
    pros::delay(750);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1900, {.forwards = false, .minSpeed = 45, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(825);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    chassis.turnToPoint(23.5, 48, 1500, {.minSpeed = 45, .earlyExitRange = 5});
    chassis.moveToPoint(23.5, 48, 2000, {.minSpeed = 30, .earlyExitRange = 1.5});
    intake.intakePneumaticV(0);
    intake.moveBottomIntake(600);
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    pros::delay(300);
    //score low goal
    chassis.turnToPoint(12.25, 58.25, 1500, {.minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(12.25, 58.25, 2000, {.minSpeed = 10});
    matchload.matchloadV(0);
    intake.stopIntake();
    pros::delay(500);
   // intakeLift.intakeLiftV(1);
    intake.outtakeAuton();
    pros::delay(1200);
    chassis.moveToPoint(23.5, 48, 1500, {.forwards = false, .minSpeed = 20, .earlyExitRange = 2});
    //intakeLift.intakeLiftV(0);
    intake.hoard();
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
    chassis.turnToPoint(-11, 60.75, 1500, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-11, 60.75, 2000, {.forwards = false, .minSpeed = 30});
    //chassis.swingToHeading(225, DriveSide::RIGHT, 1500,{.minSpeed = 40});
    intake.moveBottomIntake(-50);
    intake.moveMiddleIntake(-200);
    intake.moveTopIntake(-300);
    pros::delay(400);
    //intake.intakeOutAuton();
    intake.middleGoal();
    pros::delay(1000);
    matchload.matchloadV(0);
    chassis.moveToPoint(-18, 53, 1500, {.minSpeed = 30, .earlyExitRange = 2});
    chassis.waitUntilDone();
    descore.descoreV(1);
    pros::delay(150);
    chassis.moveToPoint(-13, 60.75, 2000, {.forwards = false, .minSpeed = 40});


}

void soloWinPoint() {
    chassis.setPose(16.875, 20, 90);
    chassis.moveToPoint(47.2, 20, 1500, {.minSpeed = 20, .earlyExitRange = 2});
    matchload.matchloadV(1);
    chassis.turnToPoint(47.8, 11.75, 1500, {.minSpeed = 20, .earlyExitRange = 1.5});
    intake.hoard();
    //matchload #1
    chassis.moveToPoint(47.8, 11.75, 825, {.minSpeed = 50, .clampDistance = false});
    pros::delay(775);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    //long goal #1
    chassis.moveToPoint(48, 43.95, 1900, {.forwards = false, .minSpeed = 45, .clampDistance = false});
    chassis.waitUntil(24.75);
    intake.intakePneumaticV(1);
    matchload.matchloadV(0);
    intake.longGoal();
    pros::delay(825);
    chassis.resetPositionLeft();
    chassis.resetPositionFront();
    intake.stopIntake();
    chassis.turnToPoint(23.5, 47.75, 1500, {.minSpeed = 35, .earlyExitRange = 5});
    //three ball stack #1
    chassis.moveToPoint(23.5, 47.75, 2000, {.minSpeed = 20, .earlyExitRange = 2});
    intake.intakePneumaticV(0);
    intake.hoard();
    chassis.waitUntil(3.5);
    matchload.matchloadV(1);
    pros::delay(300);
    matchload.matchloadV(0);
    //three ball stack #2
    chassis.moveToPoint(-22.5, 48.4, 1800, {.minSpeed = 15, .earlyExitRange = 1,.pidSelector = 1});
    chassis.waitUntil(25.75);
    matchload.matchloadV(1);
    chassis.turnToPoint(-46.75, 31, 1100, {.minSpeed = 15, .earlyExitRange = 1, .shortTurn = true});
    chassis.moveToPoint(-46.75, 31, 2000, {.minSpeed = 30, .earlyExitRange = 1.5, .clampDistance = false});
    chassis.turnToPoint(-47.5, 44.5, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});
    //long goal #2
    chassis.moveToPoint(-47.5, 44.5, 2000, {.forwards = false, .minSpeed = 45, .clampDistance = false});
    chassis.waitUntil(6.5);
    intake.intakePneumaticV(1);
    intake.longGoal();
    pros::delay(1200);
    intake.intakePneumaticV(0);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.turnToPoint(-47.25, 10, 1500, {.minSpeed = 30, .earlyExitRange = 4, .shortTurn = true});
    intake.intakePneumaticV(0);
    //matchload #2
    chassis.moveToPoint(-47.25, 10, 1300, {.minSpeed = 45, .clampDistance = false});
    pros::delay(1300);
    chassis.resetPositionRight();
    chassis.resetPositionFront();
    chassis.moveToPoint(-47.25, 24, 2000, {.forwards = false, .minSpeed = 30, .earlyExitRange = 1});
    chassis.turnToPoint(-11, 61, 800, {.forwards = false, .minSpeed = 5, .earlyExitRange = 1, .shortTurn = true});
    //middle goal
    chassis.moveToPoint(-11, 61, 1500, {.forwards = false, .minSpeed = 45, .earlyExitRange = 1, .clampDistance = false});
    intake.moveBottomIntake(0);
    intake.moveMiddleIntake(-300);
    intake.moveTopIntake(-450);
    chassis.waitUntil(43);
    //intake.intakeOutAutonSlow();
    intake.intakeOutAuton();
}

void skills() {
    // park zone balls
    chassis.setPose(0, 0, 180);
    intake.hoard();
    chassis.setDrive(12000,12000);
    pros::delay(600);
    intakeLift.intakeLiftV(1);
    chassis.wiggle(3);

   /* // moving back
    chassis.setDrive(-60,-60);
    pros::delay(1000);
    chassis.turnToHeading(0, 500);
    
    //reset
    chassis.resetPositionLeft();
    chassis.resetPositionFront();

    chassis.turnToPoint(-13, -13, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-13, -13, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});

    chassis.turnToPoint(-18, -18, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-18, -18, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2});

    matchload.matchloadV(1);
    pros::delay(300);
    
    chassis.moveToPoint(-11, -11.25, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});
    intake.intakeOutAutonSlow();
    pros::delay(1200);

    intake.hoard();
    //chassis.turnToPoint(-48, -48, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-48, -48, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2});

    chassis.turnToPoint(-48, -57, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2, .shortTurn = true});
    chassis.moveToPoint(-48, -57, 2000, {.forwards = true, .minSpeed = 10, .earlyExitRange = 2});

    chassis.moveToPoint(-52, -48, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});

    chassis.turnToPoint(-52, 24, 2000, {.forwards = false, .minSpeed = 10, .earlyExitRange = 2});*/

}