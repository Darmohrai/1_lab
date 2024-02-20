#include <iostream>
#include "Employee.h"
#include "Bank.h"
#include "Payout.h"

void BankQuestoin(Bank& profit, std::string& question ){

    int monthly_profit, workdays;


    std::cout << "Enter name of bank in which company save money (write 'skip' to skip): ";
    std::cin >> question;
    if (question != "skip"){
        profit = Bank(question);
        std::cout << "Enter company monthly's profit: (type '0' to skip)";
        std::cin >> monthly_profit;
        if (monthly_profit != 0){
            profit = Bank(question, monthly_profit);
            std::cout << "Enter company's workdays: (type '0' to skip)";
            std::cin >> workdays;
            if (workdays != 0){
                profit = Bank(question, monthly_profit, workdays);
                std::cout << std::endl;
            }
        }
    }

}

int main() {
    int number_emp;
    std::cout << "enter number of employee: ";
    std::cin >> number_emp;

    Employee* worker = new Employee[number_emp];

    for (int i = 0; i < number_emp; i++){
        worker[i] = Employee(i);
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
            if (worker[i].getFull_Name() == full_name) {

                worker[i] = Employee(worker[i].getSalary(), full_name, worker[i].getAge());

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

    std::cout<<std::endl<<std::endl<<std::endl; // потрібно замінити на очищення екрану

    Bank profit;
    BankQuestoin(profit, question);

    int employees_salary = 0;
    for (int i = 0; i < number_emp; i++){
        employees_salary = employees_salary + worker[i].getSalary();
    }

    std::cout << "Do you want see information about profit? " << std::endl;
    std::cin >> question;
    if (question == "yes") {
        profit.getInfo();
        profit.netProfit(employees_salary, profit.getMonthly_Profit());
    }

    std::cout<<std::endl<<std::endl<<std::endl; // потрібно замінити на очищення екрану

    Payout payment;
    int unexpected_expenses;
    int premium;
    std::string payment_day;

    std::cout << "On what day is the salary payment scheduled? (write 'skip' to skip)" << std::endl;
    std::cin >> question;
    if (question != "skip") {
        payment_day = question;
        payment = Payout(payment_day);
        std::cout << "Do you want enter premium? (write 'yes' or 'no')" << std::endl;
        std::cin >> question;
        if (question == "yes"){
            std::cout << "How much is allocated for the premium? ";
            std::cin >> premium;
            payment = Payout(premium, payment_day);
            std::cout << "Do you want enter unexpected expenses? (write 'yes' or 'no')" << std::endl;
            std::cin >> question;
            if (question == "yes"){
                std::cout << "How much is unexpected expenses? ";
                std::cin >> unexpected_expenses;
                payment = Payout(unexpected_expenses, premium, payment_day);
            }
        }
    }

    std::cout<<std::endl<<std::endl<<std::endl; // потрібно замінити на очищення екрану

    payment.getInfo();

    return 0;
}