#include "regularpolygon.h"

#include <stdexcept>
#include <vector>

RegularPolygon::RegularPolygon(const std::initializer_list<Point>& points) :
	Polygon(points) {
}

std::string RegularPolygon::getName() const {
	return "REGULAR POLYGON";
}

float RegularPolygon::calcArea() const {
	if (!isRegular())
		throw std::runtime_error("Polygon is not regular!");

	return Polygon::calcArea();
}

// Проверка многоугольника на правильность.
bool RegularPolygon::isRegular() const {
	for (int i = 0; i < mPoints.size() - 2; ++i) {
		Point p1 = mPoints[i]; Point p2 = mPoints[i + 1]; Point p3 = mPoints[i + 2];
		if (p1.distance(p2) != p2.distance(p3))
			return false;
	}

	Point p1 = mPoints[mPoints.size() - 1]; Point p2 = mPoints[0]; Point p3 = mPoints[1];
	if (p1.distance(p2) != p2.distance(p3))
		return false;

	return true;
}
