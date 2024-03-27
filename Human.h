//
// Created by HP on 05.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_HUMAN_H
#define PAYMENT_SYSTEM_OOP_HUMAN_H

#include <iostream>
#include <fstream>
#include <iterator>

class Human{
protected:
    std::string full_name;
    int age;
public:
    Human(): full_name("None"), age(0){};

    Human(std::string full_name, int age);

    [[nodiscard]] std::string getFull_Name() const {return full_name;}
    [[nodiscard]] int getAge() const {return age;}

    Human& operator=(const Human& other) {
        if (this != &other) {
            full_name = other.full_name;
            age = other.age;
        }
        return *this;
    }

    virtual void getBriefInfo() = 0;

    void writeHumanInfo(int size_of_object);
    void readHumanInfo(int pos);

    void setInfo(std::string full_name, int age){
        this->full_name = full_name;
        this->age = age;
        std::cout << this->full_name;
    }

    virtual ~Human() = default;
};


#endif //PAYMENT_SYSTEM_OOP_HUMAN_H
