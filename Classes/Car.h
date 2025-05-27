#pragma once
#include "Vehicle.h"
class Car :
    public Vehicle
{
public:
    bool isConvertible;

    void Read(ostream& ostream, istream& istream) override;
    void Write(ostream& ostream) override;
    vType GetType() override { return vType::CAR; }
};

