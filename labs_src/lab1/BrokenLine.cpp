#include "BrokenLine.h"
#include <vector>
#include <cmath>

using namespace std;

BrokenLine::BrokenLine(vector <Point> points) {
    this->points = points;
}

vector <Point> BrokenLine::getPoints() {
    return points;
}

float BrokenLine::calcPerimeter() {
    float result = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        float side = sqrt(pow((points[i + 1].getPoint_X() - points[i].getPoint_X()), 2)
                + pow((points[i + 1].getPoint_Y() - points[i].getPoint_Y()), 2));
        result += side;
    }
    return result;
}