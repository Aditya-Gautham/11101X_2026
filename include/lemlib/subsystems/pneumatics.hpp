#pragma once

#include "api.h"

class Matchload {
    public:
        //constructor
        Matchload(pros::adi::DigitalOut matchLoadPneumatic);

        //matchload pneumatic
        pros::adi::DigitalOut matchLoadPneumatic;

        //matchload Functions
        void matchloadV(int value);
        void matchloadChange();
        void calibrate();
        bool matchloadValue();
 
        //matchload variables
        bool matchloadOut = false;
};

class Wing {
    public:
        //constructor
        Wing(pros::adi::DigitalOut wingPneumatic);

        //wing pneumatic
        pros::adi::DigitalOut wingPneumatic;

        //wing Functions
        void wingV(int value);
        void wingChange();
        void calibrate();
 
        //wing variables
        bool wingUp = false;
};

class Descore {
    public:
        //constructor
        Descore(pros::adi::DigitalOut descorePneumatic);

        //descore pneumatic
        pros::adi::DigitalOut descorePneumatic;

        //descore Functions
        void descoreV(int value);
        void descoreChange();
        void calibrate();
        bool descoreValue();
 
        //descore variables
        bool descoreOut = false;
};

class IntakeLift {
    public:
        //constructor
        IntakeLift(pros::adi::DigitalOut intakeLiftPneumatic);

        //intake lift pneumatic
        pros::adi::DigitalOut intakeLiftPneumatic;

        //intake lift Functions
        void intakeLiftV(int value);
        void intakeLiftChange();
        void calibrate();
        bool intakeLiftValue();
 
        //intake lift variables
        bool intakeLiftUp = false;
};