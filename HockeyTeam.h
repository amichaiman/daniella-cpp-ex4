/*
 * HockeyTeam.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef HOCKEYTEAM_H_
#define HOCKEYTEAM_H_

#include "Player.h"
#include "GTree.h"

class HockeyTeam {
public:
	~HockeyTeam();
    bool setNumOfPlayers(int numOfPlayers);
    void addPlayer(Player *player);
    void computeGlobalBest();
    void setDestination(const Location &destination);
    const Location & getDestination() const;
    Player * getPlayer(int i) const;
    void update();
    void printPlayersLocations()const;
    int getNumOfPlayers() const;
    bool hasPlayer(const Player *k,const Location &x ) const;
private:
    int numOfPlayers; //numOfPlayers is received from the Simulation class
    GTree<Player*> players; //array of players
    Location destination; // destination is an instance of Location Object, and it is a data member of HockeyTeam Class
    Location globalBest;// globalBest is an instance of Location Object, and it is a data member of HockeyTeam Class
};


#endif /* HOCKEYTEAM_H_ */
