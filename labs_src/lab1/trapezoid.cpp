#include "trapezoid.h"

#include <cmath>

Trapezoid::Trapezoid(Point p1, Point p2, Point p3, Point p4):
	Shape() {
	mPoints[0] = p1; mPoints[1] = p2;
	mPoints[2] = p3; mPoints[3] = p4;
}

Trapezoid::Trapezoid(const Trapezoid& other) {
	for (int i = 0; i < 4; ++i) {
		mPoints[i] = other.mPoints[i];
	}
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			mPoints[i] = other.mPoints[i];
		}
	}

	return *this;
}

std::string Trapezoid::getName() const {
	return "TRAPEZOID";
}

float Trapezoid::calcPerimeter() const {
	return (mPoints[0].distance(mPoints[1]) + mPoints[1].distance(mPoints[2])
		+ mPoints[2].distance(mPoints[3]) + mPoints[0].distance(mPoints[3]));
}

float Trapezoid::calcArea() const {
	const float h = mPoints[1].y() - mPoints[0].y();
	const float base1 = mPoints[1].distance(mPoints[2]);
	const float base2 = mPoints[0].distance(mPoints[3]);
	return (0.5f * (base1 + base2) * h);
}