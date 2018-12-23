/*
 * Cell.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#include "Cell.h"

Cell &Cell::operator++() {
    numOfPlayers++;
    return *this;
}

Cell &Cell::operator--() {
    numOfPlayers--;
    return *this;
}

const Cell Cell:: operator++(int){
	Cell temp = *this;
	numOfPlayers++;
	return temp;
}
const Cell Cell::operator--(int){
	Cell temp=*this;
	numOfPlayers--;
	return temp;
}


int Cell::getNumOfPlayers() const {
    return numOfPlayers;
}
void Cell::setNumOfPlayers(int numOfPlayers){
	this->numOfPlayers=numOfPlayers;
}
