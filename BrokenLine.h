//
// Created by 1 on 13.03.2022.
//

#ifndef LAB_1_BROKENLINE_H
#define LAB_1_BROKENLINE_H


#include "Point.h"

class BrokenLine {
protected:
    int lenght_;
    Point *array_;

public:
    /// Default constructor
    BrokenLine(){
        lenght_ =0;
        array_ = new Point[lenght_];
    }
    /// Assignment operator
    BrokenLine& operator = (const BrokenLine &obj){
        lenght_ = obj.lenght_;
        array_ = obj.array_;
        return *this;
    }
    /// Copy constructor
    BrokenLine (const BrokenLine &obj){
        lenght_ = obj.lenght_;
        array_ = obj.array_;
    }

    void check_locked() const {
        if (array_ [0]== array_[lenght_ -1]) {
            std::cout << "True, the line is locked" << std::endl;
        }
        else {
            try
            {
                throw -1;
            }
            catch (int a)
            {
                std::cerr << "FALSE, the line doesn't locked: " << a << '\n';
            }

        }
    }

    void add_point(Point &obj){
        Point* arr= new Point[lenght_ +1];
        for (int i= 0; i < lenght_; i++){
            arr [i] = array_[i];
        }
        arr[lenght_] = obj;
        delete[] array_;
        this ->array_ = arr;

        lenght_++;
    }

    virtual float get_perimeter() const{
        float result =0;
        for(int i = 1; i< lenght_; i++){
            result += Point::get_LineLength(array_[i - 1], array_[i]);

        }
        std::cout << " the perimeter is: " << result << std::endl;
        return result;
    }

    void print_BrokenLine() const{
        for (int i =0; i < lenght_; i++){
            std::cout << "( " << array_[i].get_pointX() << " ; " << array_[i].get_pointY() << " ) " << std::endl;
        }
    }

    Point* get_array_() const{
        return array_;
    }
    virtual int get_lenght_() const{
        return lenght_;
    }

    ~BrokenLine(){
        delete[] array_;
    }

};


#endif //LAB_1_BROKENLINE_H
