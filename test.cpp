#pragma once
#include <vector>
#include "Person.h"
using namespace std
  
  class Tree {
    private:
    vector <vector<pair<Person, pair<Person, Person>>>> tree;
    public:
    Tree();
    void add_person(Person p, Person father, Person mother); // Add a person with two parents
