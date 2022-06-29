#ifndef CLION_POLYGONAL_H
#define CLION_POLYGONAL_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class Polygonal: protected ClosedPolyLine {
public:
    explicit Polygonal(const vector<Point>& tmp) :ClosedPolyLine(tmp) { //constructor
        double prev_vector_product = 0;
        for (int32_t i = 0; i < size; ++i) {
            const Point ab(points[(i + 1) % size].GetX() - points[i].GetX(), points[(i + 1) % size].GetY() - points[i].GetY());
            const Point bc(points[(i + 2) % size].GetX() - points[(i + 1) % size].GetX(), points[(i + 2) % size].GetY() - points[(i + 1) % size].GetY());
            const auto cur_vector_product = ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX();
            if (cur_vector_product * prev_vector_product < 0) {
                cout << "it isn't a Polygon, incorrect data entered" << endl;
            }
            prev_vector_product = cur_vector_product;
        }
    }
    double GetPerimeter() const override;
    virtual double GetSquare() const;
};

#endif //CLION_POLYGONAL_H
