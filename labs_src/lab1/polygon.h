#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "point.h"

#include <vector>

class Polygon: public Shape
{
public:
	Polygon(const std::initializer_list<Point>& points);
	Polygon(const Polygon& other);
	Polygon& operator=(const Polygon& other);

	std::string getName() const override;
	float calcPerimeter() const override;
	float calcArea() const override;

private:
	bool isConvex() const;

protected:
	std::vector<Point> mPoints; // Нужно для правильного многоугольника.
};

#endif