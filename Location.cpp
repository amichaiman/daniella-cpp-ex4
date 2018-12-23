/*
 * Location.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include <cmath>
#include "Location.h"
#include "Speed.h"

Location::Location(): x(0), y(0){} //location c'tor
Location::Location(double a, double b): x(a), y(b){}
Location &Location::operator=(const Location &rhs) {
    if (this == &rhs) {
        return *this;
    }
    x = rhs.x;
    y = rhs.y;
    return *this;
}

inline double square(double n) {
    return n*n;
}

double Location::computeDistance(const Location &location) const { //Pythagoras equation for distance measure
    return (sqrt(square(x-location.x) + square(y-location.y)));
}

Location Location::operator-(const Location &rhs) {
    Location newLocation;
    newLocation.x = x-rhs.x;
    newLocation.y = y-rhs.y;
    return newLocation;
}

Location Location::operator*(double n) {
    Location newLocation;
    newLocation.x = x*n;
    newLocation.y = y*n;
    return newLocation;
}

Location Location::operator+(const Speed &rhs) {
    Location newLocation;
    newLocation.x = x+rhs.getX();
    newLocation.y = y+rhs.getY();

    return newLocation;
}

