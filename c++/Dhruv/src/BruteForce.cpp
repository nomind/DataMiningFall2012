
#include "include.h"

class RandomDataGenerator {
private:
	static const int maxCoord = 10000;
	int sz;

public:
	RandomDataGenerator(int sz) {
		this->sz = sz;
	}
	
	void generate(vector<Position>& posList) {
		for(int i=0; i<sz; i++) {
			Position pos(rand()%maxCoord, rand()%maxCoord);
			posList.push_back(pos);
		}
	}
};

class Distance {
public:
	static double dist(Position A, Position B) {
		double xDiff = (double)(A.getX() - B.getX());
		double yDiff = (double)(A.getY() - B.getY());
		return sqrt(xDiff*xDiff + yDiff*yDiff);
	}
};

class Circle {
private:
	Position center;
	double radius;
	int pointsInside;
	
public:
	Circle(Position center, double radius)
	: center(center) {
		this->radius = radius;
		this->pointsInside = 0;
	}
	
	double getRadius() const {
		return radius;
	}
	
	bool isInside(Position pos) {
		if(Distance::dist(pos, center) <= radius){
			return true;
		}
		return false;
	}
	
	void countPointsInside(vector<Position>& posList) {
		pointsInside = 0;
		for(size_t i=0; i<posList.size(); i++) {
			if(isInside(posList[i])) {
				pointsInside++;
			}
		}
		return;
	}
	
	int getPointsInside() {
		return pointsInside;
	}
	
	bool operator <(const Circle& o) const {
		return this->pointsInside < o.pointsInside;
	}
};

class BruteForce {
private:
	vector<Circle> cirList;
	
public:
	BruteForce(vector<Position>& posList) {
		size_t sz = posList.size();
		for(size_t i=0; i<sz; i++) {
			for(size_t j=i+1; j<sz; j++) {
				for(size_t k=j+1; k<sz; k++) {
					Circle circle = circumCircle(posList[i], posList[j], posList[k]);
					circle.countPointsInside(posList);
					cirList.push_back(circle);
				}
			}
		}
		
		sort(cirList.begin(), cirList.end());
		/*for(size_t i=0; i<cirList.size(); i++) {
			cout<<cirList[i].getRadius()<<" "<<cirList[i].getPointsInside()<<endl;
		}*/
	}
	
	int getMaxCountUptoRadius(double radius) {
		int count = 0;
		for(size_t i=0; i<cirList.size(); i++) {
			if(cirList[i].getRadius() < radius && count < cirList[i].getPointsInside()) {
				count = cirList[i].getPointsInside();
			}
		}
		return count;
	}
	
	Circle circumCircle(Position X, Position B, Position C) {
		Coordinate ax = X.getX();
		Coordinate ay = X.getY();
		
		Coordinate bx = B.getX();
		Coordinate by = B.getY();
		
		Coordinate cx = C.getX();
		Coordinate cy = C.getY();
		
		double xNum = ((ax*ax + ay*ay)*(cy - by) + (bx*bx + by*by)*(ay - cy) + (cx*cx + cy*cy)*(by - ay));
		double xDen = 2.0*((ax*(cy - by) + bx*(ay - cy) + cx*(by - ay)));
		Coordinate x = xNum/xDen;
		
		double yNum = ((ax*ax + ay*ay)*(cx - bx) + (bx*bx + by*by)*(ax - cx) + (cx*cx + cy*cy)*(bx - ax));
		double yDen = 2.0*((ay*(cx - bx) + by*(ax - cx) + cy*(bx - ax)));
		Coordinate y = yNum/yDen;
		
		Position center(x, y);
		double r = Distance::dist(center, X);
		
		Circle circle(center, r);
		
		return circle;
	}
};


