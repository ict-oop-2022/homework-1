//
// Created by 1 on 13.03.2022.
//

#ifndef LAB_1_POLYGON_H
#define LAB_1_POLYGON_H


#include "cmake-build-debug/Lock_BrokenLine.h"

class Polygon : public Lock_BrokenLine{

public:
    void check_ConvexShape();

    Polygon ( Lock_BrokenLine &a) {
        lenght_ = a.get_lenght_();
        array_ = a.get_array_();

        check_ConvexShape();
        std::cout << " The Polygon has " << lenght_ - 1 << " vertexes " << std::endl;
    }

    virtual void get_square() const {
        int n = lenght_ - 1;
        double sum1 = 0;
        double sum2 = 0;
        double result;
        for (int i = 0; i < n; i++) {
            sum1 = sum1 + array_[i].get_pointX() * array_[i + 1].get_pointY();
        }
        for (int i = 0; i < n; i++){
            sum2 = sum2 + array_[i + 1].get_pointX() * array_[i].get_pointY();
        }

        result = 0.5 * abs(sum1 - sum2 + array_[n].get_pointX() * array_[0].get_pointY()
                           - array_[0].get_pointX() * array_[n].get_pointY());
        std::cout << "The square of Polygon = " << result << std::endl;
    }
        Polygon(){};

        ~Polygon()=default;

    };




#endif //LAB_1_POLYGON_H
