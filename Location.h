/*
 * Location.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Speed;

class Location {
public:
    Location();
    Location(double x,double y);
    Location& operator=(const Location& rhs);
    Location operator-(const Location& rhs);
    Location operator+(const Speed& rhs);
    Location operator*(double n);
    double computeDistance(const Location &location) const;
    double getX() const{
    return x;
    }
    void setX(double x){
    	this->x=x;

    }
    double getY() const{
    return y;
    }
    void setY(double y){
    	this->y=y;

    }
private:
    double x,y;
};


#endif /* LOCATION_H_ */
