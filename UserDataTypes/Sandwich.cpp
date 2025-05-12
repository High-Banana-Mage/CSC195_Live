#include "Sandwich.h"

void setPrice(float value)
{
    price = value;
}

float getPrice()
{
    return price;
}

void PrintPrice()
{
    std::cout << "Price $" << price << std::endl;
}