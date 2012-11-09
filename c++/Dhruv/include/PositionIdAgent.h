
#ifndef POSITION_ID_AGENT_H
#define POSITION_ID_AGENT_H

#include <map>

#include "Position.h"

class PositionIdAgent {
private:
	static PositionId id;
	static std::map<PositionId, Position*> posIdMap;
	
public:
	static PositionId getId(Position* pos);
	static Position* getPositionById(PositionId id);
};

#endif
