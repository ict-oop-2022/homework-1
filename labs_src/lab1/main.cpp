#include "polygon.h"
#include "regularpolygon.h"
#include "trapezoid.h"
#include "triangle.h"

#include <iostream>

using namespace std;

int main() {
    // Создаем массив указателей на базовый класс.
    const int SHAPES_COUNT = 4;
    Shape* shapes[SHAPES_COUNT]{};

    // Заполняем массив объектами.
    shapes[0] = new Triangle({ 0, 0 }, { 0, 8 }, { 5, 0 });
    shapes[1] = new Trapezoid({ 3,2 }, { 6,6 }, { 9,6 }, { 5,2 });
    shapes[2] = new Polygon({ {0, 0}, {3, 4}, {8, 2}, {6, -2}, {3, -4} });
    shapes[3] = new RegularPolygon({ {2, 10}, {2, 13}, {5, 13}, {5, 10} });

    try {
        for (int i = 0; i < SHAPES_COUNT; ++i) {
            // За счет полиморфизма мы работаем через указатели на базовый класс фигуры, а
            // вычисление площади и периметра будут происходить для каждого типа по своим формулам.
            Shape* sh = shapes[i];
            cout << sh->getName() << ": "
                << "area = " << sh->calcArea() << ", "
                << "perimeter = " << sh->calcPerimeter() << endl;
        }
    } catch (const std::runtime_error& exc) {
        cout << endl << "ERROR: " << exc.what() << endl;
    }

    // Освобождаем память, выделенную для объектов в массиве.
    for (int i = 0; i < SHAPES_COUNT; ++i)
        delete shapes[i];
    
    return 0;
}