#pragma once
#include "Animal.h"
class Bird :
    public Animal
{
public:
    eType GetType() override { return eType::BIRD; }

    void Read(ostream& ostream, istream& istream);
    void Write(ostream& ostream, istream& istream);

protected:
    int m_numFeathers = 0;
};

