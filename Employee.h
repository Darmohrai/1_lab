//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_EMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_EMPLOYEE_H

#include <string>
#include <iostream>
#include "Human.h"

class Employee : public Human{
protected:
    std::string position;

    static int promotion;
public:
    Employee() : position("No_Info"){};

    Employee(int i);

    Employee(std::string full_name, int age);

    //std::string getFull_Name() const {return full_name;}
    //int getAge() const {return age;}

    static int worker_promotion(){
        return promotion;
    }

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Human::operator=(other);
            position = other.position;
        }
        return *this;
    }

    ~Employee(){};
};

#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
