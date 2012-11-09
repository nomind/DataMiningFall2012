
#include <cstddef>

#include "PositionIdAgent.h"

PositionId PositionIdAgent::id = 1;
std::map<PositionId, Position*> PositionIdAgent::posIdMap;


PositionId PositionIdAgent::getId(Position* pos) {
	PositionId curId = id++;
	
	posIdMap[curId] = pos;
	return curId;
}

Position* PositionIdAgent::getPositionById(PositionId id) {
	std::map<PositionId, Position*>::iterator it;
	
	it = posIdMap.find(id);
	if(it == posIdMap.end()) {
		return NULL;
	}
	
	return it->second;
}
