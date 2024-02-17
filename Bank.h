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

    void setNameOfBank(std::string name_of_bank){
        this->name_of_bank = name_of_bank;
    }
    void setMonthlyProfit(int monthly_profit){
        this->monthly_profit = monthly_profit;
    }
    void setWorkdays(int workdays){
        this->workdays = workdays;
    }

    std::string getNameOfBank(){
        return name_of_bank;
    }
    int getMonthlyProfit(){
        return monthly_profit;
    }
    int getWorkdays(){
        return workdays;
    }

};


#endif //PAYMENT_SYSTEM_OOP_BANK_H
