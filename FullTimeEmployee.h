//
// Created by HP on 04.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H

#include "Employee.h"
#include <iostream>

class FullTimeEmployee : public Employee {
private:
    int salary;
    int annual_leave;
    int sick_leave;
public:
    FullTimeEmployee(int salary, std::string full_name, int age);

    FullTimeEmployee(int i);

    int operator + (const FullTimeEmployee& worker) const;

    int getSalary() const {return salary;}

    friend std::ostream& operator<<(std::ostream &os, FullTimeEmployee &worker){
        os << std::endl << "full name: " << worker.full_name << std::endl
           << "position: " << worker.position << std::endl
           << "age: " << worker.age << std::endl<< "salary: " << worker.salary << std::endl
           << "annual leave: " << worker.annual_leave << std::endl
           << "sick leave: " << worker.sick_leave << std::endl;
        return os;
    }

    FullTimeEmployee& operator=(const FullTimeEmployee& worker) {
        if (this != &worker) {
        }
        return *this;
    }
};


#endif //PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
