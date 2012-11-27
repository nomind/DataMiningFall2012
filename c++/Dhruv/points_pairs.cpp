#include <cassert>
#include <fstream>

#include "src/BruteForce.cpp"
#include "src/SinglePivotMethod.cpp"

using namespace std;

int main(int argc, char **argv) {
    //assert(argc > 1);
	char *filename = "../../data/points/1.dat";
	
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
	vector<double> list;
	for(int i=0; i<sz; i++) {
	    for(int j=i+1; j<sz; j++) {
	        double d = Distance::dist(posList[i], posList[j]);
	        list.push_back(d);
	    }
	}
	
	sort(list.begin(), list.end());
	for(int i=list.size() -1 ; i>=0; i--) {
	    printf("%.5f\n", list[i]);
	}
    return 0;	
}

