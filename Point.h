#pragma once
#include <iostream>

/**
 * @brief Класс для работы с точками на плоскости.
 * Хранит координаты точки и предоставляет основные операции:
 * сравнение, ввод/вывод, арифметические операции.
 */
class Point {
public:
    unsigned int x, y;

    /**
    * @brief Конструктор точки
    * @param x Координата X (по умолчанию 0)
    * @param y Координата Y (по умолчанию 0)
    */
    Point(unsigned int x = 0, unsigned int y = 0);

    /**
    * @brief Оператор сравнения точек на равенство.
    * @param other Точка для сравнения.
    * @return true если точки идентичны.
    */
    bool operator==(const Point& other) const;

    /**
   * @brief Оператор сравнения точек на неравенство.
   * @param other Точка для сравнения.
   * @return true если точки различаются.
   */
    bool operator!=(const Point& other) const;

    /**
    * @brief Оператор вывода точки в поток.
    * @param os Выходной поток.
    * @param p Точка для вывода.
    * @return Поток после вывода.
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
    * @brief Оператор ввода точки из потока.
    * @param is Входной поток.
    * @param p Точка для заполнения.
    * @return Поток после ввода.
    */
    friend std::istream& operator>>(std::istream& is, Point& p);


    /**
    * @brief Смещает точку на заданное значение.
    * @param value Величина смещения.
    * @return Новая точка с увеличенными координатами.
    */
    Point operator+(unsigned int value) const;

    /**
    * @brief Уменьшает координаты точки на заданное значение.
    * @param value Величина уменьшения.
    * @return Новая точка или (0,0) если value больше координат.
    */
    Point operator-(unsigned int value) const;
};