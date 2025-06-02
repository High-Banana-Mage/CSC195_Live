#pragma once
#include <iostream>
using namespace std;

namespace ost
{
	class Point
	{
	public:
		float x, y;

	public:
		Point() : x{0}, y{0} {}
		Point(float x, float y) : x{ x }, y{ y } {}

		void Write(ostream& ostream);
		void Add(Point& point);

		// friend - access private variables in a non-member function



	};
}


