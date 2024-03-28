#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <memory>
#include "Bank.h"
#include "Payout.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"

void MenuManager();

void MenuClient();

void AddFullEmployeeInfo();

void SeeFullEmployeeInfo();

void ChangeFullEmployeeInfo();

void AddPartEmployeeInfo();

void SeePartEmployeeInfo();

void ChangePartEmployeeInfo();

void SeeBriefEmployeeInfo();

void AddProfitInfo(Bank &profit, std::string &question);

void SeeProfitInfo(Bank &profit);

void AddCompanyInfo(Bank &profit);

void AddPayoutInfo(Payout &payout, std::string &question);

void SeePayoutInfo(Payout &payout);

int Employee_salary(FullTimeEmployee *full_time_worker, int number_emp, int employees_salary);

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
                            gap();
                            MenuManager();
                        }
                    }
                    catch (bool) {
                        std::cerr << "Password is not right\n You have " << 2 - i << " attempt\n";
                    }
                }
            } else if (answer == "client") {
                user_name = true;
                gap();
                MenuClient();
            } else {
                throw false;
            }
        }
        catch (bool) {
            std::cerr << "You don't write 'client' or 'manager', try again\n";
        }
    }


    return 0;
}


void MenuManager() {
    int action;
    std::string question;
    for (int j = 0; j < 1;) {
        system("pause");
        std::cout << "What do you want to do?\n" <<
                  "1. Add new or change info employee\n" <<                               // ready
                  "2. See information about employee\n" <<                                // ready
                  "3. Add information about company profit\n" <<                          // ready
                  "4. See information about company profit\n" <<                          // ready
                  "5. Add information about payout\n" <<                                  // ready
                  "6. See information about payout\n" <<                                  // ready
                  "7. Set assets\n" <<                                                    // ready (should be improved)
                  "8. See assets\n" <<                                                    // ready (should be improved)
                  "9. Exit\n";
        int i = 0;
        while (i < 1) {
            try {
                std::cin >> action;
                if (action == 1 or action == 2) {
                    int emp_act, none = 0;
                    if (!std::filesystem::exists("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt")) {
                        std::ofstream fileStream("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
                        fileStream << "0\n";
                        fileStream.close();
                    }
                    if (!std::filesystem::exists("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt")) {
                        std::ofstream fileStream("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt");
                        fileStream << "0\n";
                        fileStream.close();
                    }
                    i = 1;
                    if (action == 1) {
                        std::cout << "Which type of employee?\n" <<
                                  "1. Full-time employee\n" <<
                                  "2. Part-time employee\n" <<
                                  "3. Change info about full-time employee\n" <<
                                  "4. Change info about part-time employee\n";
                        std::cin >> emp_act;
                        if (emp_act == 1) {
                            AddFullEmployeeInfo();
                        }
                        if (emp_act == 2) {
                            AddPartEmployeeInfo();
                        }
                        if (emp_act == 3) {
                            ChangeFullEmployeeInfo();
                        }
                        if (emp_act == 4) {
                            ChangePartEmployeeInfo();
                        }
                    }
                    if (action == 2) {
                        std::cout << "Which type of employee?\n" <<
                                  "1. Full-time employee\n" <<
                                  "2. Part-time employee\n";
                        std::cin >> emp_act;
                        if (emp_act == 1) {
                            SeeFullEmployeeInfo();
                        }
                        if (emp_act == 2) {
                            SeePartEmployeeInfo();
                        }
                    }
                } else if (action == 3 or action == 4) {
                    i = 1;
                    Bank profit;
                    profit.readInfoFromFile();
                    if (action == 3) {
                        AddCompanyInfo(profit);
                        AddProfitInfo(profit, question);
                    }
                    if (action == 4) {
                        SeeProfitInfo(profit);
                    }
                    profit.writeInfoInFile();
                } else if (action == 5 or action == 6) {
                    i = 1;
                    Payout payout;
                    payout.readInfoFromFile();
                    if (action == 5) {
                        AddPayoutInfo(payout, question);
                    }
                    if (action == 6) {
                        SeePayoutInfo(payout);
                    }
                    payout.writeInfoInFile();
                } else if (action == 7 or action == 8) {
                    i = 1;
                    Bank profit;
                    if (action == 7) {
                        profit.setAssets();
                        profit.writeAssetsInfo();
                        gap();
                    }
                    if (action == 8) {
                        profit.readAssetsInfo();
                        profit.getAssets();
                        gap();
                    }
                } else if (action == 9) {
                    i = 1;
                    j = 1;
                } else {
                    throw false;
                }
            }
            catch (bool) {
                std::cerr << "You write wrong number, try again\n";
            }
        }
    }

}

void MenuClient() {
    int action;
    std::string question;
    std::fstream fin("D:\\payment_system_oop\\savings_file\\Client_history.txt", std::ios::app);
    fin << "\n\n";
    for (int j = 0; j < 1;) {
        system("pause");
        std::cout << "What do you want to do?\n" <<
                  "1. See information about employee\n" <<
                  "2. See information about payout\n" <<
                  "3. See information about company assets\n" <<
                  "4. Exit\n";
        int i = 0;
        while (i < 1) {
            std::cin >> action;
            try {
                if (action == 1) {
                    fin << "Client saw information about employee - ";
                    SeeBriefEmployeeInfo();
                    i = 1;
                } else if (action == 2) {
                    fin << "Client saw information about payout\n";
                    i = 1;
                    std::string payout;
                    std::ifstream f_payout("D:\\payment_system_oop\\savings_file\\Payout_info.txt");
                    if (f_payout.is_open()) {
                        f_payout >> payout;
                        std::cout << "\n\n Payout will be paid on "<< payout;
                        gap();
                    }
                }else if(action == 3){
                    i = 1;
                    Bank profit;
                    profit.readAssetsInfo();
                    profit.getAssets();
                }
                else if (action == 4) {
                    i = 1;
                    j = 1;
                } else {
                    throw false;
                }
            }
            catch (bool) {
                std::cerr << "You write wrong number, try again\n";
                i = 1;
            }
        }
    }
    fin.close();
}

void AddFullEmployeeInfo() {
    int emp_numb, numb, full_numb;
    std::cout << "How many new employee do you want to add? ";

    std::cin >> emp_numb;

    if (emp_numb > 0) {
        std::vector<std::shared_ptr<FullTimeEmployee>> full_time_employee;


        std::ifstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
        fin >> numb;
        full_numb = emp_numb + numb;
        fin.close();

        std::fstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt",
                          std::ios::in | std::ios::out);
        fout.seekp(0);
        fout << full_numb;
        fout.close();

        for (int i = 0; i < emp_numb; i++) {
            full_time_employee.push_back(std::make_shared<FullTimeEmployee>(i));
            full_time_employee[i]->writeFullTimeEmployeeInfo();
        }
    }
}

