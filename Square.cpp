#include "Square.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
* @brief Вычисляет квадрат расстояния между двумя точками.
* @param a Первая точка.
* @param b Первая точка.
* @return Квадрат расстояния между точками a и b.
*/
double Square::distanceSquared(const Point& a, const Point& b) const
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

/**
* @brief Проверяет, лежат ли три точки на одной прямой.
* @param a Первая точка.
* @param b Вторая точка.
* @param c Третья точка.
* @return true, если точки лежат на одной прямой, иначе false.
*/
bool Square::yesCollinear(const Point& a, const Point& b, const Point& c) const
{
    double area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return (area == 0);
}

/**
* @brief Проверяет, образуют ли три точки квадрат.
* @param a Первая точка.
* @param b Вторая точка.
* @param c Третья точка.
* @return true, если точки образуют квадрат, иначе false.
*/
bool Square::yesSquare(const Point& a, const Point& b, const Point& c) const
{
    if (yesCollinear(a, b, c))
    {
        cout << "Точки лежат на одной прямой!" << endl;
        return false;
    }

    double d2 = distanceSquared(a, b);
    double d3 = distanceSquared(a, c);
    double d4 = distanceSquared(b, c);

    if (d2 == d3 && 2 * d2 == d4) return true;
    if (d2 == d4 && 2 * d2 == d3) return true;
    if (d3 == d4 && 2 * d3 == d2) return true;

    cout << "Точки не образуют квадрат!" << endl;
    return false; 
}

/**
* @brief Находит четвертую точку квадрата по известным трем точкам.
* @param a Первая точка.
* @param b Вторая точка.
* @param c Третья точка.
*/
Point Square::findFourthPoint(const Point& a, const Point& b, const Point& c) const
{
    double abx = b.x - a.x;
    double aby = b.y - a.y;

    double acx = c.x - a.x;
    double acy = c.y - a.y;

    if (abx * acx + aby * acy == 0)
    {
        return Point(b.x + c.x - a.x, b.y + c.y - a.y);
    }

    double bcx = c.x - b.x;
    double bcy = c.y - b.y;

    if (abx * bcx + aby * bcy == 0)
    {
        return Point(a.x + c.x - b.x, a.y + c.y - b.y);
    }

    if (acx * bcx + acy * bcy == 0)
    {
        return Point(a.x + b.x - c.x, a.y + b.y - c.y);
    }

    return Point(0,0);
}

/**
* @brief Конструктор для инициализации квдрата тремя точками.
* @param p1 Первая точка.
* @param p2 Вторая точка.
* @param p3 Третья точка.
*/
Square::Square(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3)
{
    if (!yesSquare(p1, p2, p3))
    {
        cout << "Точки не образуют квадрат!" << endl; 
        exit(1);
    }
    p4 = findFourthPoint(p1, p2, p3);
}

/**
* @brief Вычисляет длину стороны квадрата.
* @return Длина стороны квадрата
*/
double Square::sideLeinght() const
{
    return sqrt(distanceSquared(p1, p2));
}

/**
* @brief Вычисляет периметр квадрата.
* @return Периметр квалрата.
*/
double Square::perimetr() const
{
    return 4 * sideLeinght(); 
}

/**
* @brief Вычисляет площадь квадрата.
* @return Площадь квадрата.
*/
double Square::area() const
{
    double side = sideLeinght();
    return side * side;
}

/**
* @brief Выводит координаты всех точек квадрата на экран.
*/
void Square::printPoints() const
{
    p1.print(); 
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();
    cout << endl;
    p4.print();
    cout << endl;
}
