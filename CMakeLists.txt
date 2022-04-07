cmake_minimum_required(VERSION 3.21)
project(Lab_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_1 main.cpp Point.h Point.cpp Point.h BrokenLine.cpp BrokenLine.h cmake-build-debug/Lock_BrokenLine.cpp cmake-build-debug/Lock_BrokenLine.h Polygon.cpp Polygon.h Triangle.cpp Triangle.h Trapezoid.cpp Trapezoid.h Regular_Polygon.cpp Regular_Polygon.h)
