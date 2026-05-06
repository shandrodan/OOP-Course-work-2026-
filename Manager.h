#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    int ts;

public:
    Manager(const std::string& n, double sal, int ts);

    void displayInfo() const override;
};

#endif