#include <iostream>
#include <locale>
#include "Person.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Person person("Комаров", "Константин", "Сергеевич");

	cout << "Имя и Фамилия" << endl;
	person.Show();

	cout << "\nФИО" << endl;
	person.ShowFormal();

	return 0;

}
