#include "Person.h"

#include <stdexcept>

Person::Person(const std::string& n) {
    if (n.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }

    this->n = n;
}

std::string Person::getName() const {
    return n;
}