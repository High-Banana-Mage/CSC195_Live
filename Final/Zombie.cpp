#include "Zombie.h"

void Zombie::Read(ifstream& istream)
{
	Monster::Read(istream);
	istream >> m_lives;
	m_name = Monster::e_Type::ZOMBIE;
}

void Zombie::Write(ofstream& ostream)
{
	ostream << "Zombie:" << endl;
	Monster::Write(ostream);
	ostream << "Lives: " << m_lives << endl;
}