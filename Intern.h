#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"

class Intern : public Employee {
private:
    std::string uni;

public:
    Intern(const std::string& n, double sal, const std::string& uni);

    void displayInfo() const override;
};

#endif