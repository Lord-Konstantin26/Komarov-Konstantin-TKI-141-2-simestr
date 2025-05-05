#include "CppUnitTest.h"
#include "../Task3.decision/Figure.h"
#include "../Task3.decision/Rectangle.h"
#include "../Task3.decision/Point.h"

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
            Assert::AreEqual(10u, p.x);
            Assert::AreEqual(20u, p.y);
        }

        TEST_METHOD(EqualityOperator_EqualPoints_ReturnsTrue)
        {
            Point p1(5, 10);
            Point p2(5, 10);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentPoints_ReturnsFalse)
        {
            Point p1(5, 10);
            Point p2(5, 15);
            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(AdditionOperator_ValidValue_ReturnsCorrectPoint)
        {
            Point p(10, 20);
            Point result = p + 5;
            Assert::AreEqual(15u, result.x);
            Assert::AreEqual(25u, result.y);
        }

        TEST_METHOD(SubtractionOperator_ValidValue_ReturnsCorrectPoint)
        {
            Point p(10, 20);
            Point result = p - 5;
            Assert::AreEqual(5u, result.x);
            Assert::AreEqual(15u, result.y);
        }

        TEST_METHOD(SubtractionOperator_TooLargeValue_ReturnsZeroPoint)
        {
            Point p(3, 4);
            Point result = p - 5;
            Assert::AreEqual(0u, result.x);
            Assert::AreEqual(0u, result.y);
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

        TEST_METHOD(Constructor_InvalidCoordinates_ThrowsException)
        {
            Rectangle::SetMaxCoordinate(100);
            auto func = [] { Rectangle rect(5, 5, 2, 2); };
            Assert::ExpectException<invalid_argument>(func);
        }

        TEST_METHOD(Constructor_CoordinatesExceedMax_ThrowsException)
        {
            Rectangle::SetMaxCoordinate(10);
            auto func = [] { Rectangle rect(1, 1, 15, 15); };
            Assert::ExpectException<invalid_argument>(func);
        }

        TEST_METHOD(ToString_ValidRectangle_ReturnsCorrectString)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            string result = rect.ToString();
            Assert::IsTrue(result.find("TopLeft = (1, 5)") != string::npos);
            Assert::IsTrue(result.find("BottomRight = (4, 9)") != string::npos);
        }

        TEST_METHOD(Serialize_ValidRectangle_ReturnsCorrectString)
        {
            Rectangle::SetMaxCoordinate(100);
            Rectangle rect(1, 5, 4, 9);
            string result = Rectangle::Serialize(rect);
            Assert::IsTrue(result.find("TopLeft = (1, 5)") != string::npos);
            Assert::IsTrue(result.find("BottomRight = (4, 9)") != string::npos);
        }

        TEST_METHOD(Deserialize_ValidInput_ReturnsCorrectRectangle)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 4 9");
            Rectangle rect = Rectangle::Deserialize(input);
            Assert::AreEqual(1u, rect.topLeft.x);
            Assert::AreEqual(5u, rect.topLeft.y);
            Assert::AreEqual(4u, rect.bottomRight.x);
            Assert::AreEqual(9u, rect.bottomRight.y);
        }

        TEST_METHOD(Deserialize_InvalidInput_ThrowsException)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 abc 9");
            auto func = [&input] { Rectangle::Deserialize(input); };
            Assert::ExpectException<invalid_argument>(func);
        }

        TEST_METHOD(Deserialize_ExtraCharacters_ThrowsException)
        {
            Rectangle::SetMaxCoordinate(100);
            istringstream input("1 5 4 9 extra");
            auto func = [&input] { Rectangle::Deserialize(input); };
            Assert::ExpectException<invalid_argument>(func);
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

            Assert::IsTrue(output.str().find("TopLeft = (1, 5)") != string::npos);
            Assert::IsTrue(output.str().find("BottomRight = (4, 9)") != string::npos);
        }
    };
}
