#pragma once

/**
* @brief Класс, представляющий точку на плоскости.
*/
class Point 
{
public:
	double x, y;
	
	/**
	* @brief Конструктор для инициализации точки.
	* @param x Координаты х (по умолчанию 0).
	* @param x Координаты y (по умолчанию 0).
	*/
	Point(const double x = 0, const double y = 0);

	/**
	* @brief Ввод координат с клавиатуры.
	*/
	void input();

	/**
	* @brief Вывод координат точки на экран.
	*/
	void print() const;

};