//
// Created by HP on 17.02.2024.
//

#include "Bank.h"

static int money;

Bank::Bank(std::string name_of_bank, int monthly_profit, int workdays) {
    this->name_of_bank = name_of_bank;
    this->monthly_profit = monthly_profit;
    this->workdays = workdays;
}

Bank::Bank(const Bank &profit) {
    assets = new int [3];
    for(int i = 0; i < 3; i++){
        assets[i] = profit.assets[i];
    }
}

void Bank::netProfit(int employees_salary, int monthly_profit, Payout& profit) {
    expencess = Payout(profit);
    money = (monthly_profit - employees_salary - expencess.getExpencess());
    std::cout << std::endl << "Net profit = " << (monthly_profit - employees_salary - expencess.getExpencess()) << std::endl;

}



void Bank::setAssets() {
    std::cout << "Write yor bank assets " << std::endl;

    assets = new int [3];

    std::cout << "uah: ";
    std::cin >> money;
    assets[0] = money;

    std::cout << "usd: ";
    std::cin >> money;
    assets[1] = money;

    std::cout << "eur: ";
    std::cin >> money;
    assets[2] = money;

}

int Bank::getAssets(int i) const {
    return assets[i];
}


void Bank::getInfo() {
    std::cout << std::endl << "In " <<
              this->name_of_bank << " bank company has " <<
              this->monthly_profit << "usd in " <<
              this->workdays << " workdays" << std::endl;
}

void Bank::showFunds() {
    std::cout << "Founds of company in bank: " << getFinance() << "\n";
}

void Bank::showName_of_company(){
    std::cout << "Name of company in bank: " << getName_of_company() << "\n";
}
