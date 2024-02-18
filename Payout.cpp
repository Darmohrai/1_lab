//
// Created by HP on 18.02.2024.
//

#include "Payout.h"

Payout::Payout(std::string &payment_day) : Payout(){
    this->payment_day = payment_day;
}

Payout::Payout(int premium, std::string &payment_day) : Payout(payment_day){
    this->premium = premium;
}

Payout::Payout(int unexpected_expenses, int premium, std::string &payment_day):Payout(premium, payment_day){
    this->unexpected_expenses = unexpected_expenses;
}

void Payout::getInfo(){
    std::cout << std::endl << "Payment day: " << payment_day << std::endl <<
              "Premium for employees: " << premium << std::endl <<
              "Unexpected expenses: " << unexpected_expenses << std::endl;
}

