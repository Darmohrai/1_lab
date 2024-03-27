//
// Created by HP on 05.03.2024.
//

#include "Human.h"

Human::Human(std::string full_name, int age){
    this->full_name = full_name;
    this->age = age;

}

void Human::writeHumanInfo(int size_of_object, std::string file_name) {
    std::ofstream fout(file_name, std::ios::app);
    fout << "\n\n" << full_name << "\n" << age << "\n";
    fout.close();
}

void Human::readHumanInfo(int pos, std::string file_name) {/*
    std::ifstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
    fin.seekg(pos+1);
    fin >> full_name >> age;
    fin.close();*/


    std::ifstream fin(file_name);
    std::string l;
    //fin.seekg(pos+1);
    for (int i = 0; i < pos + 1; i++){
        fin >> l;
    }
    fin >> full_name >> age;
    fin.close();

}