#include <iostream>
#include "Employee.h"

int main() {
    int n;
    std::cout << "enter number of employee: ";
    std::cin >> n;

    Employee* worker = new Employee[n];

    std::string full_name, position;
    int salary, age;

    for (int i = 0; i < n; i++){
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

    return 0;
}
