#include "Vehicle.h"

void Vehicle::Read(ostream& ostream, istream& istream)
{
	ostream << "Enter name: ";
	istream >> name;

	ostream << "Enter fuel in gallons: ";
	istream >> fuel_gallons;
	
}

void Vehicle::Write(ostream& ostream)
{
	ostream << "Name: " << GetName() << endl;
	ostream << "Fuel: " << GetFuel() << endl;
}
