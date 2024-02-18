//
// Created by HP on 18.02.2024.
//

#include "Payout.h"

void Payout::getInfo(){
    std::cout << std::endl << "Payment day: " << payment_day << std::endl <<
              "Premium for employees: " << premium << std::endl <<
              "Unexpected expenses: " << unexpected_expenses << std::endl;
}