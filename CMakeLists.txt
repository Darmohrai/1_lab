cmake_minimum_required(VERSION 3.27)
project(payment_system_oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(payment_system_oop main.cpp
        Employee.cpp
        Employee.h
        Bank.cpp
        Bank.h
        Payout.cpp
        Payout.h
        FullTimeEmployee.cpp
        FullTimeEmployee.h)
