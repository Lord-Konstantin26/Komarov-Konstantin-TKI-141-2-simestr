#pragma once
#include "Figure.h"
#include "Point.h"

using namespace std;

/*
* @brief Класс прямоугольника, наследующий от Figure.
* Представляет прямоугольник, заданный двумя точками :
* верхней левой и нижней правой.Поддерживает валидацию,
* сериализацию и десериализацию.
*/
class Rectangle : public Figure {
private:
    Point topLeft;
    Point bottomRight;
    static int maxCoord;

public:
    /*
    * @brief Конструктор через точки.
    * @param tl Верхняя левая точка.
    * @param br Нижняя правая точка.
    * @throw invalid_argument Если координаты некорректны.
    */
    Rectangle(const Point& tl, const Point& br);

    /*
    * @brief Конструктор через координаты.
    * @param x1 X верхней левой точки.
    * @param y1 Y верхней левой точки.
    * @param x2 X нижней правой точки.
    * @param y2 Y нижней правой точки.
    * @throw invalid_argument Если координаты некорректны.
    */
    Rectangle(double x1, double y1, double x2, double y2);

    /*
    * @brief Проверяет валидность прямоугольника.
    * @return true если координаты корректны, иначе false.
    */
    bool IsValid() const;

    /*
    * @brief Преобразует прямоугольник в строку.
    * @return Строковое представление прямоугольника.
    */
    string ToString() const override;

    /*
    * @brief Читает прямоугольник из потока.
    * @param is Входной поток.
    * @throw runtime_error При некорректных данных.
    */
    void ReadFromStream(istream& is) override;

    /*
    * @brief Сериализует прямоугольник в строку.
    * @param rect Прямоугольник для сериализации.
    * @return Строковое представление.
    */
    static string Serialize(const Rectangle& rect);

    /*
    * @brief Десериализует прямоугольник из потока.
    * @param is Входной поток.
    * @return Объект Rectangle.
    * @throw invalid_argument При некорректном вводе.
    */
    static Rectangle Deserialize(istream& is);

    /**
    * @brief Устанавливает максимальное значение координат.
    * @param max Новое максимальное значение.
    */
    static void SetMaxCoordinate(double max);

    /*
    * @brief Получает верхнюю левую точку прямоугольника.
    * @return Константную ссылку на точку topLeft.
    */
    const Point& GetTopLeft() const;

    /*
    * @brief Получает нижнюю правую точку прямоугольника.
    * @return Константную ссылку на точку bottomRight.
    */
    const Point& GetBottomRight() const;
};



