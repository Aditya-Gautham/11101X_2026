#pragma once

#include "api.h"

class Intake {
    public:
        //constructor
        Intake(pros::Motor& bottomMotor, pros::Motor& middleMotor, pros::Motor& topMotor, pros::Optical colorSensor_, pros::adi::DigitalOut intakePneumatic_);

        //initialize
        void calibrate(bool red);

        //intake Motors (store as references to avoid copying PROS objects)
        pros::Motor& bottomIntakeMotor;
        pros::Motor& middleIntakeMotor;
        pros::Motor& topIntakeMotor;

        //color sensor
        pros::Optical colorSensor;

        //color sort pneumatic
        pros::adi::DigitalOut intakePneumatic;

        //intake Functions
        void moveBottomIntake(double velocity);

        void moveMiddleIntake(double velocity);

        void moveTopIntake(double velocity);

        void hoard();

        void outtake();

        void middleGoal();

        void longGoal();

        void stopIntake();

        void intakeOutAuton();

        void outtakeAuton();

        void skillsMiddleGoalDriver();

        void intakeOutSkillsSuperSlow();

        void outtakeForSkillsMiddleGoal();

        void longGoalDriverSkills();
        
        void intakeOutSkills();

        void intakeOutSkillsSlow();

        void outtakeAutonSkillsTop();

        void outtakeAutonSkillsSlow();
        
        void intakeOutAutonSWP();

        void intakeOutAutonSlow();

        void intakeOutSkills2();

        void middleGoalSplit();

        void outtakeAutonSkills();

        void outtakeSkills();

        void setHold();
        
        void setCoast();

        //intake jam functions

        void intakeJam(bool async);

        // Jam tracking functions (for extending intake time in auton)
        void startJamTracking(); // Start tracking jams for current section
        void stopJamTracking();  // Stop tracking jams
        void resetJamCount();    // Reset jam counter
        int getJamCount();       // Get number of jams that occurred
        int getJamDelay(int baseDelay); // Get extended delay based on jam count (adds 200ms per jam)

        //color sort functions

        bool colorDetected(bool red);

        void redColorSort();

        static int redColorSortTask();

        void blueColorSort();

        static int blueColorSortTask();

        //intake pneumatic functions

        void intakePneumaticV(int value);

        void intakePneumaticChange();

        //intake variables

        bool colorSortActive = true;

        bool intakePneumaticActive = true;

        bool driverControl = false;

        double desiredBottomVelocity = 0;

        // Jam tracking variables
        int jamCount = 0;
        bool jamTrackingActive = false;
};
