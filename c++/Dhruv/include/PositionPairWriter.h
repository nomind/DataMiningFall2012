
#ifndef POSITION_PAIR_WRITER_H
#define POSITION_PAIR_WRITER_H

#include <fstream>
#include <string>
#include <vector>

#include "Position.h"
#include "PositionReader.h"

class PositionPairWriter {
private:
	std::ofstream fout;
	std::string outputFilePath;
	std::vector<std::unique_ptr<Position> > posList;
	
public:
	PositionPairWriter(std::string filePath);
	~PositionPairWriter();
	
	void clear();
	void read(PositionReader& reader);
	void write(const std::unique_ptr<Position>& p1, const std::unique_ptr<Position>& p2);
	void writeAll();
};

#endif
