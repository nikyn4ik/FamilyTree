#include "Person.h"

Person::Person(wstring name, wstring bdate, wstring ddate) {
    this->name = name;
    this->bdate = bdate;
    this->ddate = ddate;
}

Person::Person(wstring name, wstring bdate) {
    this->name = name;
    this->bdate = bdate;
    this->ddate = L"";
}

wstring Person::description() {
    if (name != L"null") {
        wstring dmessage = ddate == L"" ? L"" : L" и умер/умерла " + ddate;
        wstring message = name + L" родился/родилась " + bdate + dmessage + L"\n";
        return message;
    }
    else {
        return L"";
    }
}

wstring Person::short_description() {
    wstring is_dead = ddate == L"" ? L"--------------" : ddate;
    return name + L"\n" + bdate + L"\n" + is_dead;
}

wstring Person::get_name() {
    return this->name;
}

bool Person::operator==(Person& other) {
    return this->description() == other.description();
}
