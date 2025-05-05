#include "Rectangle.h"
#include <sstream>
#include <limits>

using namespace std;
unsigned int Rectangle::maxCoord = 1920;

Rectangle::Rectangle(const Point& tl, const Point& br) : topLeft(tl), bottomRight(br) {
    if (!IsValid()) throw invalid_argument("Invalid rectangle coordinates");
}

Rectangle::Rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
    : topLeft(x1, y1), bottomRight(x2, y2) {
    if (!IsValid()) throw invalid_argument("Invalid rectangle coordinates");
}

bool Rectangle::IsValid() const {
    return (topLeft.x < bottomRight.x) &&
        (topLeft.y < bottomRight.y) &&
        (bottomRight.x <= maxCoord) &&
        (bottomRight.y <= maxCoord);
}

std::string Rectangle::ToString() const {
    std::ostringstream oss;
    oss << "Rectangle: TopLeft = " << topLeft << ", BottomRight = " << bottomRight;
    return oss.str();
}

void Rectangle::ReadFromStream(istream& is) {
    is >> topLeft >> bottomRight;
    if (!IsValid()) throw std::runtime_error("Invalid rectangle coordinates from stream");
}

std::string Rectangle::Serialize(const Rectangle& rect) {
    return rect.ToString();
}

Rectangle Rectangle::Deserialize(istream& is) {
    unsigned int x1, y1, x2, y2;
    char check;

    if (!(is >> x1 >> y1 >> x2 >> y2)) {
        is.clear();
        is.ignore(numeric_limits < streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Requires exactly 4 numbers (x1 y1 x2 y2)");
    }


    if (is.get(check) && check != '\n') {
        is.ignore(numeric_limits < streamsize>::max(), '\n');
        throw invalid_argument("Extra characters after coordinates");
    }

    return Rectangle(x1, y1, x2, y2);
}

void Rectangle::SetMaxCoordinate(unsigned int max) {
    maxCoord = max;
}