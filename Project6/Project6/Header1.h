#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
	int X_Coordinate; 
	int Y_Cooridnate;
public:
	Point() {
		this->X_Coordinate = 0;
		this->Y_Cooridnate = 0;
	}
	Point(int x, int y) {
		this->X_Coordinate = x;
		this->Y_Cooridnate = y;

	}
	Point( const Point& p) {
		this->X_Coordinate = p.X_Coordinate;
		this->Y_Cooridnate = p.Y_Cooridnate;
	}
	int getX_Coordinate()const {
		return this->X_Coordinate;
	}
	int getY_Coordinate()const {
		return this->Y_Cooridnate;
	}
	void setX_Coordinate(int x) {
		this->X_Coordinate=x;
	}
	void setY_Coordinate(int y) {
		this->Y_Cooridnate=y;
	}

	friend ostream &operator<<(ostream& out, Point& P1);

};
ostream &operator<<(ostream & out, const Point& P1) {
	
	out << "( " << P1.getX_Coordinate() << " , " << P1.getY_Coordinate() << " )";
	return out;
}
class Line {
	Point Point_1;
	Point Point_2;
public:
	Line() {
		this->Point_1.setX_Coordinate(1);
		this->Point_1.setY_Coordinate(5);
		this->Point_2.setX_Coordinate(10);
		this->Point_2.setY_Coordinate(15);


	}
	Line(int x1, int y1, int x2, int y2) {
		this->Point_1.setX_Coordinate(x1);
		this->Point_1.setY_Coordinate(y1);
		this->Point_2.setX_Coordinate(x2);
		this->Point_2.setY_Coordinate(y2);
	}
	/*Line(const  Point& p1, const Point& p2) {
		int x1, y1, x2, y2;
		x1 = p1.getX_Coordinate();
		y1 = p1.getY_Coordinate();
		x2 = p2.getX_Coordinate();
		y2 = p2.getY_Coordinate();

		this->Point_1.setX_Coordinate(x1);
		this->Point_1.setY_Coordinate(y1);
		this->Point_2.setX_Coordinate(x2);
		this->Point_2.setY_Coordinate(y2);
		
		
		
	}*/

	Line(const Point& p1, const Point& p2) : Point_1(p1), Point_2(p2) 
	{
	  }

					float findSlope() {
						return ((static_cast<float>(Point_2.getY_Coordinate()) - Point_1.getY_Coordinate()) / (Point_2.getX_Coordinate() - Point_1.getX_Coordinate()));
					}
					float findLength() {
						float d,x,y;
						x = pow((Point_2.getY_Coordinate() - Point_1.getY_Coordinate()), 2);
						y = static_cast<float>(pow((Point_2.getX_Coordinate() - Point_1.getX_Coordinate()), 2));
						d = pow(x + y, 0.5);
						//d = pow((pow((Point_2.getY_Coordinate() - Point_1.getY_Coordinate()), 2) + pow((Point_2.getX_Coordinate() - Point_1.getX_Coordinate()), 2)), (1 / 2));
						return d;
					}
	
					Point findMidPoint() const {
						int mid_x = (Point_2.getX_Coordinate() + Point_1.getX_Coordinate()) / 2;
						int mid_y = (Point_2.getY_Coordinate() + Point_1.getY_Coordinate()) / 2;
						return Point(mid_x, mid_y);
					}

				};
