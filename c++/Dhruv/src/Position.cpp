
#include "Position.h"
#include "PositionIdAgent.h"

Position::Position(const Coordinate xPos, const Coordinate yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	
	this->id = PositionIdAgent::getId(this);
}

PositionId const Position::getId() {
	return id;
}

std::ostream& operator <<(std::ostream& out, const Position& pos) {
	out<<"("<<pos.xPos<<", "<<pos.yPos<<")";
	return out;
}
