//
// Created by HP on 18.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_PAYOUT_H
#define PAYMENT_SYSTEM_OOP_PAYOUT_H

#include <string>

class Payout {
private:
    std::string payment_day;
    int premium;
    int unexpected_expenses;
public:
    Payout(){payment_day = "Тot established"; premium = 0; unexpected_expenses = 0;}

    
};


#endif //PAYMENT_SYSTEM_OOP_PAYOUT_H
