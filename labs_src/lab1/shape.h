#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Общий интерфейс для фигур.
class Shape {
public:
	virtual ~Shape() {} // Виртуальный деструктор нужен для защиты от утечки памяти.

	virtual std::string getName() const = 0; // Возвращает название фигуры.
	virtual float calcArea() const = 0; // Вычисляет площадь фигуры.
	virtual float calcPerimeter() const = 0; // Вычисляет периметр фигуры.
};

#endif