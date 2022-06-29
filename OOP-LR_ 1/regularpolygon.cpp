#include "regularpolygon.h"

double RegularPolygon::GetPerimeter() const {
    return size * side_length;
}

double RegularPolygon::GetSquare() const {
    const double pi = M_PI;
    const double R = side_length / 2 / std::sin(pi / size);
    const double r = R * std::cos(pi / size);

    return GetPerimeter() * r / 2;
}