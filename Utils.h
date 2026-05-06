#ifndef UTILS_H
#define UTILS_H

#include <cstddef>
#include <iostream>

template <typename Container, typename Predicate>
std::size_t printMatching(const Container& c, Predicate pred) {
    std::size_t printed = 0;

    for (const auto& e : c) {
        if (pred(e)) {
            e->displayInfo();
            std::cout << "----------------\n";
            ++printed;
        }
    }

    return printed;
}

template <typename Container>
void printAll(const Container& c) {
    printMatching(c, [](const auto&) {
        return true;
    });
}

#endif
