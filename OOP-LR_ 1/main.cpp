#include "point.h"
#include "polyline.h"
#include "closedpolyline.h"
#include "polygonal.h"
#include "triangle.h."
#include "trapezoid.h"
#include "regularpolygon.h"

#include <iostream>
int main(){
    Point S(-3, -2);
    Point S1(3, 4);
    Point S3(6, 10);
    std::vector<Point> a = {S, S1, S3};
    PolyLine SSS(a);
    ClosedPolyLine AAA(a);
    vector<PolyLine*> array = {&SSS, reinterpret_cast<PolyLine*>(&AAA)};
    for (auto element : array)
        cout << element->GetPerimeter() << endl;
}