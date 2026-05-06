#include "Manager.h"

#include <iostream>
#include <stdexcept>

Manager::Manager(const std::string& n, double sal, int ts) : Employee(n, sal) {
    if (ts < 0) {
        throw std::invalid_argument("Team size cannot be negative.");
    }

    this->ts = ts;
}

void Manager::displayInfo() const {
    std::cout << "Manager\n";
    std::cout << "Name: " << n << "\n";
    std::cout << "Salary: " << sal << "\n";
    std::cout << "Team size: " << ts << "\n";
}