//
// Created by HP on 04.03.2024.
//

#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(int i): Employee(i) {
    std::cout << "Enter salary: ";
    std::cin >> this->salary;

    std::cout << "Enter annual leave: ";
    std::cin >> this->annual_leave;

    std::cout << "Enter sick leave: ";
    std::cin >> this->sick_leave;
}

FullTimeEmployee::FullTimeEmployee(int salary, std::string full_name, int age) : Employee(full_name, age) {
    promotion++;

    std::cout << "write new salary: ";
    std::cin >> this->salary;

    std::cout << "write new annual leave: ";
    std::cin >> this->annual_leave;
}

int FullTimeEmployee::operator+(const FullTimeEmployee &worker) const {
    return int{ this->getSalary() + worker.getSalary()};
}