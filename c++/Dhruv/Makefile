
CC=g++
CFLAGS=-c -Wall -Iinclude -Isrc -Itests -pedantic -std=c++0x
EFLAGS=-Wall -Iinclude -Isrc -Itests -pedantic -std=c++0x

run_tests: run_tests.cpp PositionIdAgentTests.o PositionIdAgent.o Position.o PositionReader.o PositionReaderTests.o PositionPairWriter.o
	$(CC) $(EFLAGS) -o run_tests run_tests.cpp PositionIdAgentTests.o PositionIdAgent.o Position.o PositionReader.o PositionReaderTests.o PositionPairWriter.o

PositionPairWriter.o: src/PositionPairWriter.cpp include/PositionPairWriter.h include/Position.h
	$(CC) $(CFLAGS) src/PositionPairWriter.cpp
	
PositionReaderTests.o: tests/PositionReaderTests.cpp include/PositionReader.h
	$(CC) $(CFLAGS) tests/PositionReaderTests.cpp
	
PositionReader.o: src/PositionReader.cpp include/PositionReader.h include/Position.h
	$(CC) $(CFLAGS) src/PositionReader.cpp
	
PositionIdAgentTests.o: tests/PositionIdAgentTests.cpp include/PositionIdAgent.h include/Position.h
	$(CC) $(CFLAGS) tests/PositionIdAgentTests.cpp
	
PositionIdAgent.o: src/PositionIdAgent.cpp include/PositionIdAgent.h include/Position.h
	$(CC) $(CFLAGS) src/PositionIdAgent.cpp

Position.o: src/Position.cpp include/Position.h include/PositionIdAgent.h
	$(CC) $(CFLAGS) src/Position.cpp
	
clean:
	rm *.o
