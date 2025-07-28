cmake_minimum_required(VERSION 3.30)
project(DSCourse)

set(CMAKE_CXX_STANDARD 26)

add_executable(DSCourse main.cpp
        SparseMatrix.cpp
        SparseMatrix.h)
