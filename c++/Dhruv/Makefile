
CC=g++
CFLAGS=-c -Wall -Iinclude -Isrc -Itests
EFLAGS=-Wall -Iinclude -Isrc -Itests

main: main.cpp PositionIdAgentTests.o PositionIdAgent.o Position.o PositionReader.o PositionReaderTests.o
	$(CC) $(EFLAGS) -o main main.cpp PositionIdAgentTests.o PositionIdAgent.o Position.o PositionReader.o PositionReaderTests.o

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
