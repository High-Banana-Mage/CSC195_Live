#include <iostream>
#include "Database.h"
#include "Car.h"
#include "Plane.h"

Database::~Database()
{
    for (Vehicle* obj : objects)
    {
        delete obj;
    }
}

void Database::Create(Vehicle::vType type)
{
    Vehicle* obj = nullptr;
    switch (type)
    {
    case Vehicle::vType::CAR:
        obj = new Car;
        break;
    case Vehicle::vType::PLANE:
        obj = new Plane;
        break;
    }
    obj->Read(cout, cin);
    objects.push_back(obj);
}

void Database::DisplayAll()
{
    for (Vehicle* obj : objects)
    {
        obj->Write(cout);
        cout << endl;
    }
}

void Database::Display(const string& name)
{
    for (Vehicle* obj : objects)
    {
        if (obj->GetName() == name)
        {
            obj->Write(cout);
            cout << endl;
        }
    }
}

void Database::Display(Vehicle::vType type)
{
    for (Vehicle* obj : objects)
    {
        if (obj->GetType() == type)
        {
            obj->Write(cout);
            cout << endl;
            break;
        }
    }
}