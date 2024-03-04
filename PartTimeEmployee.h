//
// Created by HP on 04.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_PARTTIMEEMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_PARTTIMEEMPLOYEE_H

#include "Employee.h"
#include <iostream>

class PartTimeEmployee : public Employee{
private:
    int hourly_rate;
    int hours_of_work;
public:
    PartTimeEmployee(){}

    PartTimeEmployee(int i);

    int getIncome() const { return hourly_rate * hours_of_work; }

    int operator + (const PartTimeEmployee& worker) const;

    friend std::ostream& operator<<(std::ostream &os, PartTimeEmployee &worker){
        os << std::endl << "full name: " << worker.full_name << std::endl
           << "position: " << worker.position << std::endl
           << "age: " << worker.age << std::endl<< "salary: " << worker.hours_of_work << std::endl
           << "annual leave: " << worker.hourly_rate << std::endl;
        return os;
    }

    PartTimeEmployee& operator=(const PartTimeEmployee& other) {
        if (this != &other) {
            Employee::operator=(other);
            hourly_rate = other.hourly_rate;
            hours_of_work = other.hours_of_work;
        }
        return *this;
    }
};


#endif //PAYMENT_SYSTEM_OOP_PARTTIMEEMPLOYEE_H
