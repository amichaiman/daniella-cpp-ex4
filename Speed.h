/*
 * Speed.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef SPEED_H_
#define SPEED_H_
class Location;

class Speed {
public:
    Speed& operator=(const Speed& rhs);
    Speed operator*(double n);
    Speed operator+(const Location& rhs);

	double getX() const {
		return x;
	}

	void setX(double x) {
		this->x = x;
	}

	double getY() const {
		return y;
	}

	void setY(double y) {
		this->y = y;
	}

private:
    double x,y;
};



#endif /* SPEED_H_ */
