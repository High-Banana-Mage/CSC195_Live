#pragma once
#include <string>
#include <ostream>
#include <istream>
#include <vector>
using namespace std;

class Animal
{
public:
	enum class eType
	{
		BIRD = 1,
		REPTILE
	};

	string GetName() { return m_name; }
	virtual eType GetType() = 0;

	virtual void  Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream);

protected:
	string m_name;
	int m_lifespan;
};

