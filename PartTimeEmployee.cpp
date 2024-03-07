//
// Created by HP on 04.03.2024.
//

#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(int i) : Employee(i){
    std::cout << "Enter hourly rate: ";
    std::cin >> this->hourly_rate;

    std::cout << "Enter hours of work: ";
    std::cin >> this->hours_of_work;
}

int PartTimeEmployee::operator+(const PartTimeEmployee &worker) const {
    return int{ this->getIncome() + worker.getIncome()};
}

std::ostream& operator<<(std::ostream &os, PartTimeEmployee &worker){
    os << std::endl << "full name: " << worker.full_name << std::endl
       << "position: " << worker.position << std::endl
       << "age: " << worker.age << std::endl<< "salary: " << worker.hours_of_work << std::endl
       << "annual leave: " << worker.hourly_rate << std::endl;
    return os;
}