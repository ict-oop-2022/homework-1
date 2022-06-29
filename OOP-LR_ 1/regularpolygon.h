#ifndef CLION_REGULARPOLYGON_H
#define CLION_REGULARPOLYGON_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class RegularPolygon : public Polygonal {
public:
    explicit RegularPolygon(const std::vector<Point>& tmp):Polygon(tmp), side_length(points[0].DistanceBetween(points[1])) {
        for (int i = 1; i < size; ++i) {
            const double cur_length = points[i].DistanceBetween(points[(i + 1) % size]);
            if (side_length != cur_length) {
                cout << "Это не правильный многоугольник";
            }
        }
    }
    double GetPerimeter() const override;
    double GetSquare() const override;
private:
    double side_length;
};

#endif //CLION_REGULARPOLYGON_H
