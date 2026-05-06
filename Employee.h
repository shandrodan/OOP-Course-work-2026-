#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    double sal;

public:
    Employee(const std::string& n, double sal);
    virtual ~Employee() = default;

    double getSalary() const;

    void displayInfo() const override;
};

#endif