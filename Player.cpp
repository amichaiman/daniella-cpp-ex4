/*
 * Player.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include "Player.h"
#include "Rules.h"
#include <cstdlib>
#include <cstdio>

inline void invalidInput(int exitCode) {
    std::cerr << "ERROR: Invalid input." << std::endl;
    exit(exitCode);
}
Player::Player(Location location, Speed speed, int id) //c'tor of player
:personalBest(Location()), cur(location), speed(speed), id(id){
    personalBest = cur;
}
// add - first parameter is the type of player, G, D, F


Player::Player():personalBest(Location()), cur(Location()), speed(Speed()), id(-1) { //empty c'tor
}

int Player::getId()const { //player's id
    return id;
}

Player &Player::operator=(const Player &rhs) {
    if (this == &rhs){
        return *this;
    }
    personalBest = rhs.getPersonalBest();
    speed = rhs.getSpeed();
    cur = rhs.getCur();
    id = rhs.getId();
    return *this;
}

const Location &Player::getCur() const {
    return cur;
}

const Location &Player::getPersonalBest() const {
    return personalBest;
}

const Speed &Player::getSpeed() const {
    return speed;
}

//    speed.operator*(0.25);
void Player::update(Location globalBest) {
    Speed speedTplusOne = speed*0.25*getAlpha() + (globalBest-cur)*randZeroToOne()*getBeta() + (personalBest-cur)*randZeroToOne()*getGama();
    cur = cur+speed; //cur location is calculated according to players speed
    if (cur.getX() < Rules::MIN_X_SIZE) {
        cur.setX(Rules::MIN_X_SIZE);
    } else if (cur.getX() > Rules::MAX_X_SIZE) {
        cur.setX(Rules::MAX_X_SIZE);
    }
    if (cur.getY() < Rules::MIN_Y_SIZE) {
        cur.setY(Rules::MIN_Y_SIZE);
    } else if (cur.getY() > Rules::MAX_Y_SIZE) {
        cur.setY(Rules::MAX_Y_SIZE);
    }
    speed = speedTplusOne; //speed updates according to formula above
}

double Player::randZeroToOne() {
    return static_cast<double>(rand())/RAND_MAX;
}
std::ostream& operator<<(std::ostream& cout, const Player &p){
	cout<<p.cur.getX()<<" "<<p.cur.getY();
	return cout;
}
std::istream& operator>>(std::istream& cin, Player &p){
	double temp1,temp2;
	cin>>temp1>>temp2;
	p.cur.setX(temp1);
	p.cur.setY(temp2);
	cin>>temp1>>temp2;
	char c;
	if ((c= static_cast<char>(cin.get())) != '\n' && c != EOF) {
        invalidInput(4);
    }
	p.speed.setX(temp1);
	p.speed.setY(temp2);
	return cin;
}

void Player::setId(int id) {
    Player::id = id;
}

bool Player::operator>(const Player &rhs) const {
    return id > rhs.getId();
}

bool Player::operator<(const Player &rhs) const {
    return id < rhs.getId();
}

Player::~Player() {

}


