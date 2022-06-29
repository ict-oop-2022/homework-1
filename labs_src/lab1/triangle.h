#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
#include "shape.h"

class Triangle: public Shape
{
public:
	Triangle(Point p1, Point p2, Point p3);
	Triangle(const Triangle& other);
	Triangle& operator=(const Triangle& other);

	std::string getName() const override;
	float calcPerimeter() const override;
	float calcArea() const override;

private:
	Point mPoints[3];
};

#endif
