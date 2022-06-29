#ifndef CLOSED_POLYGONAL_CHAIN_H
#define CLOSED_POLYGONAL_CHAIN_H

#include "PolygonalChain.h"

class ClosedPolygonalChain : public PolygonalChain {
public:
    ClosedPolygonalChain();
    ClosedPolygonalChain(int n, Point *points);

    ClosedPolygonalChain(const ClosedPolygonalChain &other);
    using PolygonalChain::operator=;
    ~ClosedPolygonalChain();

    double perimeter() const override;
};


#endif //CLOSED_POLYGONAL_CHAIN_H