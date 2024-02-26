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

    int* assets = nullptr;
public:

    Bank(std::string name_of_bank = "None", int monthly_profit = 0, int workdays = 0);

    Bank(const Bank& profit);

    void netProfit(int employees_salary, int monthly_profit);

    int getMonthly_Profit() const { return monthly_profit; }

    void setAssets();
    int getAssets(int i) const ;

    void getInfo();

    ~Bank() {};
};


#endif //PAYMENT_SYSTEM_OOP_BANK_H
