#include "port.h"
#include "vintage_port.h"

#include <iostream>

int main() {
    Port p1("Fonseca", "Crusted", 9);
    Port p2(p1);
    std::cout << "p1:\n" << p1 <<"\np2:\n" << p2 << '\n';
    std::cout << "Drinking a pair of bottles of p1:\n";
    p1 -= 2;
    p1.Show();
    std::cout << "Trying to drink more than we have:\n";
    p1 -= 8;
    std::cout << "-===================================================-\n";

    VintagePort vp1("Brandy", 9, "Dunno", 1889);
    VintagePort vp2(vp1);
    std::cout << "vp1:\n" << vp1 <<"\nvp2:\n" << vp2 << '\n';
    std::cout << "After drinking a bottle of v2:\n";
    vp2 -=1;
    std::cout << vp2 << '\n';
    VintagePort vp3;
    std::cout << "vp3:\n";
    vp3.Show();
    return 0;
}
