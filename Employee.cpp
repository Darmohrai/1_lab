//
// Created by HP on 17.02.2024.
//

#include "Employee.h"

void Employee::getInfo(){
    std::cout << std::endl << "full name: " << full_name << std::endl
              << "position: " << position << std::endl
              << "age: " << age << std::endl
              << "salary: " << salary << std::endl;
}