#pragma once
struct Sandwich
{
public:
    std::string bread;
    bool isDelicious;
    Meat meat;
private:
    float price = 0;

};

enum Meat
{
    Chicken,
    Prawns,
    Pastrami
};