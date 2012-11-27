#include <cassert>
#include <fstream>

#include "src/BruteForce.cpp"

using namespace std;

int main(int argc, char **argv) {
	/*RandomDataGenerator rdg(100);
	vector<Position> posList;
	rdg.generate(posList);
	
	for(size_t i=0; i<posList.size(); i++) {
		cout<<posList[i]<<endl;
	}
	
	Position center(0, 0);
	Circle cir(center, 1000000);
	
	Position A(0, 0);
	Position B(5, 5);
	Position C(0, 10);*/
	
	assert(argc > 1);
	char *filename = argv[1];
	
	ifstream fin;
	fin.open(filename, ios::in);
	vector<Position> posList;
	double x, y;
	while(!fin.eof()) {
	    fin>>x>>y;
	    Position pos(x, y);
	    posList.push_back(pos);
	    cout<<pos;
	}
	
	cout<<"size "<<posList.size()<<endl;
	
	//BruteForce bf(posList);
	//cout<<bf.getMaxCountUptoRadius(1000)<<endl;
	
	return 0;
}

