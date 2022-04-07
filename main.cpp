#include <iostream>
#include "Point.h"
#include "BrokenLine.h"
#include "cmake-build-debug/Lock_BrokenLine.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Trapezoid.h"
#include "Regular_Polygon.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
    Point a(0,0);
    Point b(2,3);
    Point c(6,0);
    Point d(0,0);
//    Point e(0,0);


    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Broken Line" << std::endl;
    BrokenLine Brline;
    Brline.add_point(a);
    Brline.add_point(b);
    Brline.add_point(c);
    Brline.add_point(d);
//    Brline.add_point(e);

    Brline.print_BrokenLine();
    Brline.get_perimeter();

    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Locked Broken Line" << std::endl;
    Lock_BrokenLine first_LockedBrokenLine(Brline);
    first_LockedBrokenLine.get_perimeter();
    first_LockedBrokenLine.print_BrokenLine();

    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Polygon" << std::endl;
    Polygon first_polygon(first_LockedBrokenLine);
    first_polygon.get_perimeter();
    first_polygon.get_square();
    first_polygon.check_ConvexShape();


    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Triangle " << std::endl;
    Triangle first_triangle ( first_polygon);

    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Trapezoid " << std::endl;
    Trapezoid first_trapezoid ( first_polygon);

    std::cout << "**********************************************************************" << std::endl;
    std::cout << "\t Regular Polygon " << std::endl;
    Regular_Polygon first_regularpolygon(first_polygon);
    return 0;
}
