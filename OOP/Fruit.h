#pragma once
#include "Food.h"
class Fruit : public Food
{
public:
	void Consume();
protected:
	int num_of_seeds;
};

