#include "Rectangle.h"
#include <iostream>
#include <limits>

using namespace std;


unsigned int inputMaxCoordinate() {
    unsigned int maxCoord;
    while (true) {
        cout << "Enter maximum coordinate value: ";
        cin >> maxCoord;
        if (cin.fail() || maxCoord == 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Maximum coordinate must be positive integer.\n";
        }
        else {
            break;
        }
    }
    return maxCoord;
}

void inputPoint(const string& prompt, Point& p) {
    while (true) {
        cout << prompt;
        cin >> p;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter two numbers separated by space.\n";
        }
        else {
            break;
        }
    }
}


void inputRectangleCoordinates(unsigned int& x1, unsigned int& y1,
    unsigned int& x2, unsigned int& y2) {
    while (true) {
        cout << "Enter rectangle coordinates (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter four numbers separated by spaces.\n";
        }
        else {
            break;
        }
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
        unsigned int x1, y1, x2, y2;
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