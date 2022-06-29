#pragma once
#ifndef ICT_HOMEWORK_1_CLOSEDPOLYGON_H
#define ICT_HOMEWORK_1_CLOSEDPOLYGON_H

#include "Point.h"
#include "Polygon.h"
#include <vector>

class ClosedPolygon : Polygon
{
public:
    explicit ClosedPolygon(vector <Point> points_);

};

#endif //ICT_HOMEWORK_1_CLOSEDPOLYGON_H
