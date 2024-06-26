//
// Created by HP on 04.03.2024.
//

#ifndef PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
#define PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H

#include "Employee.h"

class FullTimeEmployee final : public Employee {
private:
    int salary;
    int annual_leave;
    int sick_leave;
public:
    FullTimeEmployee() : salary(0), annual_leave(0), sick_leave(0), Employee(){}

    FullTimeEmployee(std::string full_name, int age, int sick_leave , int pos);

    explicit FullTimeEmployee(int i);

    int operator + (const FullTimeEmployee& worker) const;

    [[nodiscard]] int getSalary() const {return salary;}

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

    [[nodiscard]]int getSick_leave() const { return this->sick_leave;}
    [[nodiscard]]int getAnnual_leave() const { return this->annual_leave;}

    FullTimeEmployee(const FullTimeEmployee& other) : Employee(other) {
        salary = other.salary;
        annual_leave = other.annual_leave;
        sick_leave = other.sick_leave;
    }

    FullTimeEmployee(FullTimeEmployee&& other) noexcept : Employee(other), salary{other.salary},
    annual_leave{other.annual_leave}, sick_leave{other.sick_leave} {
        other.salary = 0;
        other.sick_leave = 0;
        other.annual_leave = 0;
    }

    void getBriefInfo() final{
        std::cout << getFull_Name() << " is " << getPosition() << " and has salary - " << salary << "\n";
    }

    void writeFullTimeEmployeeInfo();
    void readFullTimeEmployeeInfo(int pos);

    void changeInfo(){
        std::fstream file("D:\\payment_system_oop\\savings_file\\FullTimeEmployeeInfo.txt");

    }

    void setInfo(std::string full_name, std::string position, int age, int salary, int annual_leave, int sick_leave){
        this->full_name = full_name;
        this->age=age;
        this->position = position;
        this->salary=salary;
        this->annual_leave=annual_leave;
        this->sick_leave=sick_leave;
    }

    ~FullTimeEmployee() final = default;
};


#endif //PAYMENT_SYSTEM_OOP_FULLTIMEEMPLOYEE_H
