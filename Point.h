//
// Created by 1 on 07.03.2022.
//

#ifndef LAB_1_POINT_H
#define LAB_1_POINT_H


#include <cmath>
#include <iostream>

class Point{
private:
    float x_;
    float y_;

public:
    /// Default constructor
    Point(){
        x_ = 0.0;
        y_ = 0.0;
    }

    /// Constructor with parameters
    Point(float x, float y){
        x_ = x;
        y_ = y;
    }

    /// Assignment operator
    Point& operator= (const Point &point){
        x_ = point.x_;
        y_ = point.y_;
        return *this;
    }


    /// Copy constructor
    Point(const Point &point){
        x_ = point.x_;
        y_ = point.y_;
    }

    bool operator==(const Point &a) const{
        if (x_ == a.get_pointX() && y_ == a.get_pointY()){
            return true;
        }
        return false;
    }


    void set_point(float x, float y){
        this -> x_ = x;
        this -> y_ = y;
    };

    float get_pointX() const{
        return x_;
    }

    float get_pointY() const{
        return y_;
    }
    ///for finding the length of line
    static double get_LineLength(Point &a1, Point &a2){
        return sqrt(pow((a2.get_pointX() - a1.get_pointX()), 2) +
                    pow((a2.get_pointY() - a1.get_pointY()), 2));
    }

    ~Point()= default;
};



#endif //LAB_1_POINT_H
