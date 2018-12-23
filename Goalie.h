//
// Created by amichai on 23/12/18.
//

#ifndef DANIELA_CPP_4_12_GOALIE_H
#define DANIELA_CPP_4_12_GOALIE_H


#include "Player.h"

class Goalie : public Player{
    virtual double getAlpha();

    virtual double getBeta();

    virtual double getGama();
};


#endif //DANIELA_CPP_4_12_GOALIE_H
