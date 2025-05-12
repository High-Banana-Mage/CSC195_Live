#include <iostream>

struct Sandwich
{
public:
    std::string bread;
    bool isDelicious;
    Meat meat;
private:
    float price = 0;
public:g

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
};

enum Meat
{
    Chicken,
    Prawns,
    Pastrami
};



int main()
{
    typedef float salary;

    salary wage_butcher = 12.4f;
    salary wage_cleaner = 9;
    salary wage_chef = 152.45f;

    Sandwich bbq;


    
    Sandwich bbq;

    bbq.bread = "Honey rye";
    //bbq.price = 25.0f;
    bbq.setPrice(30.0f);
    bbq.isDelicious = true;

    bbq.meat = Meat::Chicken;

    bbq.PrintPrice();
}