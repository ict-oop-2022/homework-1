//
// Created by 1 on 14.03.2022.
//

#ifndef LAB_1_TRIANGLE_H
#define LAB_1_TRIANGLE_H


#include "Polygon.h"

class Triangle : public Polygon{
public:
    Triangle(Polygon &a){
        lenght_ = a.get_lenght_();
        array_ = a.get_array_();

        if (lenght_ -1 !=3){
            try{
                throw -4;
            }
            catch(int a) {
                std::cerr << "Triangle Has " << lenght_ -1 << " vertexes instead of 3: " << a << '\n';

            }

        }
        else{
            get_perimeter();
            get_square();
        }
    };

        ~Triangle()= default;


};


#endif //LAB_1_TRIANGLE_H
