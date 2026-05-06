#include "Company.h"
#include "Developer.h"
#include "Intern.h"
#include "Manager.h"
#include "Utils.h"

#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

class InputEnded : public std::runtime_error {
public:
    InputEnded() : std::runtime_error("Input ended.") {}
};

std::string trim(const std::string& text) {
    auto start = std::find_if_not(text.begin(), text.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });

    auto end = std::find_if_not(text.rbegin(), text.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();

    if (start >= end) {
        return "";
    }

    return std::string(start, end);
}

std::string readLine(const std::string& prompt) {
    std::cout << prompt;

    std::string value;
    if (!std::getline(std::cin, value)) {
        throw InputEnded();
    }

    return value;
}

std::string readNonEmptyLine(const std::string& prompt) {
    while (true) {
        std::string value = trim(readLine(prompt));

        if (!value.empty()) {
            return value;
        }

        std::cin.clear();
        std::cout << "This value cannot be empty. Please try again.\n";
    }
}

double readDouble(const std::string& prompt) {
    while (true) {
        std::string input = trim(readLine(prompt));
        std::istringstream stream(input);

        double value;
        char extra;
        if (stream >> value && !(stream >> extra)) {
            return value;
        }

        std::cin.clear();
        std::cout << "Please enter a valid number.\n";
    }
}

int readInt(const std::string& prompt) {
    while (true) {
        std::string input = trim(readLine(prompt));
        std::istringstream stream(input);

        int value;
        char extra;
        if (stream >> value && !(stream >> extra)) {
            return value;
        }

        std::cin.clear();
        std::cout << "Please enter a whole number.\n";
    }
}

void printMenu() {
    std::cout << "\nCompany Employee Management\n";
    std::cout << "===========================\n";
    std::cout << "1. Add manager\n";
    std::cout << "2. Add developer\n";
    std::cout << "3. Add intern\n";
    std::cout << "4. Show all employees\n";
    std::cout << "5. Sort employees by salary\n";
    std::cout << "6. Search employee by name\n";
    std::cout << "7. Count employees with salary above a value\n";
    std::cout << "8. Show total salary\n";
    std::cout << "9. Remove employee by name\n";
    std::cout << "0. Exit\n";
}

void addManager(Company& company) {
    std::string name = readNonEmptyLine("Name: ");
    double salary = readDouble("Salary: ");
    int teamSize = readInt("Team size: ");

    company.add(std::make_unique<Manager>(name, salary, teamSize));
    std::cout << "Manager added.\n";
}

void addDeveloper(Company& company) {
    std::string name = readNonEmptyLine("Name: ");
    double salary = readDouble("Salary: ");
    std::string language = readNonEmptyLine("Programming language: ");

    company.add(std::make_unique<Developer>(name, salary, language));
    std::cout << "Developer added.\n";
}

void addIntern(Company& company) {
    std::string name = readNonEmptyLine("Name: ");
    double salary = readDouble("Salary: ");
    std::string university = readNonEmptyLine("University: ");

    company.add(std::make_unique<Intern>(name, salary, university));
    std::cout << "Intern added.\n";
}

void searchByName(const Company& company) {
    std::string name = readNonEmptyLine("Employee name: ");
    company.find(name);
}

void countAboveSalary(const Company& company) {
    double salary = readDouble("Salary threshold: ");
    int count = company.cntHigh(salary);

    std::cout << "Employees with salary above " << salary << ": " << count << "\n";

    if (count > 0) {
        std::cout << "Matching employees:\n";
        printMatching(company.getEmployees(), [salary](const auto& employee) {
            return employee->getSalary() > salary;
        });
    }
}

void removeByName(Company& company) {
    std::string name = readNonEmptyLine("Employee name to remove: ");
    company.removeByName(name);
    std::cout << "Employee removed.\n";
}

}

int main() {
    Company company;
    bool running = true;

    while (running) {
        try {
            printMenu();
            int choice = readInt("Choose option: ");

            switch (choice) {
            case 1:
                addManager(company);
                break;
            case 2:
                addDeveloper(company);
                break;
            case 3:
                addIntern(company);
                break;
            case 4:
                company.show();
                break;
            case 5:
                company.sortSal();
                std::cout << "Employees sorted by salary.\n";
                company.show();
                break;
            case 6:
                searchByName(company);
                break;
            case 7:
                countAboveSalary(company);
                break;
            case 8:
                std::cout << "Total salary: " << company.totalSal() << "\n";
                break;
            case 9:
                removeByName(company);
                break;
            case 0:
                running = false;
                std::cout << "Goodbye.\n";
                break;
            default:
                std::cout << "Please choose a menu option from 0 to 9.\n";
                break;
            }
        }
        catch (const InputEnded&) {
            std::cout << "\nInput ended. Exiting.\n";
            break;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
