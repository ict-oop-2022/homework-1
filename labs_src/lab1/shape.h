#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// ����� ��������� ��� �����.
class Shape {
public:
	virtual ~Shape() {} // ����������� ���������� ����� ��� ������ �� ������ ������.

	virtual std::string getName() const = 0; // ���������� �������� ������.
	virtual float calcArea() const = 0; // ��������� ������� ������.
	virtual float calcPerimeter() const = 0; // ��������� �������� ������.
};

#endif