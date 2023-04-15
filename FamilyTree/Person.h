#include <iostream>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person {
private:
    string name;
    string bdate;
    string ddate;
public:
    Person(string name, string bdate, string ddate);
    Person(string name, string bdate);
    string description(bool include_dates);
    //string description();
    string short_description();
    string get_name();
    string get_birth_date();
    bool operator==(Person& other);
};
#endif