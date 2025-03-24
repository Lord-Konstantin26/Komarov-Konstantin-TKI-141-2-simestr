#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
* @brief Конструктор для инициализации точки.
* @param x Координаты х (по умолчанию 0).
* @param x Координаты y (по умолчанию 0).
*/
Point::Point(const double x, const double y) : x{x}, y{y}
{
}


/**
* @brief Ввод координат с клавиатуры.
*/
void Point::input()
{
	cout << "Введите значение координаты х: ";
	cin >> x;
	cout << "Введите значение координаты y: ";
	cin >> y;
}

/**
* @brief Вывод координат точки на экран.
*/
void Point::print() const
{
	cout << "(" << x << ", " << y << ")";
}
