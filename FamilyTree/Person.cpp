#include "Person.h"

Person::Person(string name, string bdate, string ddate) {
    this->name = name;
    this->bdate = bdate;
    this->ddate = ddate;
}

Person::Person(string name, string bdate) {
    this->name = name;
    this->bdate = bdate;
    this->ddate = "";
}

string Person::description(bool include_dates = true) {
    if (name != "null") {
        string dmessage = "";
        if (include_dates) {
            dmessage = ddate == "" ? "" : " alive/dead " + ddate;
            dmessage = " alive " + bdate + dmessage;
        }
        string message = name + dmessage + "\n";
        return message;
    }
    else {
        return "";
    }
}

string Person::short_description() {
    string is_dead = ddate == "" ? "--------------" : ddate;
    return name + "\n" + bdate + "\n" + is_dead;
}

string Person::get_name() {
    return this->name;
}

string Person::get_birth_date()
{
    return bdate;
}

bool Person::operator==(Person& other) {
    return this->description() == other.description();
}
