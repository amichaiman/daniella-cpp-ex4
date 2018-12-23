/*
 * Speed.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include "Speed.h"
#include "Location.h"

Speed &Speed::operator=(const Speed &rhs) {
    if (this == &rhs) {
        return *this;
    }
    x = rhs.x;
    y = rhs.y;
    return *this;
}

Speed Speed::operator*(double n) {
    Speed newSpeed;
    newSpeed.x = x*n;
    newSpeed.y = y*n;
    return newSpeed;
}

Speed Speed::operator+(const Location &rhs) {
    Speed newSpeed;
    newSpeed.x = x+rhs.getX();
    newSpeed.y = y+rhs.getY();
    return newSpeed;
}
