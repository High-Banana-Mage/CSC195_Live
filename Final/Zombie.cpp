#include "Zombie.h"

void Zombie::Read(istream& istream)
{
	Monster::Read(istream);
	istream >> m_lives;
	m_type = Monster::e_Type::ZOMBIE;
}

void Zombie::Write(ostream& ostream)
{
	Monster::Write(ostream);
	ostream << m_lives << endl;
}

void Zombie::Read(ifstream& istream)
{
	Monster::Read(istream);
	istream >> m_lives;
	m_type = Monster::e_Type::ZOMBIE;
}

void Zombie::Write(ofstream& ostream)
{
	Monster::Write(ostream);
	ostream << m_lives << endl;
}