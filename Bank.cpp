//
// Created by HP on 17.02.2024.
//

#include "Bank.h"

Bank::Bank(int employees_salary, int monthly_profit ){
    std::cout << std::endl << "Net profit = " << (monthly_profit - employees_salary) << std::endl;
}

void Bank::setInfo(){
    std::cout << "Enter name of bank in which company save money: ";
    std::cin >> this->name_of_bank;
    std::cout << "Enter company monthly's profit: ";
    std::cin >> this->monthly_profit;
    std::cout << "Enter company's workdays: ";
    std::cin >> this->workdays;
    std::cout << std::endl;
}

void Bank::getInfo(){
    std::cout << std::endl << "In " <<
              this->name_of_bank << " bank company has " <<
              this-> monthly_profit << "usd in " <<
              this-> workdays << " workdays" << std::endl;
}