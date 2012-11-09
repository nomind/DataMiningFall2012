
#include <sstream>

#include "PositionReader.h"
#include "types.h"

PositionReader::PositionReader(const std::string filePath) {
	PositionReader::maxLineLen = 1000;
	
	this->filePath = filePath;
	this->fin.open(filePath.c_str(), std::ios::in);
}

std::unique_ptr<Position> PositionReader::next() {
	Coordinate xPos, yPos;
	fin>>xPos>>yPos;
	if(fin.is_open() && (!fin.eof())) {
		std::unique_ptr<Position> pos(new Position(xPos, yPos));
		return pos;
	}
	if(fin.is_open()) {
		fin.close();
	}
	return NULL;
}
