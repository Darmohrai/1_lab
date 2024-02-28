//
// Created by HP on 17.02.2024.
//

#include "Employee.h"

Employee::Employee(int i) {
    std::cout << std::endl << "Enter the worker's name: ";
    std::cin >> this->full_name;
    std::cout << "Enter the worker's position: ";
    std::cin >> this->position;
    std::cout << "Enter the worker's age: ";
    std::cin >> this->age;
    std::cout << "Enter the worker's salary: ";
    std::cin >> this->salary;
}

Employee::Employee(int salary, std::string full_name, int age) {
    promotion++;

    this->full_name = full_name;
    this->age = age;

    std::cout << "write new position: ";
    std::cin >> this->position;
    std::cout << "write new salary: ";
    std::cin >> this->salary;
}

int Employee::operator+(const Employee &worker) const {
    return int{ this-> getSalary() + worker.getSalary()};
}

int Employee::promotion;