#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

Tree::Tree()
{
}

void Tree::add_person(Person p, Person father, Person mother)
{
    vector<pair<Person, pair<Person, Person>>> family;
    family.push_back(make_pair(p, make_pair(father, mother)));
    tree.push_back(family);
}

void Tree::add_person(Person p, Person parent)
{
    for (int i = 0; i < tree.size(); i++)
    {
        vector<pair<Person, pair<Person, Person>>> family = tree[i];
        for (int j = 0; j < family.size(); j++)
        {
            if (family[j].first == parent)
            {
                family.push_back(make_pair(p, make_pair(Person(L"null", L""), Person(L"null", L""))));
                tree[i] = family;
                return;
            }
        }
    }
}

void Tree::add_person(Person p)
{
    vector<pair<Person, pair<Person, Person>>> family;
    family.push_back(make_pair(p, make_pair(Person(L"null", L""), Person(L"null", L""))));
    tree.push_back(family);
}

void Tree::print_description()
{
    for (int i = 0; i < tree.size(); i++)
    {
        vector<pair<Person, pair<Person, Person>>> family = tree[i];
        cout << "Generation " << i + 1 << ":\n";
        for (int j = 0; j < family.size(); j++)
        {
            Person p = family[j].first; 
            Person parents = family[j].second.first;
            Person father = family[j].second.first;
            Person mother = family[j].second.second;

            wcout << p.description();


            if (parents.description().empty())
            {
                wcout << "Parents: " "\n";
            }

            if (father.description().empty())
            {
                wcout << "Father: " << father.short_description() << "\n";
            }

            if (mother.description().empty())
            {
                wcout << "Mother: " << mother.short_description() << "\n";
            }

            if (j != family.size() - 1)
            {
                wcout << "----\n";
            }
        }
        cout << "\n";
    }
}

void Tree::show(int width, int height)
{
    // implementation for visualizing the tree using a graphics library (e.g. SFML)
    // omitted for brevity
}
