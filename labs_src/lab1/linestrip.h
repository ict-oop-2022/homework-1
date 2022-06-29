#ifndef LINESTRIP_H
#define LINESTRIP_H

#include "point.h"

#include <vector>

// Ломаная.
class LineStrip
{
public:
	LineStrip();
	LineStrip(const std::initializer_list<Point> &ptList);
	LineStrip(const LineStrip& other);

	void addPoint(Point p);
	int getPointsCount() const;
	void makeLooped(); // Данная фигура замыкает ломаную линию.
	bool isLooped() const; // Указывает, замкнута ли ломаная.

	LineStrip& operator=(const LineStrip& other);

private:
	std::vector<Point> mPoints;
};

#endif
