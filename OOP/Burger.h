#pragma once
#include "Food.h"
class Burger :
    public Food
{
public:
    void Consume();
protected:
    bool has_special_sauce;
};

