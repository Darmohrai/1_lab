//
// Created by HP on 05.03.2024.
//

#include "Human.h"

Human::Human(std::string full_name, int age) : full_name{full_name}{
    this->full_name = full_name;
    this->age = age;

}

void Human::writeHumanInfo() {
    std::ofstream fout("D:\\payment_system_oop\\savings_file\\FullTimeEmployeeInfo.txt", std::ios::app);
    fout << full_name << "\n";
    fout.close();
}