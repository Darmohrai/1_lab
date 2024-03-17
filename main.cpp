#include <iostream>
#include "Bank.h"
#include "Payout.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

void MenuManager();


void BankQuestoin(Bank &profit, std::string &question);

void GetBankAssets(Bank &profit);

int Employee_salary(FullTimeEmployee *full_time_worker, int number_emp, int employees_salary);

Payout SetPayInfo(std::string &question);

void gap();

int main() {
    std::string answer;
    bool user_name = false;

    while (user_name == false) {
        std::cout << "Choose one:\n" <<
                  "I am a client\n" <<
                  "I am manager\n" <<
                  "(write 'client' or 'manager')\n";
        std::cin >> answer;

        gap();

        try {
            if (answer == "manager") {
                user_name = true;
                int true_password = 123;
                for (int i = 0; i < 3; i++) {
                    try {
                        std::cout << "Put in your password:";
                        int password;
                        std::cin >> password;
                        if (password != true_password) {
                            throw false;
                        }
                        if (password == true_password) {
                            i = 3;
                            MenuManager();
                        }
                    }
                    catch (bool) {
                        std::cout << "Password is not right\n You have " << 2 - i << " attempt\n";
                    }
                }
            }
            else if (answer == "client") {
                user_name = true;
            }
            else {
                throw false;
            }
        }
        catch (bool) {
            std::cout << "You don't write 'client' or 'manager', try again\n";
            user_name = false;
        }
    }
    return 0;
}


void MenuManager() {
    std::cout << "What do you want to do?\n" <<
              "1. Add new employee\n" <<
              "2. See information about employee\n" <<
              "3. Add information about company profit\n" <<
              "4. See information about company profit\n" <<
              "5. Add information about payout\n" <<
              "6. See information about payout\n";
}


void BankQuestoin(Bank &profit, std::string &question) {

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

void GetBankAssets(Bank &profit) {
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

int Employee_salary(FullTimeEmployee *full_time_worker, int number_emp, int employees_salary) {
    for (int i = 0; i < number_emp; i = i + 2) {
        if (i + 1 < number_emp) {
            employees_salary = employees_salary + (full_time_worker[i] + full_time_worker[i + 1]);
        } else {
            employees_salary = employees_salary + full_time_worker->getSalary();
        }
    }
    return employees_salary;
}

Payout SetPayInfo(std::string &question) {
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

void gap() { std::cout << std::endl << std::endl << std::endl; } // потрібно замінити на очищення екрану

//system("cls");