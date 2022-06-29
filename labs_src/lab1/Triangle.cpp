#include "Triangle.h"
#include <cmath>

Triangle::Triangle(vector<float> sidesLength) : Polygon(3, sidesLength, 0.0) {}

float Triangle::calcArea() {
    float perimeter = calcPerimeter();

    float result = sqrt(perimeter
            * (perimeter - this->sidesLength[0])
            * (perimeter - this->sidesLength[1])
            * (perimeter - this->sidesLength[2]));
    return result;
}
