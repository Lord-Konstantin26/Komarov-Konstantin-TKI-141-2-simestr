#pragma once
#include <string>
#include <iostream>

/**
* @brief Абстрактный базовый класс для геометрических фигур.
* Определяет интерфейс для всех фигур, включая методы сериализации,
* вывода и чтения из потока.
* Не может быть создан напрямую.
*/

class Figure {
public:

    /**
     * @brief Виртуальный деструктор для корректного удаления производных классов.
     */
    virtual ~Figure() = default;

    /**
     * @brief Преобразует фигуру в строковое представление.
     * @return Строку с описанием фигуры.
     */
    virtual std::string ToString() const = 0;

    /**
    * @brief Читает параметры фигуры из входного потока.
    * @param is Входной поток для чтения.
    */
    virtual void ReadFromStream(std::istream& is) = 0;

    /**
    * @brief Выводит информацию о фигуре в стандартный вывод.
    */
    virtual void Print() const;
};