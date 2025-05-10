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

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

/**
* @brief Вывод координат точки на экран.
*/
void Point::print() const
{
	cout << "(" << x << ", " << y << ")";
}


bool operator==(const Point& p1, const Point& p2)
{
	return abs(p1.getX() - p2.getX()) <= numeric_limits<double>::epsilon()
		&& abs(p1.getY() - p2.getY()) <= numeric_limits<double>::epsilon();
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}
