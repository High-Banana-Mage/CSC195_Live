#include "Animal.h"

void Animal::Read(ostream& ostream, istream& istream)
{
	ostream << "Enter name: ";
	istream >> m_name;

	ostream << "Enter Lifespan: ";
	istream >> m_lifespan;
}

void Animal::Write(ostream& ostream)
{
}
