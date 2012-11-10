
#include <memory>

#include "PositionPairWriter.h"

PositionPairWriter::PositionPairWriter(std::string filePath) {
	this->outputFilePath = filePath;
	fout.open(outputFilePath.c_str(), std::ios::out);
}

PositionPairWriter::~PositionPairWriter() {
	fout.close();
}

void PositionPairWriter::read(PositionReader& reader) {
	while(true) {
		std::unique_ptr<Position> pos = reader.next();
		if(pos == NULL) {
			break;
		}
		posList.push_back(std::move(pos));
	}
}

void PositionPairWriter::clear() {
	posList.clear();
}

void PositionPairWriter::write(const std::unique_ptr<Position>& p1, const std::unique_ptr<Position>& p2) {
	fout<<*p1<<" "<<*p2<<std::endl;
}

void PositionPairWriter::writeAll() {
	typedef std::vector<std::unique_ptr<Position> >::iterator it_type;
	for(it_type i = posList.begin(); i != posList.end(); i++) {
		for(it_type j = i + 1; j != posList.end(); j++) {
			write(std::move(*i), std::move(*j));
		}
	}
}
