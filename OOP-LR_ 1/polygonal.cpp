#include "polygonal.h"

double Polygonal::GetPerimeter() const {
    return ClosedPolyLine::GetPerimeter();
}

double Polygonal::GetSquare() const {
    double square = 0;
    const Point& fixed = points[0];
    for (int32_t i = 1; i < size - 1; ++i) {
        Point ab(points[i].GetX() - points[0].GetX(), points[i].GetY() - points[0].GetY());
        Point bc(points[i + 1].GetX() - points[0].GetX(), points[i + 1].GetY() - points[0].GetY());
        square += std::abs(ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX()) / 2;
    }
    return square;
}