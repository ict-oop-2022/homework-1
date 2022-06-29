#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H

#include "polygon.h"

// Класс правильного многоугольника.
class RegularPolygon: public Polygon
{
public:
	RegularPolygon(const std::initializer_list<Point>& points);

	std::string getName() const override;
	float calcArea() const override;

private:
	bool isRegular() const;
};

#endif
