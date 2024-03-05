#include <iostream>
#include "Employee.h"
#include "Bank.h"
#include "Payout.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

void BankQuestoin(Bank& profit, std::string &question);

void GetBankAssets(Bank profit);

int Employee_salary(FullTimeEmployee* full_time_worker, int number_emp, int employees_salary);

Payout SetPayInfo(std::string& question);

int main() {

    int number_emp;
    std::cout << "enter number of full time employee: ";
    std::cin >> number_emp;

     FullTimeEmployee *full_time_worker = new FullTimeEmployee[number_emp];

    for (int i = 0; i < number_emp; i++) {
        full_time_worker[i] = FullTimeEmployee(i);
    }

    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану

    std::string question = "yes";
    while (question == "yes") {
        std::cout << "Did anyone get a promotion? (put 'yes' or 'no')" << std::endl;
        std::cin >> question;
        if (question == "no") {
            break;
        }
        std::string full_name;
        std::cout << "put his Full Name: ";
        std::cin >> full_name;

        for (int i = 0; i < number_emp; i++) {
            if (full_time_worker[i].getFull_Name() == full_name) {

                full_time_worker[i] = FullTimeEmployee(full_time_worker[i].getSalary(), full_name, full_time_worker[i].getAge(), full_time_worker->getSick_leave());

                break;
            }
        }
    }


    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану


    std::cout << "Do you want see information about full time employee? " << std::endl;
    std::cin >> question;
    if (question == "yes") {
        for (int i = 0; i < number_emp; i++) {
            std::cout << full_time_worker[i];
        }
        std:: cout << std::endl << "Promotion have " << full_time_worker->worker_promotion() << "employee";
    }

    int employees_salary = 0;

    employees_salary = Employee_salary(full_time_worker, number_emp, employees_salary);

    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану



    std::cout << "enter number of part time employee: ";
    std::cin >> number_emp;

    PartTimeEmployee *part_time_worker = new PartTimeEmployee [number_emp];

    for (int i = 0; i < number_emp; i++) {
        part_time_worker[i] = PartTimeEmployee(i);
    }

    std::cout << "Do you want see information about part time employee? " << std::endl;
    std::cin >> question;
    if (question == "yes") {
        for (int i = 0; i < number_emp; i++) {
            std::cout << part_time_worker[i];
        }
    }

    for (int i = 0; i < number_emp; i++) {
        employees_salary = employees_salary + part_time_worker[i].getIncome();
    }

    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану

    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану

    Payout payment;

    payment = Payout(SetPayInfo(question));

    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану

    payment.getInfo();

    Bank profit;
    BankQuestoin(profit, question);


    std::cout << "Do you want see information about profit? " << std::endl;
    std::cin >> question;
    if (question == "yes") {
        profit.getInfo();
        profit.netProfit(employees_salary, profit.getMonthly_Profit(), payment);
    }


    std::cout << std::endl << std::endl << std::endl; // потрібно замінити на очищення екрану

    profit.setAssets();

    std::cout << "Do you want see your assets? (write 'yes' or 'no')" << std::endl;
    std::cin >> question;
    if (question == "yes") GetBankAssets(profit);


    delete[] full_time_worker;
    return 0;

}

void BankQuestoin(Bank& profit, std::string &question) {

    int monthly_profit, workdays;

    std::cout << "Enter name of bank in which company save money (write 'skip' to skip): ";
    std::cin >> question;
    if (question != "skip") {
        profit = Bank(question);
        std::cout << "Enter company monthly's profit: (type '0' to skip)";
        std::cin >> monthly_profit;
        if (monthly_profit != 0) {
            profit = Bank(question, monthly_profit);
            std::cout << "Enter company's workdays: (type '0' to skip)";
            std::cin >> workdays;
            if (workdays != 0) {
                profit = Bank(question, monthly_profit, workdays);
                std::cout << std::endl;
            }
        }
    }
}

void GetBankAssets(const Bank profit) {
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            std::cout << "Bank assets in uah: ";
        }
        if (i == 1) {
            std::cout << "Bank assets in usd: ";
        }
        if (i == 2) {
            std::cout << "Bank assets in eur: ";
        }

        std::cout << " " << profit.getAssets(i) << std::endl;
    }
}

Payout SetPayInfo(std::string & question){
    int unexpected_expenses;
    int premium = 0;
    std::string payment_day;
    Payout payment;

    std::cout << "On what day is the salary payment scheduled? (write 'skip' to skip)" << std::endl;
    std::cin >> question;
    if (question != "skip") {
        payment_day = question;
        payment = Payout(payment_day);
        std::cout << "Do you want enter premium? (write 'yes' or 'no')" << std::endl;
        std::cin >> question;
        if (question == "yes") {
            std::cout << "How much is allocated for the premium? ";
            std::cin >> premium;
            payment = Payout(premium, payment_day);
            std::cout << "Do you want enter unexpected expenses? (write 'yes' or 'no')" << std::endl;
            std::cin >> question;
            if (question == "yes") {
                std::cout << "How much is unexpected expenses? ";
                std::cin >> unexpected_expenses;
                payment = Payout(unexpected_expenses, premium, payment_day);
            }
        }
    }
    return payment;
}

int Employee_salary(FullTimeEmployee* full_time_worker, int number_emp, int employees_salary){
    for (int i = 0; i < number_emp; i=i+2) {
        if(i+1 < number_emp){
            employees_salary = employees_salary + (full_time_worker[i] + full_time_worker[i+1]);
        }
        else{
            employees_salary = employees_salary + full_time_worker->getSalary();
        }
    }
    return  employees_salary;
}