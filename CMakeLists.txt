cmake_minimum_required(VERSION 3.28)
project(Numerical_Linear_Algebra)

set(CMAKE_CXX_STANDARD 23)

add_executable(Numerical_Linear_Algebra main.cpp
        hessenberg_form.cpp
        tools.cpp
        eigen_solver.cpp
        tests/test_1_hessenberg_qr.cpp
        tests/tests.cpp
        tests/test_2_hessenberg_qr.cpp
        tests/test_1_simple_qr.cpp
        tests/test_1_simple_qr.h
)
