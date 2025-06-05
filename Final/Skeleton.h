#pragma once
#include "Monster.h"
class Skeleton :
    public Monster
{
private:
    bool m_hasBow;

public:
    void Read(ifstream& istream);
    void Write(ofstream& ostream);
};

