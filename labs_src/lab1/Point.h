#ifndef ICT_HOMEWORK_1_POINT_H
#define ICT_HOMEWORK_1_POINT_H

using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point(int x, int y);
    Point();
    Point getPoint();
    int getPoint_X();
    int getPoint_Y();
};

#endif //ICT_HOMEWORK_1_POINT_H
