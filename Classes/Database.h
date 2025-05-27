#pragma once
#include <vector>
#include "Vehicle.h"
class Database
{
public:
	vector<Vehicle*> objects;

	~Database(); // Destructor
	void Create(Vehicle::vType type);
	void DisplayAll();
	void Display(const std::string& name);
	void Display(Vehicle::vType type);
};

