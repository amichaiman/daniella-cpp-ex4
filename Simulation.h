/*
 * Simulation.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "HockeyTeam.h"
#include "Field.h"

class Simulation {

public:
    bool config(char *filename);
    bool init(char *filename);
    void run();

private:
    HockeyTeam hockeyTeam; // class Simulation contains HockeyTeam Object as a data type
    Field field; // class Simulation contains Field Object as a data type
    int numOfMoves;
};


#endif /* SIMULATION_H_ */
