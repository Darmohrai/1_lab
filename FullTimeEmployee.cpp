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

FullTimeEmployee::FullTimeEmployee(std::string full_name, int age, int sick_leave) : Employee(full_name, age) {
    promotion++;

    std::cout << "write new salary: ";
    std::cin >> this->salary;

    std::cout << "write new annual leave: ";
    std::cin >> this->annual_leave;

    this->sick_leave = sick_leave;
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
    writeEmployeeInfo();
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::app);
    fout << salary << "\n" << annual_leave << "\n" << sick_leave << "\n" << "\n";
    fout.close();
}