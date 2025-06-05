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

    monster->Read(cin);
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

            m_container[i]->Write(output);
            output << endl;
        }
    }
}

void Database::DisplayAll()
{
    for (int i = 0; i < m_container.size(); i++)
    {
        m_container[i]->Write(cout);
    }
}

void Database::Display(const string& name)
{
    for (int i = 0; i < m_container.size(); i++)
    {
        if (m_container[i]->getName() == name)
        {
            m_container[i]->Write(cout);
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
            m_container[i]->Write(cout);
            cout << endl;
            break;
        }
    }
}