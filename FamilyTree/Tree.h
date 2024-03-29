#ifndef TREE_H
#define TREE_H
#include <vector>
#include "Person.h"
using namespace std;

class Tree {
private:
    vector <vector<pair<Person, pair<Person, Person>>>> tree;
    std::string familyTreeName;
    std::vector<Person*> people;
    
public:
    Tree();
    void clear() {};
    void add_person(Person p, Person father, Person mother); 
    void add_person(Person p, Person parent);
    void add_person(Person p);
    void print_description();
    void show(int width, int height);
};
#endif