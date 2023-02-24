#pragma once
#include <iostream>
using namespace std;

class Person {
private:
    wstring name;
    wstring bdate;
    wstring ddate;
public:
    Person(wstring name, wstring bdate, wstring ddate);
    Person(wstring name, wstring bdate);
    wstring description();
    wstring short_description();
    wstring get_name();
    bool operator==(Person& other);
};