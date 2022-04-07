//
// Created by 1 on 14.03.2022.
//

#include "Trapezoid.h"

void Trapezoid::parallel_check() {
    float k = (array_[3].get_pointY() - array_[4].get_pointY()) /
              (array_[1].get_pointX() - array_[2].get_pointX());
    float k1 = (array_[3].get_pointY() - array_[4].get_pointY()) /
               (array_[1].get_pointX() - array_[2].get_pointX());
    if (k != k1){
        try {throw -7;}
        catch (int a) {
            std::cerr << "The trapezoid lines are not parallel: " << a <<std::endl;
        }
    } else {
        get_perimeter();
        get_square();
    }
}