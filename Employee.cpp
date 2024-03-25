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
    writeHumanInfo();
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::app);
    fout << position << "\n";
    fout.close();
}

void Employee::readEmployeeInfo(int pos) {
    readHumanInfo(pos);
    std::ifstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
    //fin.seekg(pos+3);
    std::string  l;
    for (int i = 0; i < pos + 3; i++){
        fin >> l;
    }
    fin >> position;
    fin.close();
}

int Employee::promotion;