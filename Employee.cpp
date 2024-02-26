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
    static int numb_of_promotion;
    numb_of_promotion++;

    this->full_name = full_name;
    this->age = age;

    std::cout << "write new position: ";
    std::cin >> this->position;
    std::cout << "write new salary: ";
    std::cin >> this->salary;

    if (numb_of_promotion == 1) {
        std::cout << std::endl << " At this moment promotion has " << numb_of_promotion << " person" << std::endl;
    } else {
        std::cout << std::endl << " At this moment promotion have " << numb_of_promotion << " people" << std::endl;
    }
}

void Employee::getInfo() {
    std::cout << std::endl << "full name: " << full_name << std::endl
              << "position: " << position << std::endl
              << "age: " << age << std::endl
              << "salary: " << salary << std::endl;
}