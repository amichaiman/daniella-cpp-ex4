/*
 * Player.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "Location.h"
#include "Speed.h"

class Player {
public:
    Player();
    Player(Location location, Speed speed, int id);
    Player& operator=(const Player& rhs);
    virtual ~Player();
    bool operator>(const Player& rhs) const;
    bool operator<(const Player& rhs) const;
    int getId()const;
    const Location &getCur() const;
    const Location &getPersonalBest() const;
    const Speed &getSpeed() const;
    friend std::ostream& operator<<(std::ostream& out, const Player& p);
    friend std::istream& operator>>(std::istream& cin, Player &p);
    void update(Location globalBest);
    void setId(int id);
private:
    virtual double getAlpha()=0;
    virtual double getBeta()=0;
    virtual double getGama()=0;
    Location personalBest; //player has a data member personalBest which is an instance of Location
    Location cur; //player has a data member cur which is an instance of Location
    Speed speed; //speed is an instance of Speed class
    int id;
    double randZeroToOne();
};




#endif /* PLAYER_H_ */
