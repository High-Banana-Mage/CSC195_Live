#include "Skeleton.h"

void Skeleton::Read(ifstream& istream)
{
	Monster::Read(istream);
	istream >> m_hasBow;
	m_name = Monster::e_Type::SKELETON;
}

void Skeleton::Write(ofstream& ostream)
{
	ostream << "Skeleton:" << endl;
	Monster::Write(ostream);
	ostream << "Has a Bow: " << m_hasBow << endl;
}