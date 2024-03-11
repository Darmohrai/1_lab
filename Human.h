//
// Created by HP on 05.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_HUMAN_H
#define PAYMENT_SYSTEM_OOP_HUMAN_H

#include <iostream>

class Human{
protected:
    std::string full_name;
    int age;
public:
    Human(): full_name{"None"}, age{0}{};

    Human(std::string full_name, int age);

    std::string getFull_Name() const {return full_name;}
    int getAge() const {return age;}

    /*Human& operator=(const Human& other) {
        if (this != &other) {
            full_name = other.full_name;
            age = other.age;
        }
        return *this;
    }*/

    virtual void getBriefInfo() = 0;

    virtual ~Human(){};
};


#endif //PAYMENT_SYSTEM_OOP_HUMAN_H
