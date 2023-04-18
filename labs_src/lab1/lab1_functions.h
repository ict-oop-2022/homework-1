#pragma once


#include <iostream>
#include <vector>
#include <cmath>

class Point {
public:
    Point();
    Point(float a, float b);
    ~Point();
    Point& operator=(const Point& object);
    Point(const Point& object);
    friend std::ostream& operator<<(std::ostream& stream, Point& obj);
    float x = 0, y = 0;
};

bool operator==(const Point& object1, const Point& object2);

float distance(const Point& a, const Point& b);

class Polyline {
public:
    Polyline();
    ~Polyline();
    Polyline(const Polyline& p);
    void push_back(float xp, float yp);
    void push_back(Point p);
    int getLength() const;
    Point& operator[](int i);
    const std::vector<Point> getCoords() const;
    Polyline& operator=(const Polyline& object);
    friend std::ostream& operator<<(std::ostream& stream, Polyline& obj);
    float getPerimeter() const;
    void clearCoords();

private:
    std::vector<Point> coords;
};

class ClosedPolyline : public Polyline {
public:
    float getPerimeter();
};

bool isParallel(Point a1, Point a2, Point b1, Point b2);

class Polygon : public ClosedPolyline {
public:
    float getArea();
    bool isTrapezoid();
};

class Triangle : public Polygon {
public:
    void push_back(Point a);
};

class Trapezoid : public Polygon {
public:
    Trapezoid();
    Trapezoid(std::vector<Point> v);
};

class RegularPolygon : public Polygon {
public:
    RegularPolygon();
    RegularPolygon(int n, float r, float x, float y);
};

