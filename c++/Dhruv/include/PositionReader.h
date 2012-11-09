
#ifndef POSITION_READER_H
#define POSITION_READER_H

#include <string>
#include <fstream>

#include "Position.h"

class PositionReader {
private:
	int maxLineLen;
	std::string filePath;
	std::ifstream fin;
	
public:
	PositionReader(std::string filePath);
	Position* next();
};

#endif
