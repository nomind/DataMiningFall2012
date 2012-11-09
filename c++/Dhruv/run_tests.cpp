
#include "PositionIdAgentTests.cpp"
#include "PositionReaderTests.cpp"

#include "PositionPairWriter.h"

int main(int argc, char **argv) {
	PositionIdAgentTests::test1();
	
	PositionReaderTests::test1();
	
	PositionPairWriter writer("sample.out");
	PositionReader reader("sample.dat");
	writer.read(reader);
	writer.writeAll();
	
	return 0;
}
