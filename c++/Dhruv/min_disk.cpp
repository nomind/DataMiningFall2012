#include <cassert>
#include <fstream>

#include "src/BruteForce.cpp"
#include "src/SinglePivotMethod.cpp"

using namespace std;

int main(int argc, char **argv) {
	/*RandomDataGenerator rdg(50);
	vector<Position> posList;
	rdg.generate(posList);*/
	
	/*for(size_t i=0; i<posList.size(); i++) {
		cout<<posList[i]<<endl;
	}*/
	
	/*Position center(0, 0);
	Circle cir(center, 1000000);
	*/
	/*Position A(0, 0);
	posList.push_back(A);
	Position B(5, 5);
	posList.push_back(B);
	Position C(0, 10);
	posList.push_back(C);
	*/
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
	
	//cout<<"size "<<posList.size()<<endl;
	
	/*{
	    BruteForce bf(posList);
	    int n = posList.size();
	    double rMin = 1.0, rMax = 2.0;
	    while(true) {
	        int count = bf.getMaxCountUptoRadius(rMax);
	        //cout<<count<<endl;
	        if(count >= n) {
	            break;
	        }
	        rMin = rMax;
	        rMax = 2*rMax;
	        //cout<<rMin<<" "<<rMax<<endl;
	    }
	    cout<<rMin<<" "<<rMax<<endl;
	    
	    while(rMax - rMin >= 0.1) {
	        double m = (rMin + rMax)/2.0;
	        int count = bf.getMaxCountUptoRadius(m);
	        if(count < n) {
	            rMin = m;
	        } else {
	            rMax = m;
	        }
	    }
	    cout<<rMin<<" "<<rMax<<endl;
	}*/
	
	SinglePivotMethod engine(posList);
	int n = posList.size();
    double rMin = 1.0, rMax = 2.0;
    string st;
    while(true) {
        int count = engine.getMaxCountUptoRadius(rMax);
        //cout<<count<<" "<<n<<endl;
        if(count >= n) {
            break;
        }
        rMin = rMax;
        rMax = 2*rMax;
        //cout<<rMin<<" "<<rMax<<endl;
        //cin>>st;
    }
    //cout<<rMin<<" "<<rMax<<endl;
    
    while(rMax - rMin >= 0.1) {
        double m = (rMin + rMax)/2.0;
        int count = engine.getMaxCountUptoRadius(m);
        if(count < n) {
            rMin = m;
        } else {
            rMax = m;
        }
    }
    cout<<rMin<<" "<<rMax<<endl;
    
	return 0;
}

