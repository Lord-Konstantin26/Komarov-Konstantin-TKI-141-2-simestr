#include "Point.h"
#include "Square.h"
#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

/**
* @brief Точка входа в пронграмму.
* @return 0 в случае успешного завершения программы.
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	Point p1, p2, p3;

	cout << "Введите координаты  первой точки с клавиатуры: " << endl;
	p1.input();
	cout << "Введите координаты  второй точки с клавиатуры: " << endl;
	p2.input();
	cout << "Введите координаты  третьей точки с клавиатуры: " << endl;
	p3.input();

	Square square(p1, p2, p3);

	square.printPoints();

	cout << "Площадь квадрата: " << square.area() << endl;
	cout << "Периметр квадрата: " << square.perimetr() << endl;
}
