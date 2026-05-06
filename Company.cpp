#include "Company.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <utility>

std::vector<std::unique_ptr<Employee>>::iterator Company::findEmployee(const std::string& n) {
    return std::find_if(emp.begin(), emp.end(), [&n](const auto& e) {
        return e->getName() == n;
    });
}

std::vector<std::unique_ptr<Employee>>::const_iterator Company::findEmployee(const std::string& n) const {
    return std::find_if(emp.begin(), emp.end(), [&n](const auto& e) {
        return e->getName() == n;
    });
}

void Company::add(std::unique_ptr<Employee> e) {
    if (e == nullptr) {
        throw std::invalid_argument("Employee cannot be empty.");
    }

    if (hasEmployee(e->getName())) {
        throw std::invalid_argument("Employee with this name already exists.");
    }

    emp.push_back(std::move(e));
}

void Company::show() const {
    if (emp.empty()) {
        throw std::runtime_error("Company has no employees.");
    }

    for (const auto& e : emp) {
        e->displayInfo();
        std::cout << "----------------\n";
    }
}

const std::vector<std::unique_ptr<Employee>>& Company::getEmployees() const {
    return emp;
}

void Company::sortSal() {
    if (emp.empty()) {
        throw std::runtime_error("Cannot sort empty company.");
    }

    std::sort(emp.begin(), emp.end(), [](const auto& a, const auto& b) {
        return a->getSalary() < b->getSalary();
    });
}

void Company::find(const std::string& n) const {
    if (n.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }

    auto it = findEmployee(n);

    if (it == emp.end()) {
        throw std::runtime_error("Employee not found.");
    }

    std::cout << "Employee found:\n";
    (*it)->displayInfo();
    std::cout << "----------------\n";
}

void Company::removeByName(const std::string& n) {
    if (n.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }

    auto it = findEmployee(n);

    if (it == emp.end()) {
        throw std::runtime_error("Employee not found.");
    }

    emp.erase(it);
}

bool Company::hasEmployee(const std::string& n) const {
    if (n.empty()) {
        return false;
    }

    return findEmployee(n) != emp.end();
}

int Company::cntHigh(double s) const {
    return std::count_if(emp.begin(), emp.end(), [s](const auto& e) {
        return e->getSalary() > s;
    });
}

double Company::totalSal() const {
    return std::accumulate(emp.begin(), emp.end(), 0.0, [](double sum, const auto& e) {
        return sum + e->getSalary();
    });
}
