#include "port.h"

#include <cstring>
#include <iostream>

Port::Port(const char* br, const char* st, int b) {
    brand = new char[strlen(br)+1];
    strcpy(brand, br);
    strncpy(style, st,
            strlen(st) < STYLE_MAX-1 ? strlen(st)+1 : STYLE_MAX);
    style[STYLE_MAX-1] = '\0';
    bottles = b;
}

Port::Port(const Port& p) {
    *this = p;
}

Port& Port::operator= (const Port& p) {
    if (this != &p) {
        brand = new char[strlen(p.brand)+1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    return *this;
}

Port& Port::operator+= (int b) {
    int temp = bottles + b;
    if (temp < 0) {
        std::cerr << "This operation requires more bottles than you have\n";
    } else {
        bottles = temp;
    }
    return *this;
}

Port& Port::operator-= (int b) {
    int temp = bottles - b;
    if (temp < 0) {
        std::cerr << "This operation requires more bottles than you have\n";
    } else {
        bottles = temp;
    }
    return *this;
}

void Port::Show() const {
    std::cout << "Brand: " << brand
        << "\nKind: " << style
        << "\nBottles: " << bottles << '\n';
}

std::ostream& operator<< (std::ostream& os, const Port& p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
