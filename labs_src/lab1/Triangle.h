#ifndef ICT_HOMEWORK_1_TRIANGLE_H
#define ICT_HOMEWORK_1_TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle(vector<float> sidesLength);
    float calcArea() override;
};

#endif //ICT_HOMEWORK_1_TRIANGLE_H
