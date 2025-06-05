#include "Skeleton.h"

void Skeleton::Read(istream& istream)
{
	Monster::Read(istream);
	istream >> m_hasBow;
	m_type = Monster::e_Type::SKELETON;
}

void Skeleton::Write(ostream& ostream)
{
	Monster::Write(ostream);
	ostream << m_hasBow << endl;
}

void Skeleton::Read(ifstream& istream)
{
	Monster::Read(istream);
	istream >> m_hasBow;
	m_type = Monster::e_Type::SKELETON;
}

void Skeleton::Write(ofstream& ostream)
{
	Monster::Write(ostream);
	ostream << m_hasBow << endl;
}