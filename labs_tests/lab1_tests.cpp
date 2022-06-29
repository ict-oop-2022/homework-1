#include <gtest/gtest.h>

#include "lab1/BrokenLine.h"
#include "lab1/Triangle.h"
#include <cmath>
using namespace std;

TEST(CreateBrokenLine, PerimeterCalculatedCorrectly) {
    BrokenLine line({ Point {0,0},  Point {0,2},  Point {2,0} , Point{ 2,2 } });
    float perimeter = line.calcPerimeter();
    float res = 4 + sqrt(8);
    ASSERT_FLOAT_EQ(perimeter, res);
}

TEST(CreateSharpTriangle, RightTriangleCheckFailed_ThrowException) {
    Triangle tr({ 3, 3, 3 });
    float perimeter = tr.calcPerimeter();
    ASSERT_EQ(perimeter, 9);
    cout << perimeter << endl;
    float area = tr.calcArea();
    cout << area << endl;
}


