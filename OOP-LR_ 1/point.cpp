#include "point.h"

double Point::DistanceBetween(const Point &A) const {
    return sqrt((A.x - x) * (A.x - x) + (A.y - y) * (A.y - y));
}


double Point::GetX() const {
    return x;
}


double Point::GetY() const {
    return y;
}