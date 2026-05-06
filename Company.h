#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"

#include <memory>
#include <string>
#include <vector>

class Company {
private:
    std::vector<std::unique_ptr<Employee>> emp;

    std::vector<std::unique_ptr<Employee>>::iterator findEmployee(const std::string& n);
    std::vector<std::unique_ptr<Employee>>::const_iterator findEmployee(const std::string& n) const;

public:
    void add(std::unique_ptr<Employee> e);
    void show() const;
    const std::vector<std::unique_ptr<Employee>>& getEmployees() const;

    void sortSal();
    void find(const std::string& n) const;
    void removeByName(const std::string& n);
    bool hasEmployee(const std::string& n) const;

    int cntHigh(double s) const;
    double totalSal() const;
};

#endif
