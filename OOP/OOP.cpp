#include <iostream>
#include "Food.h"
using namespace std;

int main()
{
	Food food;

	food.Consume();
	cout << food.GetCalories() << endl;

	Food* pFood = &food;

	(*pFood).Consume();
}