
#include "Position.h"
#include "PositionIdAgent.h"

Position::Position(Coordinate xPos, Coordinate yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	
	this->id = PositionIdAgent::getId(this);
}

PositionId Position::getId() {
	return id;
}

std::ostream& operator <<(std::ostream& out, Position& pos) {
	out<<"("<<pos.xPos<<", "<<pos.yPos<<")";
}
