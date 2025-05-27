#include "Bird.h"

void Bird::Read(ostream& ostream, istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter the number of feathers: ";
	istream >> m_numFeathers;
}

void Bird::Write(ostream& ostream, istream& istream)
{

}
