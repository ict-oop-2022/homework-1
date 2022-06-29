#ifndef LINESTRIP_H
#define LINESTRIP_H

#include "point.h"

#include <vector>

// �������.
class LineStrip
{
public:
	LineStrip();
	LineStrip(const std::initializer_list<Point> &ptList);
	LineStrip(const LineStrip& other);

	void addPoint(Point p);
	int getPointsCount() const;
	void makeLooped(); // ������ ������ �������� ������� �����.
	bool isLooped() const; // ���������, �������� �� �������.

	LineStrip& operator=(const LineStrip& other);

private:
	std::vector<Point> mPoints;
};

#endif
