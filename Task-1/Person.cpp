#include "Person.h"
#include <string>
#include <iostream>

Person::Person() : firstname(""), lastname(""), patronymic("") {}

Person::Person(const string& ln, const string& fn, const string& pn)
    : firstname(fn), lastname(ln), patronymic(pn) {
}

void Person::Show()
{
        cout << lastname << " " << firstname << endl;
}

void Person::ShowFormal()
{
        cout << lastname << " " << firstname << " " << patronymic << endl;
}

