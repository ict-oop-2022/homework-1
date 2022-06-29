#ifndef CLION_POLYLINE_H
#define CLION_POLYLINE_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class PolyLine{
public:
    explicit PolyLine(const vector<Point>& tmp) : size(tmp.size()), points(tmp) { //constructor
        if (size < 3) cout << "incorrect data entered" << endl;
        for (int i = 0; i < size - 2; ++i){
            Point ab(points[i + 1].GetX() - points[i].GetX(), points[i + 1].GetY() - points[i].GetY());
            Point bc(points[i + 2].GetX() - points[i + 1].GetX(), points[i + 2].GetY() - points[i + 1].GetY());
            if (ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX() == 0){
                cout << "incorrect data entered" << endl;
            }
        }
    }

    virtual double GetPerimeter() const;
protected:
    vector<Point> points;
    size_t size;
};

#endif //CLION_POLYLINE_H
