#include "Polygon.h"
#include <iostream>
#include <vector>
#include <cmath>

Polygon::Polygon(int numberOfSides, vector<float> sideLength, float radius = 0.0) {
    this->numberOfSides = numberOfSides;
    this->sidesLength = sideLength;
    this->radius = radius;
}

Polygon::Polygon(vector<Point> points_) {
    this->points = points_;
}

float Polygon::calcPerimeter() {
    float result = 0;
    for (auto side : sidesLength) {
        result += side;
    }
    return result;
}

float Polygon::calcArea() {
    if (radius == 0.0)
        return 0;
    float perimeter = calcPerimeter();
    float result = 0.5 * perimeter * radius;
    return result;
}

float Polygon::calcPerimeterByPoints() {
    float result = 0.0;
    for (int i = 0; i < points.size(); i++) {
        float side = 0.0;
        if(i != points.size() - 1)
            side = sqrt(pow((points[i + 1].getPoint_X() - points[i].getPoint_X()), 2)
                    + pow((points[i + 1].getPoint_Y() - points[i].getPoint_Y()), 2));
        else
            side = sqrt(pow((points[i].getPoint_X() - points[0].getPoint_X()), 2)
                    + pow((points[i].getPoint_Y() - points[0].getPoint_Y()), 2));
        result += side;
    }
    return result;
}

float Polygon::calcAreaByPoints() {
    float result = 0;
    for (int i = 0; i < points.size(); i++) {
        if (i != points.size() - 1)
            result += points[0].getPoint_X() * points[i + 1].getPoint_Y()
                    - points[i + 1].getPoint_X() * points[i].getPoint_Y();
        else
            result += points[i].getPoint_X() * points[0].getPoint_Y()
                    - points[0].getPoint_X() * points[i].getPoint_Y();
    }
    if (result < 0)
        result *= (-1);
    return result / 2;
}