#ifndef CLION_TRIANGLE_H
#define CLION_TRIANGLE_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class Triangle final: public Polygonal{
public:
    explicit Triangle(const vector<Point>& tmp) : Polygonal(tmp) {  //constructor
        if (size != 3) {
            cout << "it isn't a Triangle, incorrect data entered" << endl;
        }
    }
    double GetPerimeter() const override;
    double GetSquare() const override;
};

#endif //CLION_TRIANGLE_H
