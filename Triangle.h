#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
public:
    Triangle();
    Triangle(int n, Point *points);

    Triangle(const Triangle& other);
    using PolygonalChain::operator=;
    ~Triangle();

    bool hasRightAngle() const;
};


#endif //TRIANGLE_H