#pragma once
#include <string>
#include <iostream>

using namespace std;

/*
*@brief Абстрактный базовый класс для геометрических фигур.
* Определяет интерфейс для всех фигур, включая методы сериализации,
* вывода и чтения из потока.
* Не может быть создан напрямую.
*/

class Figure {
public:

    /*
    *@brief Виртуальный деструктор для корректного удаления производных классов.
    */
    virtual ~Figure() = default;

    /*
    *@brief Преобразует фигуру в строковое представление.
    * @return Строку с описанием фигуры.
    */
    virtual string ToString() const = 0;

    /*
    *@brief Читает параметры фигуры из входного потока.
    * @param is Входной поток для чтения.
    */
    virtual void ReadFromStream(istream& is) = 0;

    /**
    * @brief Выводит информацию о фигуре в стандартный вывод.
    */
    void Print() const;
};



