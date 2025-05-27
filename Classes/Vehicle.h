#pragma once
#include <string>
#include <ostream>
#include <istream>
using namespace std;
class Vehicle
{
public:
	enum class vType
	{
		CAR,
		PLANE
	};
	string name;
	double fuel_gallons;

	virtual void Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream);

	string GetName() { return name; };
	int GetFuel() { return fuel_gallons; }
	virtual vType GetType() = 0;

};

