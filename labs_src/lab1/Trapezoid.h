#ifndef ICT_HOMEWORK_1_TRAPEZOID_H
#define ICT_HOMEWORK_1_TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon
{
public:
    Trapezoid(vector<float> sideLength);
    float calcArea() override;
};

#endif //ICT_HOMEWORK_1_TRAPEZOID_H
