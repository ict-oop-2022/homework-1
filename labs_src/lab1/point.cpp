#include "point.h"

#include <cmath>

Point::Point() {
	mX = 0.f; mY = 0.f;
}

Point::Point(float x, float y) {
	mX = x; mY = y;
}

Point::Point(const Point &other) {
	mX = other.mX; mY = other.mY;
}

Point& Point::operator=(Point other) {
	if (this != &other)
		mX = other.mX; mY = other.mY;

	return *this;
}

bool Point::operator==(const Point& other) const {
	return (mX == other.mX && mY == other.mY);
}

bool Point::operator!=(const Point& other) const {
	return !(*this == other);
}

float Point::distance(Point other) const {
	return std::sqrt(std::pow(other.mX -mX, 2.f) + std::pow(other.mY - mY, 2.f));
}

float Point::x() const {
	return mX;
}

float Point::y() const {
	return mY;
}

void Point::setX(float x) {
	mX = x;
}

void Point::setY(float y) {
	mY = y;
}
