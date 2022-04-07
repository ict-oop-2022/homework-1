//
// Created by 1 on 13.03.2022.
//

#include "Polygon.h"

void Polygon::check_ConvexShape() {
    for (int i = 1; i < lenght_ -1; i++) {
        float res =  (array_[i].get_pointX() - array_[i - 1].get_pointX()) *
                     (array_[i + 1].get_pointY() - array_[i].get_pointY()) -
                     (array_[i].get_pointY() - array_[i - 1].get_pointY()) *
                     (array_[i + 1].get_pointX() - array_[i].get_pointX());
        if (res > 0 ){
            try
            {
                throw -3;
            }
            catch (int a){
                std::cerr<< "False, the polygon doesnt convex: "<<a <<'\n';

            }
        }
    }
}