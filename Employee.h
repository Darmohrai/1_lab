//
// Created by HP on 17.02.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_EMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
private:
    std::string full_name;
    std::string position;
    int age;
    int salary;

public:
    Employee() : full_name("No_Info"), position("No_Info"), age(0), salary(0) {}

    Employee(int i);

    Employee(int salary, std::string full_name, int age);

    void getInfo();

    std::string getFullName() const {return full_name;}
    int getSalary() const {return salary;}
    int getAge() const {return age;}

    ~Employee(){}
};


#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
