
#include <cassert>
#include <iostream>

#include "PositionReader.h"

class PositionReaderTests {
public:
	static void test1() {
		PositionReader reader("sample.dat");
		while(true) {
			std::unique_ptr<Position> pos = reader.next();
			if(pos == NULL) {
				break;
			}
			std::cout<<*pos<<std::endl;
		}
	}
};
