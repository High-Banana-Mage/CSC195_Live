#include "Monster.h"

void Monster::Read(istream& istream)
{
    istream >> m_name;
	istream >> m_health;
}

void Monster::Write(ostream& ostream)
{
    ostream << m_name << endl;
	ostream << m_health << endl;
}

istream& operator>>(istream& istream, Monster& monster)
{
	monster.Read(cin);
	return istream;
}

ostream& operator<<(ostream& ostream, Monster& monster)
{
	monster.Write(ostream);
	return ostream;
}

ifstream& operator >> (ifstream& istream, Monster& monster) {
    if (auto* fileStream = dynamic_cast<ifstream*>(&istream)) {
        monster.Read(*fileStream);
    }
    return istream;
}

ofstream& operator << (ofstream& ostream, Monster& monster) {
    if (auto* fileStream = dynamic_cast<ofstream*>(&ostream)) {
        monster.Write(*fileStream);
    }
    return ostream;
}
