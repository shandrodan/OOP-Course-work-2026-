#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
private:
    std::string lng;

public:
    Developer(const std::string& n, double sal, const std::string& lng);

    void displayInfo() const override;
};

#endif