# OOP Course Work 2026: Employee Management System

Done by: Shyshenko Danylo ITfu-25/1

## What This Project Does

This project is a small C++ console application for managing employees in a company. It stores different employee types, prints their details, sorts them by salary, searches by name, counts employees above a salary threshold, and calculates the total payroll.

The program models a realistic business domain instead of using artificial placeholder classes. The main idea is that a company can contain different kinds of employees, and each employee type has its own data and behavior.

## Main Functionality

- Add employees to a company
- Store multiple employee types in one collection
- Display all employees
- Sort employees by salary
- Search for an employee by name
- Count employees whose salary is above a chosen value
- Calculate total salary of all employees
- Handle invalid input using exceptions

## Class Structure

The class hierarchy is:

`Person -> Employee -> Manager`

`Person -> Employee -> Developer`

`Person -> Employee -> Intern`

### Classes

- `Person`: abstract base class that stores the employee name and declares `displayInfo()`
- `Employee`: derived from `Person`, adds salary
- `Manager`: derived from `Employee`, adds team size
- `Developer`: derived from `Employee`, adds programming language
- `Intern`: derived from `Employee`, adds university
- `Company`: manages the collection of employees and provides operations such as sorting, searching, counting, and total salary calculation

## Project Files

- `main.cpp`: demonstrates program usage
- `Person.h` / `Person.cpp`: base abstract class
- `Employee.h` / `Employee.cpp`: common employee functionality
- `Manager.h` / `Manager.cpp`: manager implementation
- `Developer.h` / `Developer.cpp`: developer implementation
- `Intern.h` / `Intern.cpp`: intern implementation
- `Company.h` / `Company.cpp`: company container and algorithms
- `Utils.h`: generic helper template for printing collections

## How to Build

If you have a C++ compiler installed, compile with:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o app
```

You can also use another standard such as C++14 or C++20 if your compiler supports the code.

## How to Run

Run the program with:

```bash
./app
```

The program first demonstrates the main features automatically:

- adds several employees
- shows exception handling for invalid salary
- prints all employees
- sorts employees by salary
- searches for an existing and a missing employee
- counts employees above salary `2000`
- prints the total salary

At the end, it asks the user to enter an employee name for interactive search.

## How the Program Works

1. `main.cpp` creates a `Company` object.
2. Different employee objects are created using `std::make_unique`.
3. They are added to the company through `Company::add`.
4. The company stores all employees polymorphically as `std::unique_ptr<Employee>`.
5. Operations like printing, sorting, and searching are performed on that collection.
6. When `displayInfo()` is called, the correct overridden version is selected based on the real object type.

## Criteria Mapping

### 1. Polymorphism with at least two levels of inheritance and at least four separate classes

Implemented through this inheritance chain:

- `Person`
- `Employee : public Person`
- `Manager : public Employee`
- `Developer : public Employee`
- `Intern : public Employee`

This gives two inheritance levels:

- level 1: `Person -> Employee`
- level 2: `Employee -> Manager`, `Employee -> Developer`, `Employee -> Intern`

Polymorphism is used through:

- pure virtual function `displayInfo()` in `Person`
- overridden `displayInfo()` in `Employee`, `Manager`, `Developer`, and `Intern`
- storage of derived objects through base-class pointers: `std::vector<std::unique_ptr<Employee>>`

### 2. Classes declared and defined in separate header/source files

Implemented by separating declarations and definitions:

- declarations in `.h` files
- definitions in `.cpp` files

Examples:

- `Person.h` and `Person.cpp`
- `Employee.h` and `Employee.cpp`
- `Manager.h` and `Manager.cpp`
- `Developer.h` and `Developer.cpp`
- `Intern.h` and `Intern.cpp`
- `Company.h` and `Company.cpp`

### 3. At least one standard library container and at least two algorithms

Standard library container used:

- `std::vector<std::unique_ptr<Employee>>` in `Company`

Algorithms used:

- `std::sort` in `Company::sortSal()`
- `std::find_if` in `Company::find()`
- `std::count_if` in `Company::cntHigh()`

This exceeds the requirement of at least two algorithms.

### 4. Error management with at least one exception handling case

Exception handling is used in multiple places.

Validation with exceptions:

- empty name throws `std::invalid_argument` in `Person`
- negative salary throws `std::invalid_argument` in `Employee`
- negative team size throws `std::invalid_argument` in `Manager`
- empty language throws `std::invalid_argument` in `Developer`
- empty university throws `std::invalid_argument` in `Intern`
- adding a null employee throws `std::invalid_argument` in `Company::add`
- searching or showing invalid state throws `std::runtime_error` in `Company`

Handling exceptions:

- `main.cpp` uses `try` / `catch` blocks when adding employees and when calling company operations

One visible example is the attempt to add:

```cpp
Developer("Tom", -1000, "Python")
```

This triggers an exception because salary cannot be negative.

### 5. The software should perform a reasonably useful function

The program performs a useful business-related task: basic employee management for a company.

It can:

- keep different employee types in one system
- print structured employee data
- sort employees by salary
- search for a specific employee
- produce simple salary statistics

This is a practical domain model rather than a trivial class demonstration.

## Bonus: User-Defined Generic Functionality

The bonus requirement is implemented in `Utils.h`:

```cpp
template <typename T>
void printAll(const T& c)
```

This is a user-defined generic function template that can print any compatible container whose elements support `displayInfo()`. In this project, it is used to print the company employee collection.

## Example Summary of Output

When the program runs successfully, it demonstrates:

- 3 valid employees added
- 1 invalid employee rejected by exception handling
- employees displayed before and after sorting
- successful search for `Anna`
- failed search for `John`
- count of salaries above `2000`
- total salary equal to `6300`

## Conclusion

This project meets all required coursework criteria and also includes a bonus generic template. It demonstrates inheritance, runtime polymorphism, separate compilation units, STL containers and algorithms, exception handling, and a useful application domain in a clear and manageable C++ program.
