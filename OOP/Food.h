#pragma once

class Food
{
public:
	//Constructor
	//allocating memory for data members
	//initiating data members w/ diffucult value
	// If we don't create one manually, one is created for us
	/*Food() {
		m_calories = 0;
	}*/

	Food() : m_calories(0) {};

	//Constructor w/ parameters
	Food(int cal) {
		SetCalories(cal);
	}

	//Deconstructor used to deallocate memory
	~Food();


	void Consume();
	int GetCalories() { return m_calories; }

protected:
	int m_calories;
	void SetCalories(int calories) { m_calories = calories; }

};
