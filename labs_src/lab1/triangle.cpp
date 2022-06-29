#include "triangle.h"

#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3) {
	mPoints[0] = p1;
	mPoints[1] = p2;
	mPoints[2] = p3;
}
Triangle::Triangle(const Triangle& other) {
	for (int i = 0; i < 3; ++i)
		mPoints[i] = other.mPoints[i];
}
Triangle& Triangle::operator=(const Triangle& other) {
	if (this != &other) {
		for (int i = 0; i < 3; ++i)
			mPoints[i] = other.mPoints[i];
	}

	return *this;
}

std::string Triangle::getName() const {
	return "TRIANGLE";
}

float Triangle::calcPerimeter() const {
	return mPoints[0].distance(mPoints[1]) + mPoints[1].distance(mPoints[2])
		+ mPoints[0].distance(mPoints[2]);
}

float Triangle::calcArea() const {
	return (0.5f * std::abs((mPoints[1].x() - mPoints[0].x()) * (mPoints[2].y() - mPoints[0].y())
	- (mPoints[2].x() - mPoints[0].x()) * (mPoints[1].y() - mPoints[0].y())));
}