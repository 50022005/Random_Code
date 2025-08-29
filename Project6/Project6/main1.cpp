#include<iostream>
#include"Header1.h"


int main() {
	Line L1(1, 5, 10, 15);
	Point p2(1, 2);
	Point p3(2,4);
	Point P(p2);
	
	cout << "Slope    :" << L1.findSlope() << endl;
	cout << "Length     :" << L1.findLength() << endl;
	cout << " Midpoint   :" << L1.findMidPoint() << endl;


}