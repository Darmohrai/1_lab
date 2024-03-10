//
// Created by HP on 10.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_COMPANY_H
#define PAYMENT_SYSTEM_OOP_COMPANY_H
#include <string>
#include <iostream>

class Company {
private:
    std::string name_of_company;
    int finance;
public:
    virtual void showFunds();

    void setFinance();
    int getFinance(){ return finance;}
};


#endif //PAYMENT_SYSTEM_OOP_COMPANY_H
