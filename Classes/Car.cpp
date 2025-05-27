#include "Car.h"

void Car::Read(ostream& ostream, istream& istream)
{
	Vehicle::Read(ostream, istream);
	ostream << "Is it a convertable? [true/false]";
	istream >> isConvertible;
}

void Car::Write(ostream& ostream)
{
	Vehicle::Write(ostream);
	ostream << "Is a convirtable: " << isConvertible << endl;
}
