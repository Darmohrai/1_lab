//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_EMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
protected:
    std::string full_name;
    std::string position;
    int age;

    static int promotion;
public:
    Employee() : full_name("No_Info"), position("No_Info"){}

    Employee(int i);

    Employee(std::string full_name, int age);

    std::string getFull_Name() const {return full_name;}
    int getAge() const {return age;}

    static int worker_promotion(){
        return promotion;
    }

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            full_name = other.full_name;
            position = other.position;
            age = other.age;
        }
        return *this;
    }

    ~Employee(){}
};

#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
