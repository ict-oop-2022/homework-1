#include "linestrip.h"

LineStrip::LineStrip() {
}

LineStrip::LineStrip(const std::initializer_list<Point>& ptList) {
	for (const Point p : ptList)
		mPoints.push_back(p);
}

LineStrip::LineStrip(const LineStrip& other) {
	for (const Point p : other.mPoints)
		mPoints.push_back(p);
}

void LineStrip::addPoint(Point p) {
	mPoints.push_back(p);
}

int LineStrip::getPointsCount() const {
	return mPoints.size();
}

void LineStrip::makeLooped() {
	if (mPoints.front() != mPoints.back())
		mPoints.push_back(mPoints.front());
}

bool LineStrip::isLooped() const {
	return (mPoints.front() == mPoints.back());
}

LineStrip& LineStrip::operator=(const LineStrip& other) {
	if (this != &other) {
		mPoints.clear();
		for (const Point p : other.mPoints)
			mPoints.push_back(p);
	}

	return *this;
}
