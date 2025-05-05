#pragma once
#include "Figure.h"
#include "Point.h"

using namespace std;

/**
* @brief Класс прямоугольника, наследующий от Figure.
*
* Представляет прямоугольник, заданный двумя точками:
* верхней левой и нижней правой. Поддерживает валидацию,
* сериализацию и десериализацию.
*/
class Rectangle : public Figure {
private:
    Point topLeft;
    Point bottomRight;
    static unsigned int maxCoord;

public:
    /**
    * @brief Конструктор через точки.
    * @param tl Верхняя левая точка.
    * @param br Нижняя правая точка.
    * @throw std::invalid_argument Если координаты некорректны.
    */
    Rectangle(const Point& tl, const Point& br);

    /**
    * @brief Конструктор через координаты.
    * @param x1 X верхней левой точки.
    * @param y1 Y верхней левой точки.
    * @param x2 X нижней правой точки.
    * @param y2 Y нижней правой точки.
    * @throw std::invalid_argument Если координаты некорректны.
    */
    Rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

    /**
    * @brief Проверяет валидность прямоугольника.
    * @return true если координаты корректны, иначе false.
    */
    bool IsValid() const;

    /**
    * @brief Преобразует прямоугольник в строку.
    * @return Строковое представление прямоугольника.
    */
    std::string ToString() const override;

    /**
    * @brief Читает прямоугольник из потока.
    * @param is Входной поток.
    * @throw std::runtime_error При некорректных данных.
    */
    void ReadFromStream(istream& is) override;

    /**
    * @brief Сериализует прямоугольник в строку.
    * @param rect Прямоугольник для сериализации.
    * @return Строковое представление.
    */
    static std::string Serialize(const Rectangle& rect);

    /**
    * @brief Десериализует прямоугольник из потока.
    * @param is Входной поток.
    * @return Объект Rectangle.
    * @throw std::invalid_argument При некорректном вводе.
    */
    static Rectangle Deserialize(std::istream& is);

    /**
    * @brief Устанавливает максимальное значение координат.
    * @param max Новое максимальное значение.
    */
    static void SetMaxCoordinate(unsigned int max);
};