//
// Created by HP on 10.03.2024.
//

#include "Company.h"

void Company::showFunds() {
    std::cout << "Founds of company: " << finance;
}

void Company::setFinance() {
    std::cout << "Set finance of company: ";
    std::cin >> finance;
}