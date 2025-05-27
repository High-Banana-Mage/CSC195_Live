#pragma once
#include "Vehicle.h"
class Plane :
    public Vehicle
{
public:
    int altitude;

    void Read(ostream& ostream, istream& istream) override;
    void Write(ostream& ostream) override;
    vType GetType() override { return vType::PLANE; }
};

