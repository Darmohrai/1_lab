//
// Created by HP on 17.02.2024.
//

#include "Employee.h"

Employee::Employee(int i){
    std::cout << std::endl << "Enter the worker's name: ";
    std::cin >> this->full_name;
    std::cout << "Enter the worker's position: ";
    std::cin >> this-> position;
    std::cout << "Enter the worker's age: ";
    std::cin >> this->age;
    std::cout << "Enter the worker's salary: ";
    std::cin >> this->salary;
}

Employee::Employee(int salary, std::string &full_name, int age){
    this->full_name = full_name;
    this->age = age;

    std::cout << "write new position: ";
    std::cin >> this->position;
    std::cout << "write new salary: ";
    std::cin >> this->salary;

    int difference = this->salary - salary;
    std::cout << "salary rise on " << difference;

    if (difference > 0){
        std::cout << std::endl << this->full_name << " has promotion " << std::endl;
    }
}

void Employee::getInfo(){
    std::cout << std::endl << "full name: " << full_name << std::endl
              << "position: " << position << std::endl
              << "age: " << age << std::endl
              << "salary: " << salary << std::endl;
}