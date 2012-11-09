
#include <cassert>
#include <iostream>

#include "PositionIdAgent.h"
#include "Position.h"

class PositionIdAgentTests {
public:
	static void test1() {
		Position *A = new Position(10, 20);
		Position *B = new Position(30, 50);

		assert(PositionIdAgent::getPositionById(A->getId()) == A);
		assert(PositionIdAgent::getPositionById(B->getId()) == B);
	}
};
