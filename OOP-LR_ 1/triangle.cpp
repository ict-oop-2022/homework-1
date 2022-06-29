#include "triangle.h"

double Triangle::GetPerimeter() const {
    return Polygon::GetPerimeter();
}

double Triangle::GetSquare() const {
    Point ab(points[1].GetX() - points[0].GetX(), points[1].GetY() - points[0].GetY());
    Point bc(points[2].GetX() - points[0].GetX(), points[2].GetY() - points[0].GetY());
    return std::abs(ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX()) / 2;
}
