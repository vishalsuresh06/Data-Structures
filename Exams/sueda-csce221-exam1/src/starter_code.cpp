#include <iostream>
#include <utility>
#include "Planet.h"
#include "Pointer.h"
// If you see red squiggles under the includes, do not worry
// As long as you can run in terminal locally or gradescope, you are fine

using namespace std;

/*
    You can assume this is the struct of Planet type. (DO NOT UNCOMMENT)

    struct Planet {
        private:
            double volume;
            double density;

        public:
            Planet(double v, double d): volume(v), density(d) {}
            double getVolume() { return volume; }
            double getDensity() { return density; }
    };

    Pointer wrapper class is for testing reasons only - it works like a normal pointer.
    Can be used like any normal pointer, 
    i.e. Planet* planet = new Planet(1, 2); is the same as Pointer<Planet> planet = new Planet(1, 2);

    #### INSTRUCTIONS ####

    - WRITE code in the function below where it says TODO.
    - FIND the total mass of all of the Planet objects in the array.
    - CALCULATE the mass of a given planet with the formula:
    
            mass = volume * density

    - RETURN the total mass of all of the Planet objects in the array.

    You cannot use [] to access an element of the array as in a vector, you must use the pointer you are given.
    You are given a pointer to an array of Planets, and the size of the array
*/

double find_planets_mass(Pointer<Planet> arr, size_t n) {
    /* TODO: WRITE YOUR CODE HERE */
    double sum = 0;
    for (size_t i = 0;i < n;++i) {
        sum+= (*arr).getDensity() * (*arr).getVolume();
        arr+=1;
    }
    return sum; // update with answer
}