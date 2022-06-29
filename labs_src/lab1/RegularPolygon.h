#ifndef ICT_HOMEWORK_1_REGULARPOLYGON_H
#define ICT_HOMEWORK_1_REGULARPOLYGON_H

#include "Polygon.h"

class RegularPolygon : Polygon
{
private:
    vector <float> sideLength;
public:
    RegularPolygon(int numberOfSides, vector<float> sidesLength, float radius);
};

#endif //ICT_HOMEWORK_1_REGULARPOLYGON_H
