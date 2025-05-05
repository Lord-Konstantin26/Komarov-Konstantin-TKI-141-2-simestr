#include "Point.h"
#include <limits>

Point::Point(unsigned int x, unsigned int y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    while (!(is >> p.x >> p.y)) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Enter coordinates again (x y): ";
    }
    return is;
}

Point Point::operator+(unsigned int value) const {
    return Point(x + value, y + value);
}

Point Point::operator-(unsigned int value) const {
    return (value <= x && value <= y) ? Point(x - value, y - value) : Point(0, 0);
}