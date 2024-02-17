//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_EMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
private:
    std::string full_name;
    std::string position;
    int age;
    int salary;

public:
    Employee() : full_name("No_Info"), position("No_Info"), age(0), salary(0) {}

    Employee(std::string full_name, std::string position, int age, int salary){
        this->full_name = full_name;
        this-> position = position;
        this->age = age;
        this->salary = salary;
    }

    Employee(std::string position, int salary){
        if (this->salary > salary){
            std::cout << std::endl << this->full_name << " has promotion " << std::endl;
        }
        if (this->salary < salary){
            std::cout << std::endl << this->full_name << " has demotion " << std::endl;
        }
        this->position = position;
        this->salary = salary;

    }

    void setFullName(std::string full_name){
        this->full_name = full_name;
    }
    void setPosition(std::string position){
        this->position = position;
    }
    void setAge(int age){
        this->age = age;
    }
    void setSalary(int salary){
        this->salary = salary;
    }

    void getInfo(){
        std::cout << "full name: " << full_name << std::endl
        << "position: " << position << std::endl
        << "age: " << age << std::endl
        << "salary: " << salary << std::endl;
    }
};


#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
