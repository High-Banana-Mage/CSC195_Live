#include "Monster.h"

void Monster::Read(ifstream& istream)
{
	istream >> m_health;
	istream >> m_name;
}

void Monster::Write(ofstream& ostream)
{
	ostream << m_health << endl;
	ostream << m_name << endl;
}
