
#include "include.h"

class Angle {
public:
    int id;
    double angle;
    bool start;
    
    Angle(int id, double angle, bool start) {
        this->id = id;
        this->angle = angle;
        this->start = start;
    }
    
    bool operator <(const Angle& x) const {
        return this->angle < x.angle;
    }
};

class SinglePivotMethod {
private:
	vector<Position>& posList;
	
	const double PI;
	
public:
	SinglePivotMethod(vector<Position>& posList)
	: posList(posList), PI(3.14159265) {
	}
	
	int process(Position pivot, double radius) {
	    vector<Angle> aiList;
	    size_t sz = posList.size();
	    
	    for(size_t i=0; i<sz; i++) {
	        Position &pos = posList[i];
		    double d = Distance::dist(pivot, pos);
		    //cout<<"distance "<<d<<endl;
		    if(d >= 2*radius || d == 0.0) {
			    continue;
		    }
		
		    double mid;
		    double x = pivot.getX() - pos.getX();
		    double y = pivot.getY() - pos.getY();
		    if(pivot.getX() != pos.getX()) {
			    mid = atan(y/x);
			    if(x<0) {
			        mid += PI;
			    }
		    } else if(pivot.getX() > pos.getX()) {
			    mid = 3*PI/2.0;
		    } else {
			    mid = PI/2.0;
		    }
		    //cout<<"radius "<<d/(2.0*radius)<<endl;
		    double delta = acos(d/(2.0*radius));
		    //cout<<"angle "<<mid<<" "<<delta<<endl;
		    
		    Angle start(i, mid - delta, true);
		    Angle end(i, mid + delta, false);
		    aiList.push_back(start);
		    aiList.push_back(end);
	    }
	    
		return getMaxOverlap(aiList) + 1;
		//return 0;
	}
	
	int getMaxOverlap(vector<Angle>& aiList) {
	    sort(aiList.begin(), aiList.end());
		int listSz = aiList.size();
		int count = 0, ans = 0;
		
		for(int i=0; i<listSz; i++) {
		    Angle &x = aiList[i];
		    if(x.start) {
		        count++;
		    } else {
		        count--;
		    }
		    if(ans < count) {
		        ans = count;
		    }
		}
		return ans;
	}
	
	int getMaxCountUptoRadius(double r) {
		size_t sz = posList.size();
		int ans = 0;
		for(size_t i=0; i<sz; i++) {
			int count = process(posList[i], r);
			if(ans < count) {
			    ans = count;
			}
		}
		return ans;
	}
};


