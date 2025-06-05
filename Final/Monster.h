#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Monster
{
public:
	enum class e_Type
	{
		ZOMBIE,
		SKELETON
	};

protected:
	int m_health;
	string m_name;
	e_Type m_type;

public:
	int getHealth() { return m_health; }
	string getName() { return m_name; }
	e_Type getType() { return m_type; }

	virtual void Read(istream& istream);
	virtual void Write(ostream& ostream);

	friend istream& operator>> (istream& istream, Monster& monster);
	friend ostream& operator<< (ostream& ostream, Monster& monster);
	friend ifstream& operator >> (ifstream& istream, Monster& monster);
	friend ofstream& operator << (ofstream& ostream, Monster& monster);
};

