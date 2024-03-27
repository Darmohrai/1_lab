//
// Created by HP on 04.03.2024.
//

#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(int i) : Employee(i) {
    std::cout << "Enter salary: ";
    std::cin >> this->salary;

    std::cout << "Enter annual leave: ";
    std::cin >> this->annual_leave;

    std::cout << "Enter sick leave: ";
    std::cin >> this->sick_leave;
}

FullTimeEmployee::FullTimeEmployee(std::string full_name, int age, int sick_leave, int pos) : Employee(full_name, age) {
    promotion++;

    std::cout << "write new salary: ";
    std::cin >> this->salary;

    std::cout << "write new annual leave: ";
    std::cin >> this->annual_leave;

    this->sick_leave = sick_leave;
/*
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::out | std::ios::trunc);
    fout.seekp(pos, std::ios::beg);
    fout << "\n" << full_name << "\n" << age << "\n" << position << "                    \n" << salary
         << "                     \n" << annual_leave << "\n" << sick_leave;*/
}

int FullTimeEmployee::operator+(const FullTimeEmployee &worker) const {
    return int{this->getSalary() + worker.getSalary()};
}

std::ostream &operator<<(std::ostream &os, FullTimeEmployee &worker) {
    os << std::endl << "full name: " << worker.full_name << std::endl
       << "position: " << worker.position << std::endl
       << "age: " << worker.age << std::endl << "salary: " << worker.salary << std::endl
       << "annual leave: " << worker.annual_leave << std::endl
       << "sick leave: " << worker.sick_leave << std::endl;
    return os;
}

void FullTimeEmployee::writeFullTimeEmployeeInfo() {
    int size_of_object;
    std::string size_int;
    size_of_object = std::size(full_name) + std::size(position) + std::size(std::to_string(age)) +
                     std::size(std::to_string(salary)) + std::size(std::to_string(annual_leave)) +
                     std::size(std::to_string(sick_leave)) + 6;
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::app);
    writeEmployeeInfo(size_of_object);
    fout << salary << "\n" << annual_leave << "\n" << sick_leave << "\n" << "\n";
    fout.close();
}


void FullTimeEmployee::readFullTimeEmployeeInfo(int pos) {
    readEmployeeInfo(pos);
    std::ifstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
    //fin.seekg(pos+4);
    std::string l;
    for (int i = 0; i < pos + 4; i++) {
        fin >> l;
    }
    fin >> salary >> annual_leave >> sick_leave;
    fin.close();
}
