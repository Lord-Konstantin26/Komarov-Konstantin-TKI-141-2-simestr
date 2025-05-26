#include "CppUnitTest.h"
#include "../decision/Figure.h"
#include "../decision/Rectangle.h"
#include "../decision/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace RectangleTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(Constructor_ValidData_Success)
        {
            Point p(10, 20);
            Assert::AreEqual(10.0, p.x);
            Assert::AreEqual(20.0, p.y);
        }

        TEST_METHOD(EqualityOperator_WorksCorrectly)
        {
            Point p1(5, 10);
            Point p2(5, 10);
            Assert::IsTrue(p1 == p2, L"Equal points should return true");

            Point p3(5, 11);
            Point p4(6, 10);
            Point p5(6, 11);
            Assert::IsFalse(p1 == p3, L"Different Y should return false");
            Assert::IsFalse(p1 == p4, L"Different X should return false");
            Assert::IsFalse(p1 == p5, L"Different X and Y should return false");
        }
    };

    TEST_CLASS(RectangleTests)
    {
    public:
        TEST_METHOD(ConstructorWithPoints_ValidData_Success)
        {
            Point tl(1, 5);
            Point br(4, 9);
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(tl, br);
            Assert::IsTrue(rect.IsValid());
        }

        TEST_METHOD(ConstructorWithCoordinates_ValidData_Success)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            Assert::IsTrue(rect.IsValid());
        }

        TEST_METHOD(Constructor_InvalidCoordinates_ThrowsCorrectException)
        {
            Rectangle::SetMaxCoordinate(100);
            string expectedMessage = "Invalid rectangle coordinates";
            string actualMessage;
            try {
                Rectangle rect(5, 5, 2, 2);
            }
            catch (const invalid_argument& e) {
                actualMessage = e.what();
            }
            Assert::AreEqual(expectedMessage, actualMessage,
                L"Exception message doesn't match expected");
        }

        TEST_METHOD(Constructor_CoordinatesExceedMax_ThrowsCorrectException)
        {
            Rectangle::SetMaxCoordinate(10);
            const string expectedMsg = "Invalid rectangle coordinates";
            string actualMsg;
            try {
                Rectangle rect(1, 1, 15, 15);
            }
            catch (const invalid_argument& e) {
                actualMsg = e.what();
            }
            Assert::AreEqual(expectedMsg, actualMsg,
                L"Сообщение об ошибке не соответствует ожидаемому");
        }

        TEST_METHOD(ToString_ValidRectangle_ReturnsCorrectString)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            string result = rect.ToString();
            string expected = "Rectangle: TopLeft = (1, 5), BottomRight = (4, 9)";
            Assert::AreEqual(expected, result, L"ToString() returned incorrect string");
        }

        TEST_METHOD(Serialize_ValidRectangle_ReturnsCorrectString)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            string result = Rectangle::Serialize(rect);
            string expected = "Rectangle: TopLeft = (1, 5), BottomRight = (4, 9)";
            Assert::AreEqual(expected, result, L"Serialize() returned incorrect string");
        }

        TEST_METHOD(Deserialize_ValidInput_ReturnsCorrectRectangle)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 4 9");
            Rectangle rect = Rectangle::Deserialize(input);
            Assert::AreEqual(1.0, rect.GetTopLeft().x);
            Assert::AreEqual(5.0, rect.GetTopLeft().y);
            Assert::AreEqual(4.0, rect.GetBottomRight().x);
            Assert::AreEqual(9.0, rect.GetBottomRight().y);
        }

        TEST_METHOD(Deserialize_InvalidInput_ThrowsCorrectException)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 abc 9");
            string expectedMessage = "Invalid input. Requires exactly 4 numbers (x1 y1 x2 y2)";
            string actualMessage;
            try {
                Rectangle::Deserialize(input);
            }
            catch (const invalid_argument& e) {
                actualMessage = e.what();
            }
            Assert::AreEqual(expectedMessage, actualMessage,
                L"Exception message doesn't match expected");
        }

        TEST_METHOD(Deserialize_ExtraCharacters_ThrowsException)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 4 9 extra");
            try {
                Rectangle::Deserialize(input);
                Assert::Fail(L"Expected exception was not thrown");
            }
            catch (const invalid_argument& e) {
                string expected = "Extra characters";
                string actual = e.what();
                Assert::IsTrue(actual.find(expected) != string::npos,
                    L"Exception message should contain: " + wstring(expected.begin(), expected.end()));
            }
            catch (...) {
                Assert::Fail(L"Unexpected exception type thrown");
            }
        }
    };

    TEST_CLASS(FigureTests)
    {
    public:
        TEST_METHOD(Print_ValidRectangle_OutputsCorrectString)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            ostringstream output;
            auto oldCoutBuffer = cout.rdbuf();
            cout.rdbuf(output.rdbuf());
            rect.Print();
            cout.rdbuf(oldCoutBuffer);
            string expected = "Rectangle: TopLeft = (1, 5), BottomRight = (4, 9)\n";
            Assert::AreEqual(expected, output.str(),
                L"Print() output doesn't match expected string");
        }
    };
}


