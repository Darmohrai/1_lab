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

    friend std::ostream& operator<<(std::ostream &os, FullTimeEmployee &worker){
        os << std::endl << "full name: " << worker.full_name << std::endl
           << "position: " << worker.position << std::endl
           << "age: " << worker.age << std::endl<< "salary: " << worker.salary << std::endl
           << "annual leave: " << worker.annual_leave << std::endl
           << "sick leave: " << worker.sick_leave << std::endl;
        return os;
    }

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

};


#endif //PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
