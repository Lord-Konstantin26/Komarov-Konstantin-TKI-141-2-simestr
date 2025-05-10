#pragma once
#include "Point.h"

/**
* @brief Класс, представляющий квадрат, заданный тремя точками.
*/
class Square 
{
private:
	Point p1, p2, p3, p4;

	/**
	* @brief Сторона квадрата.
	*/
	double side;

	/**
	* @brief Вычисляет квадрат расстояния между двумя точками.
	* @param a Первая точка.
	* @param b Первая точка.
	* @return Квадрат расстояния между точками a и b.
	*/
	double distanceSquared() const;

	/**
	* @brief Проверяет, лежат ли три точки на одной прямой.
	* @param a Первая точка.
	* @param b Вторая точка.
	* @param c Третья точка.
	* @return true, если точки лежат на одной прямой, иначе false.
	*/
	bool yesCollinear() const;

	/**
	* @brief Проверяет, образуют ли три точки квадрат.
	* @param a Первая точка.
	* @param b Вторая точка.
	* @param c Третья точка.
	* @return true, если точки образуют квадрат, иначе false.
	*/
	bool yesSquare() const;

	/**
	* @brief Находит четвертую точку квадрата по известным трем точкам.
	* @param a Первая точка.
	* @param b Вторая точка.
	* @param c Третья точка.
	*/
	Point findFourthPoint() const;

	/**
	* @brief Вычисляет длину стороны квадрата.
	* @return Длина стороны квадрата
	*/
	double sideLeinght() const;

public:

	/**
	* @brief Конструктор для инициализации квдрата тремя точками.
	* @param p1 Первая точка.
	* @param p2 Вторая точка.
	* @param p3 Третья точка.
	*/
	Square(Point p1, Point p2, Point p3);

	/**
	* @brief Функция возврата значения длины стороны квадрата.
	* @return Возвращает значение длины стороны квадрата.
	*/
	double getSide() const;

	/**
	* @brief Вычисляет периметр квадрата.
	* @return Периметр квалрата.
	*/
	double perimetr() const;

	/**
	* @brief Вычисляет площадь квадрата.
	* @return Площадь квадрата.
	*/
	double area() const;

	/**
	* @brief Выводит координаты всех точек квадрата на экран.
	*/
	void printPoints() const;
};
