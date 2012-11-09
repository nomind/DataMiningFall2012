
#include <sstream>

#include "PositionReader.h"
#include "types.h"

PositionReader::PositionReader(std::string filePath) {
	PositionReader::maxLineLen = 1000;
	
	this->filePath = filePath;
	this->fin.open(filePath.c_str(), std::ios::in);
}

Position* PositionReader::next() {
	char str[maxLineLen];
	fin.getline(str, maxLineLen);
	if(fin.is_open() && (!fin.eof())) {
		std::stringstream ss;
		Coordinate xPos, yPos;
		
		ss<<str;
		ss>>xPos>>yPos;
		Position *pos = new Position(xPos, yPos);
		return pos;
	}
	if(fin.is_open()) {
		fin.close();
	}
	return NULL;
}
