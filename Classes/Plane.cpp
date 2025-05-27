#include "Plane.h"

void Plane::Read(ostream& ostream, istream& istream)
{
	Vehicle::Read(ostream, istream);
	ostream << "Altitude: ";
	istream >> altitude;
}

void Plane::Write(ostream& ostream)
{
	Vehicle::Write(ostream);
	ostream << "Altitude: " << altitude << endl;
}
