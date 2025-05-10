#include "Point.h"
#include "Square.h"
#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

/**
* @brief Ввод координат точек с клавиатуры.
* @param message Сообщение перед вводом.
*/
Point getPoint(string message);

/**
* @brief Функция создание квадрата по трем точкам.
*/
Square getSquare();

/**
* @brief Точка входа в пронграмму.
* @return 0 в случае успешного завершения программы.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	Square square = getSquare();
	square.printPoints();
	cout << "Площадь квадрата: " << square.area() << endl;
	cout << "Периметр квадрата: " << square.perimetr() << endl;
	return 0;
}

Point getPoint(string message)
{
	cout << message << endl;
	double x = 0.0;
	double y = 0.0;
	cin >> x >> y;
	if (cin.fail())
	{
		throw invalid_argument("Введено некорректное значениет");
	}

	return Point(x, y);
}

Square getSquare()
{
	Point A = getPoint("Введите координаты x и y для первой точки: ");
	Point B = getPoint("Введите координаты x и y для второй точки: ");
	Point C = getPoint("Введите координаты x и y для третьей точки: ");
	return Square(A, B, C);
}
