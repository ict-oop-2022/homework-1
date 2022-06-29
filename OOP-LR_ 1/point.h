#ifndef CLION_POINT_H
#define CLION_POINT_H


#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;


class Point{
public:
    Point(double x, double y) : x{x}, y{y} {} //constructor
    Point(const Point& tmp): x(tmp.x), y(tmp.y) {}             //copy constructor
    Point& operator = (const Point& tmp){                      //assignment operator
        x = tmp.x;
        y = tmp.y;
        return *this;
    }

    double DistanceBetween(const Point& A) const;
    double GetX() const;
    double GetY() const;
private:
    double x;
    double y;
};
#endif //CLION_POINT_H