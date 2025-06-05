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
    return obj;
}

void Database::Add(Monster::e_Type type)
{
    unique_ptr<Monster> monster = Create(type);


    cin >> *monster;
    m_container.push_back(move(monster));
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
                monster->Read(input);
                m_container.push_back(move(monster));
            }
    }
}

void Database::Save(const string& filename)
{
    ofstream output(filename);
    if (output.is_open())
    {
        for(int i = 0; i < m_container.size(); i++)
        {

            output << static_cast<int>(m_container[i]->getType());
            m_container[i]->Write(output);
            output << endl;
        }
    }
}

void Database::DisplayAll()
{
    for (int i = 0; i < m_container.size(); i++)
    {
        cout << *m_container[i];
    }
}

void Database::Display(const string& name)
{
    for (int i = 0; i < m_container.size(); i++)
    {
        if (m_container[i]->getName() == name)
        {
            cout << *m_container[i];
            cout << endl;
        }
    }
}

void Database::Display(Monster::e_Type type)
{
    for (int i = 0; i < m_container.size(); i++)
    {
        if (m_container[i]->getType() == type)
        {
            cout << *m_container[i];
            cout << endl;
            break;
        }
    }
}