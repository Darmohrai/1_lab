//
// Created by HP on 18.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_PAYOUT_H
#define PAYMENT_SYSTEM_OOP_PAYOUT_H

#include <string>
#include <iostream>

class Payout {
private:
    std::string payment_day;
    int premium;
    int unexpected_expenses;
public:
    Payout() : payment_day("Not established"), premium(0), unexpected_expenses(0){}

    Payout(std::string &payment_day) : Payout(){
        this->payment_day = payment_day;
    }

    Payout(int premium, std::string &payment_day) : Payout(payment_day){
        this->premium = premium;
    }

    Payout(int unexpected_expenses, int premium, std::string &payment_day):Payout(premium, payment_day){
        this->unexpected_expenses = unexpected_expenses;
    }

    void getInfo();

    ~Payout(){ std::cout << std::endl << "info about payment is deleted now";};
};


#endif //PAYMENT_SYSTEM_OOP_PAYOUT_H
