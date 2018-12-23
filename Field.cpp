/*
 * Field.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include "Field.h"
#include <cmath>


bool Field::destinationReached(const Location &destination )const { // when the destination x and y valus are not zero
 int x=(field[static_cast<int>(floor(destination.getX()))][static_cast<int>(floor(destination.getY()))]).getNumOfPlayers();
 return x!=0? true:false;


}
void Field::update(HockeyTeam &team) { //update the number of players in each cell after each iteration
    for (int i=Rules::MIN_X_SIZE; i<Rules::MAX_X_SIZE; i++) {
        for (int j=Rules::MIN_X_SIZE; j<Rules::MAX_X_SIZE; j++){
            field[i][j].setNumOfPlayers(0); // after every iteration, I want the field to be set to zero
            for (int k=0; k<team.getNumOfPlayers(); k++) { // go over the number of players in the team
            	Player *x = team.getPlayer(k); // id of specific player received
                if (team.hasPlayer(x, Location(i, j))) { // this function should check if there is a player with given id at every ij cell
                    field[i][j]++;
                }
            }
        }
    }
}
