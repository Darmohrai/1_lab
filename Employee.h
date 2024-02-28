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

    static int promotion;
public:
    Employee() : full_name("No_Info"), position("No_Info"), salary(0) {}

    Employee(int i);

    Employee(int salary, std::string full_name, int age);

    std::string getFull_Name() const {return full_name;}
    int getSalary() const {return salary;}
    int getAge() const {return age;}

    static int worker_promotion(){
        return promotion;
    }

    int operator + (const Employee& worker) const;

   friend std::ostream& operator<<(std::ostream &os, Employee &worker){
        os << std::endl << "full name: " << worker.full_name << std::endl
              << "position: " << worker.position << std::endl
              << "age: " << worker.age << std::endl
              << "salary: " << worker.salary << std::endl;;
        return os;
    }

    ~Employee(){}
};

#endif //PAYMENT_SYSTEM_OOP_EMPLOYEE_H
