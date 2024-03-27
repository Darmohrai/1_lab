//
// Created by HP on 04.03.2024.
//

#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(int i) : Employee(i) {
    std::cout << "Enter hourly rate: ";
    std::cin >> this->hourly_rate;

    std::cout << "Enter hours of work: ";
    std::cin >> this->hours_of_work;
}

PartTimeEmployee::PartTimeEmployee(std::string full_name, int age) : Employee(full_name, age) {
    std::cout << "Write new hourly rate: ";
    std::cin >> hourly_rate;

    std::cout << "Write new hours of work: ";
    std::cin >> hours_of_work;
}

int PartTimeEmployee::operator+(const PartTimeEmployee &worker) const {
    return int{this->getIncome() + worker.getIncome()};
}

std::ostream &operator<<(std::ostream &os, PartTimeEmployee &worker) {
    os << std::endl << "full name: " << worker.full_name << std::endl
       << "position: " << worker.position << std::endl
       << "age: " << worker.age << std::endl << "salary: " << worker.hours_of_work << std::endl
       << "annual leave: " << worker.hourly_rate << std::endl;
    return os;
}

void PartTimeEmployee::writePartTimeEmployeeInfo() {
    std::string file_name = "D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt";
    int i = 0;
    std::ofstream fout(file_name, std::ios::app);
    writeEmployeeInfo(i, file_name);
    fout << hourly_rate << "\n" << hours_of_work << "\n";
    fout.close();
}

void PartTimeEmployee::readPartTimeEmployeeInfo(int pos) {
    std::string file_name = "D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt";
    readEmployeeInfo(pos, file_name);
    std::ifstream fin(file_name);
    //fin.seekg(pos+4);
    std::string l;
    for (int i = 0; i < pos + 4; i++) {
        fin >> l;
    }
    fin >> hourly_rate >> hours_of_work;
    fin.close();
}