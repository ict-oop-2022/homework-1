#ifndef ICT_HOMEWORK_1_POINTLIST_H
#define ICT_HOMEWORK_1_POINTLIST_H

#include "Point.h"
#include <vector>

using namespace std;

class BrokenLine
{
protected:
    vector <Point> points;

public:
    BrokenLine(vector <Point> points);
    vector<Point> getPoints();
    virtual float calcPerimeter();
};

#endif //ICT_HOMEWORK_1_POINTLIST_H
