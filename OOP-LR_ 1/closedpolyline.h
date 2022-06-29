#include <cmath>
#ifndef CLION_CLOSEDPOLYLINE_H
#define CLION_CLOSEDPOLYLINE_H

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using std::vector, std::cout, std::endl;

class ClosedPolyLine: public PolyLine{            //protected(reinterpret cast); public(static cast)     -------
public:
    explicit ClosedPolyLine(const vector<Point>& tmp); //constructor
    double GetPerimeter() const override;
};
#endif //CLION_CLOSEDPOLYLINE_H
