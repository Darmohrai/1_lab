//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_BANK_H
#define PAYMENT_SYSTEM_OOP_BANK_H

#include <string>
#include <iostream>

class Bank {
private:
    std::string name_of_bank;
    int monthly_profit;
    int workdays;
public:
    Bank(){name_of_bank = "None"; monthly_profit = 0; workdays = 0;}

    Bank(int employees_salary, int monthly_profit ){
        std::cout << std::endl << "Net profit = " << (monthly_profit - employees_salary) << std::endl;
    }

    void setInfo(){
        std::cout << "Enter name of bank in which company save money: ";
        std::cin >> this->name_of_bank;
        std::cout << "Enter company monthly's profit: ";
        std::cin >> this->monthly_profit;
        std::cout << "Enter company's workdays: ";
        std::cin >> this->workdays;
        std::cout << std::endl;
    }

    int getMonthlyProfit() const{
        return monthly_profit;
    }
    void getInfo(){
        std::cout << std::endl << "In " <<
        this->name_of_bank << " bank company has " <<
        this-> monthly_profit << "usd in " <<
        this-> workdays << " workdays" << std::endl;
    }

    ~Bank(){};
};


#endif //PAYMENT_SYSTEM_OOP_BANK_H
