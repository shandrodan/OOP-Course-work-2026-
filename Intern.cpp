#include "Intern.h"

#include <iostream>
#include <stdexcept>

Intern::Intern(const std::string& n, double sal, const std::string& uni)
    : Employee(n, sal) {
    if (uni.empty()) {
        throw std::invalid_argument("University cannot be empty.");
    }

    this->uni = uni;
}

void Intern::displayInfo() const {
    std::cout << "Intern\n";
    std::cout << "Name: " << n << "\n";
    std::cout << "Salary: " << sal << "\n";
    std::cout << "University: " << uni << "\n";
}