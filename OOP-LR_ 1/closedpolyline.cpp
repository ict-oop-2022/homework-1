#include "closedpolyline.h"

ClosedPolyLine::ClosedPolyLine(const vector<Point> &tmp) :PolyLine(tmp) {
    Point ab(points[0].GetX() - points[size - 1].GetX(), points[0].GetY() - points[size - 1].GetY());
    Point bc(points[1].GetX() - points[0].GetX(), points[1].GetY() - points[0].GetY());
    Point da(points[size - 1].GetX() - points[size - 2].GetX(), points[size - 1].GetY() - points[size - 2].GetY());
    if (ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX() == 0 || ab.GetX() * da.GetY() - ab.GetY() * da.GetX() == 0){
        cout << "Введены неверные данные" << endl;
    }
}
double ClosedPolyLine::GetPerimeter() const {
    double perimeter = PolyLine::GetPerimeter();
    return perimeter + points[0].DistanceBetween(points[size - 1]);
}