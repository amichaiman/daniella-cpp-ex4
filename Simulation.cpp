/*
 * Simulation.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */


#include "Simulation.h"
#include "Location.h"
#include "Speed.h"
#include "Player.h"
#include "Goalie.h"
#include "Forwards.h"
#include "Defensemen.h"
#include <fstream>
#include <iostream>

using namespace std;

inline bool fileStateIsGood(ifstream &file) {
    return !(file.fail()  || file.bad());
}
bool Simulation::config(char *filename) {
    ifstream file;

    file.open(filename, ios::in);
    if (!file.is_open()){ //if file cannot be opened, return false
        return false;
    }

    double x,y;
    file >> x >> y; //insert x and y values into destination


    hockeyTeam.setDestination(Location(x,y));

    if (!fileStateIsGood(file) || file.eof()) {
        return false;
    }

    file >> numOfMoves;
    return fileStateIsGood(file);

}

bool Simulation::init(char *filename) {
    ifstream file(filename);
    if (!file.is_open()){
        return false;
    }

    int numOfPlayers;
    file >> numOfPlayers;
	
    if (!fileStateIsGood(file) || file.eof()) {
        return false;
    }
    if (!hockeyTeam.setNumOfPlayers(numOfPlayers)){
        return false;
    }
    char typeOfPlayer;

    for (int i=0; i<numOfPlayers; i++){
        file >> typeOfPlayer;
    	Player *temp;
    	switch (typeOfPlayer) {
    	    case 'G':
    	        temp = new Goalie(); break;
            case 'F':
                temp = new Forwards(); break;
            case 'D':
                temp = new Defensemen(); break;
    	    default:
    	        return false;
    	}
        file >> *temp;
        if (!fileStateIsGood(file)){
            return false;
        }
        temp->setId(i);
        hockeyTeam.addPlayer(temp);
    }
	
    hockeyTeam.computeGlobalBest();
    return true;
}

void Simulation::run() {
    int i;
    for (i=0; i<numOfMoves; i++){
        hockeyTeam.update();
        hockeyTeam.computeGlobalBest();
        field.update(hockeyTeam);
        if (field.destinationReached(hockeyTeam.getDestination()) ) {
            break;
        }
    }
    cout << i << endl;
    hockeyTeam.printPlayersLocations();
}
