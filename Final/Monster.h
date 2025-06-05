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
	e_Type m_name;

public:
	int getHealth() { return m_health; }
	e_Type getName() { return m_name; }

	virtual void Read(istream& istream);
	virtual void Write(ostream& ostream);

	friend istream& operator>> (istream& istream, Monster& monster);
	friend ostream& operator<< (ostream& ostream, Monster& monster);
	friend istream& operator >> (istream& istream, Monster& monster);
	friend ostream& operator << (ostream& ostream, Monster& monster);
};

