//
// Created by 1 on 14.03.2022.
//

#ifndef LAB_1_TRAPEZOID_H
#define LAB_1_TRAPEZOID_H


#include "Polygon.h"

class Trapezoid : public Polygon  {
public:
    void parallel_check();

    Trapezoid (Polygon &a){
        lenght_ = a.get_lenght_();
        array_ = a.get_array_();

        if (lenght_ -1 != 4){
            try {
                throw -4;
            }
            catch (int a){
                std::cerr << " Trapezoid has "<< lenght_ -1 << " vertexes instead of 4: " << a <<'\n';

            }
        }
        parallel_check();
    };

    ~Trapezoid()= default;

};


#endif //LAB_1_TRAPEZOID_H