void SeeFullEmployeeInfo() {
    int numb, pos = 0;

    std::fstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::in);
    fin >> numb;

    std::vector<std::shared_ptr<FullTimeEmployee>> full_time_employee;
    for (int i = 0; i < numb; i++) {
        full_time_employee.push_back(std::make_shared<FullTimeEmployee>());
    }
    for (int i = 0; i < numb; i++) {
        full_time_employee[i]->readFullTimeEmployeeInfo(pos);
        std::cout << *full_time_employee[i];
        pos = pos + 6;
    }
    fin.close();
}

void ChangeFullEmployeeInfo() {

    int numb, pos = 0;

    std::fstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::in);
    fin >> numb;
    std::vector<std::shared_ptr<FullTimeEmployee>> full_time_employee;
    for (int i = 0; i < numb; i++) {
        full_time_employee.push_back(std::make_shared<FullTimeEmployee>());
    }
    for (int i = 0; i < numb; i++) {
        full_time_employee[i]->readFullTimeEmployeeInfo(pos);
        pos = pos + 6;
    }
    fin.close();
    std::ofstream fcls("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
    fcls.close();

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

        pos = 0;

        for (int i = 0; i < numb; i++) {
            if (full_time_employee[i]->getFull_Name() == full_name) {
                *full_time_employee[i] = FullTimeEmployee(full_name, full_time_employee[i]->getAge(),
                                                          full_time_employee[i]->getSick_leave(), pos);
                break;
            }
        }
    }

    std::fstream fout("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt");
    fout.seekp(0);
    fout << numb;
    fout.close();

    for (int i = 0; i < numb; i++) {
        full_time_employee[i]->writeFullTimeEmployeeInfo();
    }
}

void AddPartEmployeeInfo() {
    int emp_numb, numb, full_numb;
    std::cout << "How many new employee do you want to add? ";

    std::cin >> emp_numb;

    if (emp_numb > 0) {
        std::vector<std::shared_ptr<PartTimeEmployee>> part_time_employee;

        std::ifstream fin("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt");
        fin >> numb;
        full_numb = emp_numb + numb;
        fin.close();

        std::fstream fout("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt",
                          std::ios::in | std::ios::out);
        fout.seekp(0);
        fout << full_numb;
        fout.close();

        for (int i = 0; i < emp_numb; i++) {
            part_time_employee.push_back(std::make_shared<PartTimeEmployee>(i));
            part_time_employee[i]->writePartTimeEmployeeInfo();
        }
    }
}

void SeePartEmployeeInfo() {
    int numb, pos = 0;

    std::fstream fin("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt", std::ios::in);
    fin >> numb;

    std::vector<std::shared_ptr<PartTimeEmployee>> part_time_employee;
    for (int i = 0; i < numb; i++) {
        part_time_employee.push_back(std::make_shared<PartTimeEmployee>());
    }
    for (int i = 0; i < numb; i++) {
        part_time_employee[i]->readPartTimeEmployeeInfo(pos);
        std::cout << *part_time_employee[i];
        pos = pos + 5;
    }
    fin.close();
}

