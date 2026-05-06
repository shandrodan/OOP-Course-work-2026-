#include "Developer.h"

#include <iostream>
#include <stdexcept>

Developer::Developer(const std::string& n, double sal, const std::string& lng)
    : Employee(n, sal) {
    if (lng.empty()) {
        throw std::invalid_argument("Language cannot be empty.");
    }

    this->lng = lng;
}

void Developer::displayInfo() const {
    std::cout << "Developer\n";
    std::cout << "Name: " << n << "\n";
    std::cout << "Salary: " << sal << "\n";
    std::cout << "Language: " << lng << "\n";
}