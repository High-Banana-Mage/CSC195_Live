#include <iostream>
#include "Monster.h"
#include "Skeleton.h"
#include "Zombie.h"
#include "Database.h"
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>
using namespace std;

int main()
{
	Database* database = new Database();
	while(true)
	{
		cout << "1) Add\n";
		cout << "2) Display All\n";
		cout << "3) Display Name\n";
		cout << "4) Display Type\n";
		cout << "5) Load\n";
		cout << "6) Save\n";
		cout << "7) Quit\n";

		int input;
		cin >> input;
		switch (input)
		{
		case 1:
		{
			cout << "[1] Zombie" << endl;
			cout << "[2] Skeleton" << endl;
			int i;
			cin >> i;
			i--;
			database->Add(static_cast<Monster::e_Type>(i));
			cout << endl;
			break;
		}
		case 2:
		{
			database->DisplayAll();
			cout << endl;
			break;
		}
		case 3:
		{
			string name;
			cout << "Enter the name: ";
			cin >> name;
			database->Display(name);
			cout << endl;
			break;
		}
		case 4:
		{
			int i;
			cout << "What kind of monster are you looking for?" << endl;
			cout << "[1] Zombie" << endl;
			cout << "[2] Skeleton" << endl;
			cin >> i;
			i--;
			database->Display(static_cast<Monster::e_Type>(i));
			cout << endl;
			break;
		}
		case 5:
		{
			std::cout << "enter filename: ";
			string name;
			cin >> name;
			database->Load(name);
			cout << endl;
			break;
		}
		case 6:
		{
			std::cout << "enter filename: ";
			string name;
			cin >> name;
			database->Save(name);
			cout << endl;
			break;
		}
		case 7:
		{
			delete database;
			_CrtDumpMemoryLeaks();
			return 0;
		}
		default:
		{
			delete database;
			_CrtDumpMemoryLeaks();
			return 0;
		}
		}
	}
}