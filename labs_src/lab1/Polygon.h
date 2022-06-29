#pragma once
#ifndef ICT_HOMEWORK_1_POLYGON_H
#define ICT_HOMEWORK_1_POLYGON_H

#include <iostream>
#include <vector>
#include "BrokenLine.h"
using namespace std;

class Polygon
{
protected:
    int numberOfSides;
    vector<float> sidesLength;
    vector<Point> points;
    float radius;
public:
    Polygon(int sides, vector<float> sidesLength, float radius);
    explicit Polygon(vector<Point> points);
    float calcPerimeter();
    virtual float calcArea();
    float calcPerimeterByPoints();
    float calcAreaByPoints();
};

#endif //ICT_HOMEWORK_1_POLYGON_H
