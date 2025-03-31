#pragma once

/**
* @brief Класс, представляющий точку на плоскости.
*/
class Point 
{
public:

	/**
	* @brief Координаты x,y точки.
	*/
	double x, y;
	
	/**
	* @brief Конструктор для инициализации точки.
	* @param x Координаты х (по умолчанию 0).
	* @param x Координаты y (по умолчанию 0).
	*/
	Point(const double x = 0.0, const double y = 0.0);

	/**
	* @brief Функция возврата значения координаты х точки.
	* @return Возвращает значение координаты х точки
	*/
	double getX() const;

	/**
    * @brief Функция возврата значения координаты х точки.
    * @return Возвращает значение координаты х точки
    */
	double  getY() const;

	/**
	* @brief Вывод координат точки на экран.
	*/
	void print() const;

};

/**
*@brief Функция переопределения оператора == .
* @return Возвращает результат проверки совпадения точек.
*/
bool operator==(const Point& p1, const Point& p2);

/**
* @brief Функция переопределения оператора !=.
* @return Возвращает результат проверки несовпадения точек.
*/
bool operator!=(const Point& p1, const Point& p2);

