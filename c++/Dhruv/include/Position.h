
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
	Position(const Coordinate xPos, const Coordinate yPos);
	PositionId const getId();
	
	friend std::ostream& operator <<(std::ostream& out, const Position& pos);
};

#endif
