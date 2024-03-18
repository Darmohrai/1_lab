//
// Created by HP on 10.03.2024.
//

#include "Company.h"

void Company::showFunds() {
    std::cout << "Founds of company: " << finance;
}

void Company::showName_of_company(){
    std::cout << "Name of company: " << name_of_company;
}

void Company::setFinance() {
    std::cout << "Set finance of company: ";
    std::cin >> finance;
}

void Company::setName_of_company(){
    std::cout << "Set name of company: ";
    std::cin >> name_of_company;
}

void Company::readCompInfoFromFile(std::string &name_of_company, int &finance) {
    this->name_of_company = name_of_company;
    this->finance = finance;
}