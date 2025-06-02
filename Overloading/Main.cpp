#include <iostream>
#include "Point.h"
using namespace std;

void print(int x) { cout << x << endl; }
void print(float x) { cout << x << endl; }
void print(bool x) { cout << x << endl; }

void operator + (ost::Point& p1, ost::Point& p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
}

void operator << (ostream& ostream, ost::Point& point)
{
	ostream << point.x << " : " << point.y << endl;
}

ost::Point operator * (ost::Point& p1, ost::Point& p2)
{
	return ost::Point(p1.x * p2.x, p1.y * p2.y);
}

int main()
{
	ost::Point point1(10, 14);
	ost::Point point2(2, 2);
	ost::Point point3;

	cout << point1;
	point3 = point1 * point2;
	cout << point3;
}