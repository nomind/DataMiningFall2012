
#ifndef POSITION_H
#define POSITION_H

#include "include.h"
#include "types.h"

class Position {
private:
	Coordinate xPos;
	Coordinate yPos;
	
	PositionId id;
	
public:
	Position(const Coordinate xPos, const Coordinate yPos);
	PositionId const getId();
	Coordinate getX();
	Coordinate getY();
	
	friend std::ostream& operator <<(std::ostream& out, const Position& pos);
};

#endif
