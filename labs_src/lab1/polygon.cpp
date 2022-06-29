#include "polygon.h"

#include <algorithm> // all_of
#include <stdexcept>

Polygon::Polygon(const std::initializer_list<Point>& points) {
	for (Point p : points)
		mPoints.push_back(p);
}

Polygon::Polygon(const Polygon& other) {
	for (Point p : other.mPoints)
		mPoints.push_back(p);
}

Polygon& Polygon::operator=(const Polygon& other) {
	if (this != &other) {
		for (Point p : other.mPoints)
			mPoints.push_back(p);
	}

	return *this;
}

float Polygon::calcPerimeter() const {
	float perimeter = 0.f;
	
	for (int i = 0; i < mPoints.size() - 1; ++i) {
		perimeter += mPoints[i].distance(mPoints[i + 1]);
	}

	perimeter += mPoints[0].distance(mPoints[mPoints.size() - 1]);

	return perimeter;
}

bool less0(float a) {
	return a <= 0.f;
}

bool greater0(float a) {
	return a >= 0.f;
}

std::string Polygon::getName() const {
	return "POLYGON";
}

float Polygon::calcArea() const {
	if (isConvex() == false)
		throw std::runtime_error("Shape must be convex!");

	float area = 0.f;

	for (int i = 0; i < mPoints.size() - 1; ++i) {
		area += (mPoints[i].x() * mPoints[i + 1].y() - mPoints[i].y() * mPoints[i + 1].x());
	}

	area += (mPoints[0].x() * mPoints[mPoints.size() - 1].y()
		- mPoints[0].y() * mPoints[mPoints.size() - 1].x());

	area = 0.5f * std::abs(area);

	return area;
}

bool Polygon::isConvex() const {
	std::vector<float> crossProducts;
	for (int i = 1; i < mPoints.size() - 1; ++i) {
		crossProducts.push_back(mPoints[i].x() * mPoints[i + 1].y() - mPoints[i].y() * mPoints[i + 1].x());
	}
	/*crossProducts.push_back(mPoints[0].x() * mPoints[mPoints.size() - 1].y()
		- mPoints[0].y() * mPoints[mPoints.size() - 1].x());*/

	bool convex = std::all_of(crossProducts.cbegin(), crossProducts.cend(), less0);
	if (convex == false) {
		convex = std::all_of(crossProducts.cbegin(), crossProducts.cend(), greater0);
	}

	return convex;
}