#pragma once
#include <string>
#include <fstream>
using namespace std;

class Monster
{
protected:
	int m_health;
	string m_name;

public:
	int getHealth() { return m_health; }
	string getName() { return m_name; }

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);
};

