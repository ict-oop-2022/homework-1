#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() {
    this->x = 0;
    this->y = 0;
};

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

Point Point::getPoint() {
    return *this;
}

int Point::getPoint_X() {
    return x;
}

int Point::getPoint_Y() {
    return y;
}