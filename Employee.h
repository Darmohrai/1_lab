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

    Employee(int i){
        std::cout << "Enter the worker's name: ";
        std::cin >> this->full_name;
        std::cout << "Enter the worker's position: ";
        std::cin >> this-> position;
        std::cout << "Enter the worker's age: ";
        std::cin >> this->age;
        std::cout << "Enter the worker's salary: ";
        std::cin >> this->salary;
    }

    Employee(std::string position, int salary, std::string full_name, int age){
        this->full_name = full_name;
        this->age = age;

        if (this->salary < salary){
            std::cout << std::endl << this->full_name << " has promotion " << std::endl;
        }
        if (this->salary > salary){
            std::cout << std::endl << this->full_name << " has demotion " << std::endl;
        }
        this->position = position;
        this->salary = salary;
    }

    void getInfo(){
        std::cout << std::endl << "full name: " << full_name << std::endl
        << "position: " << position << std::endl
        << "age: " << age << std::endl
        << "salary: " << salary << std::endl;
    }

    std::string getFullName(){return full_name;}
    int getSalary(){return salary;}
    int getAge(){return age;}
};


#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
