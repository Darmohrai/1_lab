//
// Created by HP on 18.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_PAYOUT_H
#define PAYMENT_SYSTEM_OOP_PAYOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include "Interface.h"

class Payout : Interface{
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

    void getInfo() override;
    const int getMoney() override{ std::cout << "premium - " << this->premium; return this->premium;}

    Payout(const Payout& other);

    void writeInfoInFile();

    void readInfoFromFile();

    ~Payout() = default;
};

#endif //PAYMENT_SYSTEM_OOP_PAYOUT_H
