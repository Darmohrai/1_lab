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
}

Employee::Employee(std::string full_name, int age) : Human(full_name, age) {

    std::cout << "write new position: ";
    std::cin >> this->position;
}

void Employee::writeEmployeeInfo() {
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\FullTimeEmployeeInfo.txt", std::ios::app);
    writeHumanInfo();
    fout << position << "\n";
    fout.close();
}

int Employee::promotion;