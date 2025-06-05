#pragma once
#include "Monster.h"
class Zombie :
    public Monster
{
private:
    int m_lives;

public:
    void Read(istream& istream);
    void Write(ostream& ostream);
    void Read(ifstream& istream);
    void Write(ofstream& ostream);
};

