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
        cout << "Generation " << i << ":" << endl;
        for (int j = 0; j < family.size(); j++)
        {
            Person p = family[j].first;
            pair<Person, Person> parents = family[j].second;

            if (i == 0) {
                cout << "  t.add_person(Person(L\"" << p.get_name() << "\", L\"" << p.get_birth_date() << "\"));" << endl;
            }
            else {
                cout << "t.add_person(Person(L\"" << p.get_name() << "\", L\"" << p.get_birth_date() << "\"), " << endl;
                cout << "  Parents: " << endl;
                if (!parents.first.get_name().empty() || !parents.first.get_birth_date().empty()) {
                    cout << "    Person(L\"" << parents.first.get_name() << "\", L\"" << parents.first.get_birth_date() << "\")";
                }
                if (!parents.second.get_name().empty() || !parents.second.get_birth_date().empty()) {
                    cout << ", " << endl << "    Person(L\"" << parents.second.get_name() << "\", L\"" << parents.second.get_birth_date() << "\")";
                }
                cout << ");" << endl;
            }

            if (j != family.size() - 1)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
}

void Tree::show(int width, int height)
{
}
