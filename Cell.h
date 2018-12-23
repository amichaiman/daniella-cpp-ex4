/*
 * Cell.h
 *
 *  Created on: Dec 9, 2018
 *      Author: test
 */

#ifndef CELL_H_
#define CELL_H_


class Cell {
public:
    Cell& operator++();
    Cell& operator--();
    const Cell operator++(int);
    const Cell operator--(int);
    int getNumOfPlayers() const;
    void setNumOfPlayers(int numOfPlayers);
private:
    int numOfPlayers;

};

#endif /* CELL_H_ */
