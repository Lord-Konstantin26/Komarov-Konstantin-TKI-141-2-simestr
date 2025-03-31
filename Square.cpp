#include "Square.h"
#include <iostream>
#include <cmath>

using namespace std;

double Square::distanceSquared() const
{
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return dx * dx + dy * dy;
}

bool Square::yesCollinear() const
{
    double area = a.getX() * (b.getY() - c.getY()) + 
        b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
    return (abs(area) < numeric_limits<double>::epsilon());
}

bool Square::yesSquare() const
{
    if (a == b || a == c || b == c)
    {
        cout << "Некоторые точки совпадают!" << endl;
        return false;
    }
    if (yesCollinear(a, b, c))
    {
        cout << "Точки лежат на одной прямой!" << endl;
        return false;
    }

    double d2 = distanceSquared(a, b);
    double d3 = distanceSquared(a, c);
    double d4 = distanceSquared(b, c);

    if (abs(d2 - d3) < numeric_limits<double>::epsilon() && abs(2 * d2 - d4) 
        < numeric_limits<double>::epsilon()) return true;
    if (abs(d2 - d4) < numeric_limits<double>::epsilon() && abs(2 * d2 - d3)
        < numeric_limits<double>::epsilon()) return true;
    if (abs(d3 - d4) < numeric_limits<double>::epsilon() && abs(2 * d3 - d2)
        < numeric_limits<double>::epsilon()) return true;

    cout << "Точки не образуют квадрат!" << endl;
    return false; 
}

Point Square::findFourthPoint() const
{
    double abx = b.getX() - a.getX();
    double aby = b.getY() - a.getY();

    double acx = c.getX() - a.getX();
    double acy = c.getY() - a.getY();

    if (abx * acx + aby * acy == 0)
    {
        return Point(b.getX() + c.getX() - a.getX(), b.getY() + c.getY() - a.getY());
    }

    double bcx = c.getX() - b.getX();
    double bcy = c.getY() - b.getY();

    if (abx * bcx + aby * bcy == 0)
    {
        return Point(a.getX() + c.getX() - b.getX(), a.getY() + c.getY() - b.getY());
    }

    if (acx * bcx + acy * bcy == 0)
    {
        return Point(a.getX() + b.getX() - c.getX(), a.getY() + b.getY() - c.getY());
    }

    return Point(0,0);
}

double Square::sideLeinght() const
{
    return sqrt(distanceSquared(p1, p2));
}

Square::Square(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3)
{
    if (!yesSquare(p1, p2, p3))
    {
        cout << "Точки не образуют квадрат!" << endl; 
        exit(1);
    }
    p4 = findFourthPoint(p1, p2, p3);
    side = sideLeinght();
}


double Square::getSide() const
{
    return side;
}

double Square::perimetr() const
{
    return 4 * side; 
}

double Square::area() const
{
    return side * side;
}

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
