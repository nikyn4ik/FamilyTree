#pragma once
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string bdate;
    string ddate;
public:
    Person(string name, string bdate, string ddate);
    Person(string name, string bdate);
    string description();
    string short_description();
    string get_name();
    string get_birth_date();
    bool operator==(Person& other);
};