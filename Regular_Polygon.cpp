//
// Created by 1 on 14.03.2022.
//

#include "Regular_Polygon.h"
Regular_Polygon ::Regular_Polygon(Polygon &a) {
    lenght_= a.get_lenght_();
    array_= a.get_array_();

    a.check_ConvexShape();

    std::cout <<" The Polygon has "<< lenght_ -1 << "vertexes"<< std::endl;

    double temp;
    double first_line = Point::get_LineLength(array_[0],
                                              array_[1]);
    for (int i=2; i< lenght_; i++){
        temp= Point::get_LineLength(array_[i-1], array_[i]);
        if (temp != first_line){
            try{
                throw -6;
            }
            catch (int a){
                std::cerr<<"The Polygon is not regular: " << a << std::endl;

            }
            exit(-6);
        }
    }
    std::cout<< "The polygon is regular" << std::endl;
    get_perimeter();
    get_lenght_();
}