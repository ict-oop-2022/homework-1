#ifndef POINT_H
#define POINT_H

// Класс точки.
class Point
{
public:
	Point();
	Point(float x, float y);

	Point(const Point &other);
	Point& operator=(Point other);

	// Операторы равенства для точки.
	bool operator==(const Point& p) const;
	bool operator!=(const Point& p) const;

	float distance(Point other) const;
	float x() const;
	float y() const;
	void setX(float x);
	void setY(float y);

private:
	float mX = 0.f, mY = 0.f;
};

#endif