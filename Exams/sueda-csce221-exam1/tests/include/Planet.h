#pragma once
#include "Monitor.h"

struct Planet {
    private:
        double volume;
        double density;

    public:
        Planet(double v=0.0, double d=0.0): volume(v), density(d) {}
        
        double getVolume() {
            Monitor::update_first();
            return volume;
        }

        double getDensity() { 
            Monitor::update_second();
            return density;
        }
};