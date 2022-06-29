#ifndef CLION_TRAPEZOID_H
#define CLION_TRAPEZOID_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class Trapezoid: public Polygonal{
public:
    explicit Trapezoid(const vector<Point>& tmp) : Polygonal(tmp) {   //constructor
        if (size != 4) {
            cout << "Это не трапеция" << endl;
        }
        Point ab(points[2].GetX() - points[1].GetX(), points[2].GetY() - points[1].GetY());
        Point bc(points[3].GetX() - points[0].GetX(), points[3].GetY() - points[0].GetY());
        if (ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX() == 0){
            const auto save = points[0];
            points[0] = points[1];
            points[1] = points[2];
            points[2] = points[3];
            points[3] = save;
        }
    }
    double GetPerimeter() const override;
    double GetSquare() const override;
};

#endif //CLION_TRAPEZOID_H
