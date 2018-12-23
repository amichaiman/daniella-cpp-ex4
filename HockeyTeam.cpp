/*
 * HockeyTeam.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include <iomanip>      // std::setprecision
#include <climits>
#include <iostream>
#include "HockeyTeam.h"
#include "Rules.h"
//I am using the default copy c'tor and the default operator=

bool HockeyTeam::setNumOfPlayers(int numOfPlayers) {
    if (numOfPlayers < Rules::MIN_NUM_OF_PLAYERS || numOfPlayers > Rules::MAX_NUM_OF_PLAYERS) {
        return false;
    }
    HockeyTeam::numOfPlayers = numOfPlayers;
    return true;
}


void HockeyTeam::addPlayer(Player *player) {
    players.insert(player);
}

void HockeyTeam::computeGlobalBest() {
    double shortestRoute = INT_MAX;
    double curRoute;
    for (int i=0; i<numOfPlayers; i++){
        curRoute = players.getPlayerById(i)->getCur().computeDistance(destination);
        if (curRoute < shortestRoute){
            shortestRoute = curRoute;
            globalBest = players.getPlayerById(i)->getCur();
        }
    }
}


void HockeyTeam::setDestination(const Location &destination) {
    HockeyTeam::destination = destination;
}

const Location &HockeyTeam::getDestination() const{
    return destination;
}

void HockeyTeam::update() {
    for (int i=0; i<numOfPlayers; i++){
        players.getPlayerById(i)->update(globalBest);
    }
}

int HockeyTeam::getNumOfPlayers() const {
    return numOfPlayers;
}

Player *HockeyTeam::getPlayer(int i) const{
    return players.getPlayerById(i);
}
bool HockeyTeam::hasPlayer(const Player *k, const Location &x) const{
	return k->getCur().getX() >= x.getX() && k->getCur().getX() < x.getX() + 1 && k->getCur().getY() >= x.getY() && k->getCur().getY() < x.getY() + 1; //
} // I receive a player, and a location, and I want to check if the player is now at this location at the new iteration.
// so I check this player's current location (cur), and if it is equal to the x,y location values,
//then I'll update the [i][j]++ cell of the field

void HockeyTeam::printPlayersLocations()const{
	for (int i=0; i<numOfPlayers;i++){
		std::cout << fixed << std::setprecision(2) << *players.getPlayerById(i);
		if(i!= numOfPlayers-1) {
            std::cout<<endl;
		}
	}

}
/*
printTwo(Location x);
	x*=100;
	x=(round(x)/100);
	return x;
*/

HockeyTeam::~HockeyTeam(){ }

