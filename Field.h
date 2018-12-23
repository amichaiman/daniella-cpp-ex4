/*
 * Field.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef FIELD_H_
#define FIELD_H_


#include "Cell.h"
#include "Rules.h"
#include "HockeyTeam.h"

class Field {
private:
    Cell field[Rules::MAX_X_SIZE][Rules::MAX_Y_SIZE];
public:
    bool destinationReached(const Location &destination) const;
    void update(HockeyTeam &team);
};


#endif /* FIELD_H_ */
