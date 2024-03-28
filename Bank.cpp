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
    assets = new int[3];
    for (int i = 0; i < 3; i++) {
        assets[i] = profit.assets[i];
    }
}

void Bank::netProfit(int employees_salary, int monthly_profit, Payout &profit) {
    expencess = Payout(profit);
    money = (monthly_profit - employees_salary - expencess.getExpencess());
    std::cout << std::endl << "Net profit = " << (monthly_profit - employees_salary - expencess.getExpencess())
              << std::endl;

}


void Bank::setAssets() {
    std::cout << "Write yor bank assets " << std::endl;

    assets = new int[3];

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

void Bank::getAssets() {
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "uah: ";
        if (i == 1) std::cout << "usd: ";
        if (i == 2) std::cout << "eur: ";
        std::cout << assets[i] << "\n";
    }
}


void Bank::getInfo() {
    std::cout << std::endl << "In " <<
              this->name_of_bank << " bank company " << getName_of_company() << " has " <<
              this->monthly_profit << "usd in " <<
              this->workdays << " workdays" << std::endl;
}

void Bank::showFunds() {
    std::cout << "Founds of company in bank: " << getFinance() << "\n";
}

void Bank::showName_of_company() {
    std::cout << "Name of company in bank: " << getName_of_company() << "\n";
}

void Bank::writeInfoInFile() {
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Profit_info.txt");
    fout << name_of_bank << "\n" << monthly_profit << "\n" << workdays << "\n" <<
         getName_of_company() << "\n" << getFinance();
    fout.close();
}

void Bank::readInfoFromFile() {
    std::ifstream fin("D:\\payment_system_oop\\savings_file\\Profit_info.txt");
    std::string name_of_company;
    int finance;
    fin >> name_of_bank >> monthly_profit >> workdays >> name_of_company >> finance;
    readCompInfoFromFile(name_of_company, finance);
    fin.close();
}

void Bank::writeAssetsInfo() {
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\Assets_info.txt");
    for (int i = 0; i < 3; i++) {
        if (assets[i] != NULL) {
            fout << assets[i] << "\n";
        } else {
            fout << "0";
        }
    }
    fout.close();
}

void Bank::readAssetsInfo() {
    std::ifstream fin("D:\\payment_system_oop\\savings_file\\Assets_info.txt");
    assets = new int[3];
    for (int i = 0; i < 3; i++) {
        fin >> assets[i];
    }
    fin.close();
}
