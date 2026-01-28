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
 
        //descore variables
        bool descoreOut = false;
};