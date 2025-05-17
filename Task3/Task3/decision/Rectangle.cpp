#include "Rectangle.h"
#include <sstream>
#include <limits>

using namespace std;

Rectangle::Rectangle(const Point& tl, const Point& br) : topLeft(tl), bottomRight(br) {
    if (!IsValid()) throw invalid_argument("Invalid rectangle coordinates");
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : topLeft(x1, y1), bottomRight(x2, y2) {
    if (!IsValid()) throw invalid_argument("Invalid rectangle coordinates");
}

bool Rectangle::IsValid() const {
    return (topLeft.x < bottomRight.x) &&
        (topLeft.y < bottomRight.y) &&
        (bottomRight.x <= maxCoord) &&
        (bottomRight.y <= maxCoord);
}

string Rectangle::ToString() const {
    ostringstream oss;
    oss << "Rectangle: TopLeft = " << topLeft << ", BottomRight = " << bottomRight;
    return oss.str();
}

void Rectangle::ReadFromStream(istream& is) {
    is >> topLeft >> bottomRight;
    if (!IsValid()) throw runtime_error("Invalid rectangle coordinates from stream");
}

string Rectangle::Serialize(const Rectangle& rect) {
    return rect.ToString();
}

Rectangle Rectangle::Deserialize(istream& is) {
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
    char check = '\0';

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

void Rectangle::SetMaxCoordinate(double max) {
    maxCoord = max;
}

const Point& Rectangle::GetTopLeft() const {
    return topLeft;
}

const Point& Rectangle::GetBottomRight() const {
    return bottomRight;
}

