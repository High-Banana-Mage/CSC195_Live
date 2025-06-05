#pragma once
#include "Monster.h"
class Skeleton :
    public Monster
{
private:
    bool m_hasBow;

public:
    void Read(istream& istream);
    void Write(ostream& ostream);
    void Read(ifstream& istream);
    void Write(ofstream& ostream);
};

