
#ifndef POSITION_H
#define POSITION_H

#include <ostream>

#include "types.h"

class Position {
private:
	Coordinate xPos;
	Coordinate yPos;
	
	PositionId id;
	
public:
	Position(Coordinate xPos, Coordinate yPos);
	PositionId getId();
	
	friend std::ostream& operator <<(std::ostream& out, Position& pos);
};

#endif
