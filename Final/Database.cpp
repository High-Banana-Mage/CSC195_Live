#include "Database.h"

unique_ptr<Monster> Database::Create(Monster::e_Type type)
{
    unique_ptr<Monster> obj;
    switch (type)
    {
    case Monster::e_Type::ZOMBIE:
        obj = make_unique<Zombie>();
        break;
    case Monster::e_Type::SKELETON:
        obj = make_unique<Skeleton>();
        break;
    default:
        break;
    }
    obj->Read(cin);
    return obj;
}

void Database::Add(Monster::e_Type type)
{
    unique_ptr<Monster> monster = Create(type);

    monster->Read(cin);
    m_container.push_back(monster);
}

void Database::Load(const string& filename)
{
    ifstream input(filename);
    if (input.is_open())
    {
        m_container.clear();
            while (!input.eof())
            {
                int type;
                input >> type;
                unique_ptr<Monster> monster = Create(static_cast<Monster::e_Type>(type));
                monster->Read(cin);
                m_container.push_back(monster);
            }
    }
}

void Database::Save(const string& filename)
{
    ofstream output(filename);
    if (output.is_open())
    {
        //use for loop to iterate through all animals in the container
        for(int i = 0; i < m_container.size(); i++)
        {

            output << get animal type and cast to int to write << endl;
            <call animal Write with the file output stream>
        }
    }
}