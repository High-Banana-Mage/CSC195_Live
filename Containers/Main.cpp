#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <map>
using namespace std;
void arrays()
{
	array<string, 7> week = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	for (string day : week)
	{
		cout << day << endl;
	}
}

void vectors()
{
	vector<int> nums = { 1,2,3,4,5 };
	nums.push_back(6);
	nums.push_back(7);
	nums.pop_back();
	for (int num : nums)
	{
		cout << num << endl;
	}
}

void lists()
{
	list<string> fruits = { "Apple", "Orange", "Banana" };
	fruits.push_front("Watermelon");
	fruits.push_back("Mango");
	fruits.remove("Banana");
	for (string fruit : fruits)
	{
		cout << fruit << endl;
	}
}

void maps()
{
	map<string, int> stock = {
	{"apples", 10,},
	{"bananas", 5},
	{"mangos", 7}
	};
	stock["apples"] = 4;

	for (auto& item : stock)
	{
		cout << item.first << " " << item.second << endl;
	}
}

int main()
{
	arrays();
	vectors();
	lists();
	maps();
}