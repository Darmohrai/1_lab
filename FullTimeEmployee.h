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
    FullTimeEmployee() : salary(0), annual_leave(0), sick_leave(0){}

    FullTimeEmployee(int salary, std::string full_name, int age, int sick_leave);

    FullTimeEmployee(int i);

    int operator + (const FullTimeEmployee& worker) const;

    int getSalary() const {return salary;}

    friend std::ostream& operator<<(std::ostream &os, FullTimeEmployee &worker);

    FullTimeEmployee& operator=(const FullTimeEmployee& other) {
        if (this != &other) {
            Employee::operator=(other);
            salary = other.salary;
            annual_leave = other.annual_leave;
            sick_leave = other.sick_leave;
        }
        return *this;
    }

    int getSick_leave(){ return this->sick_leave;}

    FullTimeEmployee(const FullTimeEmployee& other) : Employee(other) {
        salary = other.salary;
        annual_leave = other.annual_leave;
        sick_leave = other.sick_leave;
    }

    FullTimeEmployee(FullTimeEmployee&& other) : Employee(other), salary{other.salary},
    annual_leave{other.annual_leave}, sick_leave{other.sick_leave}{
        other.salary = 0;
        other.sick_leave = 0;
        other.annual_leave = 0;
    }

    virtual void getBriefInfo(){
        std::cout << full_name << " " << position << " salary - " << salary;
    }

    ~FullTimeEmployee(){};
};


#endif //PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
