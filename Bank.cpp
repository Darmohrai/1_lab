//
// Created by HP on 17.02.2024.
//

#include "Bank.h"

Bank::Bank(std::string name_of_bank, int monthly_profit, int workdays){
    this->name_of_bank = name_of_bank;
    this->monthly_profit = monthly_profit;
    this->workdays = workdays;
}

void Bank::NetProfit(int employees_salary, int monthly_profit){
    std::cout << std::endl << "Net profit = " << (monthly_profit - employees_salary) << std::endl;
}

void Bank::getInfo(){
    std::cout << std::endl << "In " <<
              this->name_of_bank << " bank company has " <<
              this-> monthly_profit << "usd in " <<
              this-> workdays << " workdays" << std::endl;
}