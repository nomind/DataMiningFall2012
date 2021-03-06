#include <cassert>
#include <fstream>

#include "src/BruteForce.cpp"
#include "src/SinglePivotMethod.cpp"

using namespace std;

int main(int argc, char **argv) {
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
	    //cout<<pos;
	}
	
	int sz = posList.size();
	double dia = 0.0;
	for(int i=0; i<sz; i++) {
	    for(int j=0; j<sz; j++) {
	        double d = Distance::dist(posList[i], posList[j]);
	        if(dia < d) {
	            dia = d;
	        }
	    }
	}
	
	cout<<dia<<endl;
}

