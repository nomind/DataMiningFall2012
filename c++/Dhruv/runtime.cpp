#include <cassert>
#include <fstream>

#include "src/BruteForce.cpp"
#include "src/SinglePivotMethod.cpp"

using namespace std;

int main(int argc, char **argv) {
	RandomDataGenerator rdg(500);
	vector<Position> posList;
	rdg.generate(posList);
	
	
	{
	    BruteForce bf(posList);
	    //int n = posList.size();
	    double dia = bf.getDiameter();
	    cout<<dia<<endl;
	}
	
	/*{
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
        //cout<<n<<endl;
        while(rMax - rMin >= 0.1) {
            double m = (rMin + rMax)/2.0;
            int count = engine.getMaxCountUptoRadius(m);
            if(count < n) {
                rMin = m;
            } else {
                rMax = m;
            }
            //cout<<count<<" "<<n<<" "<<rMin<<" "<<rMax<<endl;
        }
        //cout<<rMin<<" "<<rMax<<endl;
        cout<<2.0*rMax<<endl;
    }*/
    
	return 0;
}

