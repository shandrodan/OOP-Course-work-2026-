#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string n;

public:
    Person(const std::string& n);
    virtual ~Person() = default;

    std::string getName() const;

    virtual void displayInfo() const = 0;
};

#endif