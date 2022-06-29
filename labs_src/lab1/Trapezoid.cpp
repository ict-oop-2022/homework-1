#include "Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(vector<float> sidesLength) : Polygon(4, sidesLength, 0.0) {}

float Trapezoid::calcArea() {
    float result = (sidesLength[0] + sidesLength[1]) / 2;
    result *= sqrt(pow(sidesLength[2], 2)
            - pow((pow(sidesLength[0] - sidesLength[1], 2)
            + pow(sidesLength[2], 2)
            - pow(sidesLength[3], 2))
            / (2 * (sidesLength[0] - sidesLength[1])), 2));
    return result;
}