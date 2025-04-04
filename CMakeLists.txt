cmake_minimum_required(VERSION 3.30)
project(free_style_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(free_style_cpp main.cpp
        MathUtils.cpp
        MathUtils.h
        Fraction.cpp
        Fraction.h)