void ChangePartEmployeeInfo() {

    int numb, pos = 0;

    std::fstream fin("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt", std::ios::in);
    fin >> numb;
    std::vector<std::shared_ptr<PartTimeEmployee>> part_time_employee;
    for (int i = 0; i < numb; i++) {
        part_time_employee.push_back(std::make_shared<PartTimeEmployee>());
    }
    for (int i = 0; i < numb; i++) {
        part_time_employee[i]->readPartTimeEmployeeInfo(pos);
        pos = pos + 6;
    }
    fin.close();
    std::ofstream fcls("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt");
    fcls.close();

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

        pos = 0;

        for (int i = 0; i < numb; i++) {
            if (part_time_employee[i]->getFull_Name() == full_name) {
                *part_time_employee[i] = PartTimeEmployee(full_name, part_time_employee[i]->getAge());
                break;
            }
        }
    }

    std::fstream fout("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt",
                      std::ios::in | std::ios::out);
    fout.seekp(0);
    fout << numb;
    fout.close();

    for (int i = 0; i < numb; i++) {
        part_time_employee[i]->writePartTimeEmployeeInfo();
    }
}

void SeeBriefEmployeeInfo() {
    std::string action;
    bool quest = true;

    int numb, pos = 0;

    std::fstream fin("D:\\payment_system_oop\\savings_file\\Full_time_employee_info.txt", std::ios::in);
    fin >> numb;

    std::vector<std::shared_ptr<FullTimeEmployee>> full_time_employee;
    do {
        std::cout << "Type name of employee: ";
        std::cin >> action;
        std::fstream fin_c("D:\\payment_system_oop\\savings_file\\Client_history.txt", std::ios::app);
        fin_c << action << " ";
        fin_c.close();
        pos = 0;
        for (int i = 0; i < numb; i++) {

            full_time_employee.push_back(std::make_shared<FullTimeEmployee>());
            full_time_employee[i]->readFullTimeEmployeeInfo(pos);
            if (full_time_employee[i]->getFull_Name() == action) {
                full_time_employee[i]->getBriefInfo();
                i = numb;
                gap();
                std::cout << "Do you want see info about another employee? (type yes or no)";
                std::cin >> action;
                if (action == "no") quest = false;
            } else if (i >= numb - 1) {
                std::fstream fin_p("D:\\payment_system_oop\\savings_file\\Part_time_employee_info.txt",
                                   std::ios::in);
                int numb_p;
                pos = 0;
                fin_p >> numb_p;
                for (int k = 0; k < numb_p; k++) {
                    std::vector<std::shared_ptr<PartTimeEmployee>> part_time_employee;
                    part_time_employee.push_back(std::make_shared<PartTimeEmployee>());
                    part_time_employee[i]->readPartTimeEmployeeInfo(pos);
                    if (part_time_employee[i]->getFull_Name() == action) {
                        part_time_employee[i]->getBriefInfo();
                        k = numb_p;
                        i = numb;
                        gap();
                        std::cout << "Do you want see info about another employee? (type yes or no)";
                        std::cin >> action;
                        if (action == "no") quest = false;
                    }
                    pos = pos + 5;

                }
                fin_p.close();
            }
            pos = pos + 6;
        }
    } while (quest);
    fin.close();
}

void AddPayoutInfo(Payout &payout, std::string &question) {
    int unexpected_expenses;
    int premium = 0;
    std::string payment_day;

    std::cout << "On what day is the salary payment scheduled? (write 'skip' to skip)" << std::endl;
    std::cin >> question;
    if (question != "skip") {
        payment_day = question;
        payout = Payout(payment_day);
        std::cout << "Do you want enter premium? (write 'yes' or 'no')" << std::endl;
        std::cin >> question;
        if (question == "yes") {
            std::cout << "How much is allocated for the premium? ";
            std::cin >> premium;
            payout = Payout(premium, payment_day);
            std::cout << "Do you want enter unexpected expenses? (write 'yes' or 'no')" << std::endl;
            std::cin >> question;
            if (question == "yes") {
                std::cout << "How much is unexpected expenses? ";
                std::cin >> unexpected_expenses;
                payout = Payout(unexpected_expenses, premium, payment_day);
            }
        }
    }
}

void SeePayoutInfo(Payout &payout) {
    payout.getInfo();
    std::cout << "\n" << "\n";
}

void AddProfitInfo(Bank &profit, std::string &question) {

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

void SeeProfitInfo(Bank &profit) {
    profit.getInfo();
    std::cout << "\n" << "\n";
}

void AddCompanyInfo(Bank &profit) {
    profit.setName_of_company();
    profit.setFinance();
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

void gap() {
    std::cout << "--------------------------------------" << std::endl << std::endl
              << "--------------------------------------" << std::endl;
} // потрібно замінити на очищення екрану