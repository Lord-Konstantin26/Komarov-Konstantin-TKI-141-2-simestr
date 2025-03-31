#include "Point.h"
#include "Square.h"
#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

/**
* @brief Функция проверки ввода.
* @return При невернном вводе выводит ошибку и аварийно завершает программу.
*/
double input();

/**
* @brief Точка входа в пронграмму.
* @return 0 в случае успешного завершения программы.
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	Point p1, p2, p3;

	cout << "Введите координаты первой точки с клавиатуры (x, y): " << endl;
	double x1 = input();
	double y1 = input();
	p1 = Point(x1, y1);
	cout << "Введите координаты второй точки с клавиатуры (x, y): " << endl;
	double x2 = input();
	double y2 = input();
	p2 = Point(x2, y2);
	cout << "Введите координаты третьей точки с клавиатуры (x, y): " << endl;
	double x3 = input();
	double y3 = input();
	p3 = Point(x3, y3);

	Square square(p1, p2, p3);

	square.printPoints();

	cout << "Площадь квадрата: " << square.area() << endl;
	cout << "Периметр квадрата: " << square.perimetr() << endl;

	return 0;
}

double input()
{
	double value = 0.0;
	cin >> value;
	if (cin.fail())
	{
		cout << "Ошибка ввода!" << endl;
		exit(0);
	}
	return value;
}