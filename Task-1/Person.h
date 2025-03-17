#pragma once
#include <string>

using namespace std;

class Person
{
private:
	string lastname;
	string firstname;
	string patronymic;
public:
	Person();
	Person(const string& ln, const string& fn, const string& pn ="");
	void Show();
	void ShowFormal();
};