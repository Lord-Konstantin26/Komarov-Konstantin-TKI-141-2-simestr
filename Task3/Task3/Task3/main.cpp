#include <iostream>
#include <limits>
#include "../Task-3/"


using namespace std;

double inputMaxCoordinate() {
    double maxCoord;
    cout << "Enter maximum coordinate value: ";
    cin >> maxCoord;

    if (cin.fail() || maxCoord <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Maximum coordinate must be positive integer");
    }

    return maxCoord;
}

void inputPoint(const string& prompt, Point& p) {
    cout << prompt;
    cin >> p;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Please enter two numbers separated by space");
    }
}

void inputRectangleCoordinates(double& x1, double& y1, double& x2, double& y2) {
    cout << "Enter rectangle coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Please enter four numbers separated by spaces");
    }
}

int main() {
    try {
        Rectangle::SetMaxCoordinate(inputMaxCoordinate());

        cout << "\n=== Creating first rectangle (via Points) ===\n";
        Point p1, p2;
        inputPoint("Enter top-left point (x y): ", p1);
        inputPoint("Enter bottom-right point (x y): ", p2);
        Rectangle rect1(p1, p2);
        cout << "Rectangle 1 created: ";
        rect1.Print();

        // Создание второго прямоугольника через координаты
        cout << "\n=== Creating second rectangle (via coordinates) ===\n";
        double x1, y1, x2, y2;
        inputRectangleCoordinates(x1, y1, x2, y2);
        Rectangle rect2(x1, y1, x2, y2);
        cout << "Rectangle 2 created: ";
        rect2.Print();

        // Сериализация первого прямоугольника
        cout << "\nSerialized Rectangle 1: " << Rectangle::Serialize(rect1) << endl;

        // Создание третьего прямоугольника через десериализацию
        cout << "\n=== Creating third rectangle (via deserialization) ===\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try {
            Rectangle rect3 = Rectangle::Deserialize(cin);
            cout << "Rectangle 3 created: ";
            rect3.Print();
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    }
    catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
