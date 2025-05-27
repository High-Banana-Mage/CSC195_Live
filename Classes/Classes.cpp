#include <iostream>
#include <limits>
#include "Database.h"

int main()
{
    Database database;
    bool quit = false;
    while (!quit)
    {
        std::cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
        int choice = 0;
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            cout << "[1]Car" << endl;
            cout << "[2]Plane" << endl;
            int vChoice = 0;
            cin >> vChoice;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (vChoice)
            {
            case 1:
                database.Create(Vehicle::vType::CAR);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 2:
                database.Create(Vehicle::vType::PLANE);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
            break;
        }
        case 2:
            database.DisplayAll();
            break;
        case 3:
        {
            cout << "Name of vehicle: ";
            string n_search;
            getline(cin, n_search);
            database.Display(n_search);
            break;
        }
        case 4:
        {
            std::cout << "Enter type (0 for Car, 1 for Plane): ";
            int t = -1;
            std::cin >> t;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (t == 0 || t == 1) {
                database.Display(static_cast<Vehicle::vType>(t));
            }
            else {
                cout << "Invalid type!" << endl;
            }
            break;
        }
        case 5:
            quit = true;
            break;
        default:
            cout << "Invalid menu choice! Please enter 1-5." << endl;
            break;
        }
    }
    return 0;
}