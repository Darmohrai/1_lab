//
// Created by HP on 10.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_COMPANY_H
#define PAYMENT_SYSTEM_OOP_COMPANY_H
#include <string>
#include <iostream>
#include "Interface.h"

class Company : public Interface {
private:
    std::string name_of_company;
    int finance;
public:
    virtual void showFunds();
    virtual void showName_of_company();

    void setName_of_company();
    void setFinance();
    [[nodiscard]] int getFinance() const { return finance;}
    std::string getName_of_company(){ return name_of_company;}

    virtual ~Company() = default;
};


#endif //PAYMENT_SYSTEM_OOP_COMPANY_H
