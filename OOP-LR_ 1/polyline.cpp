#include "polyline.h"
double PolyLine::GetPerimeter() const {
    double perimeter = 0;
    for (int i = 0; i < size - 1; ++i){
        perimeter += points[i].DistanceBetween(points[i + 1]);
    }
    return perimeter;
}