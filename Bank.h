//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_BANK_H
#define PAYMENT_SYSTEM_OOP_BANK_H

#include <string>
#include <iostream>
#include "Payout.h"
#include "Company.h"

class Bank final : public Company {
private:
    std::string name_of_bank;
    int monthly_profit;
    int workdays;
    Payout expencess;

    int *assets;
public:

    explicit Bank(std::string name_of_bank = "None", int monthly_profit = 0, int workdays = 0);

    Bank(const Bank &profit);

    void netProfit(int employees_salary, int monthly_profit, Payout &profit);

    [[nodiscard]] int getMonthly_Profit() const { return monthly_profit; }

    void setAssets();
    void getAssets();

    void getInfo() override;

    const int getMoney() override { return this->monthly_profit; }

    Bank &operator=(const Bank &other) {
        if (this != &other) {
            this->name_of_bank = other.name_of_bank;
            this->monthly_profit = other.monthly_profit;
            this->workdays = other.workdays;
        }
        return *this;
    }

    void showFunds() override;

    void showName_of_company() override;

    void writeInfoInFile();
    void readInfoFromFile();

    void writeAssetsInfo();
    void readAssetsInfo();

    ~Bank() final = default;
};


#endif //PAYMENT_SYSTEM_OOP_BANK_H
