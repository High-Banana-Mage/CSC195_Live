#include <iostream>
#include "Food.h"
#include "Fruit.h"
#include "Burger.h"
using namespace std;

int main()
{
	Food food;

	food.Consume();
	cout << food.GetCalories() << endl;

	Food* pFood = &food;

	(*pFood).Consume();

	Fruit apple;

	cout << "Fruit stuff!" << endl;
	apple.Consume();

	cout << "Fruit Calories: " << apple.GetCalories() << endl;

	cout << "Burger Instances" << endl;
	Burger burger;

}