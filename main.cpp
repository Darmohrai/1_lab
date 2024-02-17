#include <iostream>
#include "Employee.h"
#include "Bank.h"

int main() {
    int number_emp;
    std::cout << "enter number of employee: ";
    std::cin >> number_emp;

    Employee* worker = new Employee[number_emp];

    std::string full_name, position;
    int salary, age;

    for (int i = 0; i < number_emp; i++){
        std::cout << "Enter the worker's name: ";
        std::cin >> full_name;

        std::cout << "Enter the worker's position: ";
        std::cin >> position;

        std::cout << "Enter the worker's age: ";
        std::cin >> age;

        std::cout << "Enter the worker's salary: ";
        std::cin >> salary;

        worker[i] = Employee(full_name, position, age, salary);

        //worker[i].getInfo();
    }

    std::cout<<std::endl<<std::endl<<std::endl; // потрібно замінити на очищення екрану

    std::string question = "yes";
    while(question == "yes") {
        std::cout << "Did anyone get a promotion? (put 'yes' or 'no')" << std::endl;
        std::cin >> question;
        if (question == "no"){
            break;
        }
        std::string full_name;
        std::cout << "put his Full Name: ";
        std::cin >> full_name;

        for (int i = 0; i < number_emp; i++) {
            if (worker[i].getFullName() == full_name) {
                std::string position;
                int salary;
                std::cout << "write new position: ";
                std::cin >> position;
                std::cout << "write new salary: ";
                std::cin >> salary;

                int difference = salary - worker[i].getSalary();
                std::cout << "salary rise on " << difference;

                worker[i] = Employee(position, salary, worker[i].getFullName(), worker[i].getAge());

                break;
            }
        }
    }

    std::cout<<std::endl<<std::endl<<std::endl; // потрібно замінити на очищення екрану

    std::cout << "Do you want see information about employee? " << std::endl;
    std::cin >> question;
    if (question == "yes"){
        for (int i = 0; i < number_emp; i++){
            worker[i].getInfo();
        }
    }

    

    return 0;
}
