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
    Payout() : payment_day{"Not established"}, premium{0}, unexpected_expenses{0}{}

    Payout(std::string &payment_day);

    Payout(int premium, std::string &payment_day);

    Payout(int unexpected_expenses, int premium, std::string &payment_day);

    Payout(Payout && payment);

    Payout& operator = (Payout &&other) {
        this->~Payout();
        return *new(this) Payout(std::move(other));
    }

    int getExpencess(){ return premium + unexpected_expenses;}

    void getInfo();

    Payout(const Payout& other) {
        payment_day = other.payment_day;
        premium = other.premium;
        unexpected_expenses = other.unexpected_expenses;
    }

    ~Payout(){}
};

#endif //PAYMENT_SYSTEM_OOP_PAYOUT_H
