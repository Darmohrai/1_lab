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

    Bank(int employees_salary, int monthly_profit );

    void setInfo();

    int getMonthlyProfit() const{return monthly_profit;}

    void getInfo();

    ~Bank(){};
};


#endif //PAYMENT_SYSTEM_OOP_BANK_H
