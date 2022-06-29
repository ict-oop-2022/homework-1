#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "point.h"
#include "shape.h"

// Трапеция.
class Trapezoid: public Shape
{
public:
	Trapezoid(Point p1, Point p2, Point p3, Point p4);
	Trapezoid(const Trapezoid& other);
	Trapezoid& operator=(const Trapezoid& other);

	std::string getName() const override;
	float calcPerimeter() const override;
	float calcArea() const override;

private:
	Point mPoints[4];
};

#endif
