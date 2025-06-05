#pragma once
#include <vector>
#include <memory>
#include "Monster.h"
#include "Zombie.h"
#include "Skeleton.h"
#include <iostream>
#include <fstream>

using namespace std;

class Database
{
private:
	vector<unique_ptr<Monster>> m_container;
	unique_ptr<Monster> Create(Monster::e_Type type);
public:
	void Add(Monster::e_Type type);
	void Load(const string& filename);
	void Save(const string& filename);
	void DisplayAll();
	void Display(const string& name);
	void Display(Monster::e_Type type);
};