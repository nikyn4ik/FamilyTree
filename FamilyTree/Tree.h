#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Person.h"
using namespace std;


class Tree {
private:
    vector <vector<pair<Person, pair<Person, Person>>>> tree;
public:
    Tree();
    void add_person(Person p, Person father, Person mother); // Add a person with two parents
    void add_person(Person p, Person parent); // Add a person with one parent
    void add_person(Person p); // Add a person without specifying parents - at the top level
    void print_description(); // Print a text description of the tree state
    void show(int width, int height); // Display the tree as a graphical representation
};