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