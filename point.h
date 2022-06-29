#ifndef POINT_H
#define POINT_H

#include <cmath>
//fixed remove russian letters
class Point {
private:
    double x_;
    double y_;
public:
    Point();                                      // default constructor
    Point(double x, double y);                    // constructor from coordinates

    Point(const Point& other);                    // copy constructor
    Point& operator=(const Point& other);         // assignment operator
    ~Point() { }                                  // destructor

    double getX() const;
    double getY() const;
    double getDistance(const Point& other) const;
};



#endif //POINT_H