#include "Employee.h"

#include <iostream>
#include <stdexcept>

Employee::Employee(const std::string& n, double sal) : Person(n) {
    if (sal < 0) {
        throw std::invalid_argument("Salary cannot be negative.");
    }

    this->sal = sal;
}

double Employee::getSalary() const {
    return sal;
}

void Employee::displayInfo() const {
    std::cout << "Employee\n";
    std::cout << "Name: " << n << "\n";
    std::cout << "Salary: " << sal << "\n";
}