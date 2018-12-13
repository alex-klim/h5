/*
 * =====================================================================================
 *
 *       Filename:  vintage_port.cpp
 *
 *    Description:  source for vintage port
 *
 *        Version:  1.0
 *        Created:  12/11/2018 07:06:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Alex Klim
 *   Organization: home
 *
 * =====================================================================================
 */
#include "vintage_port.h"

#include <iostream>
#include <cstring>

VintagePort::VintagePort() : Port("Unknown", "Vintage", 0), year(0) {
    nickname = new char[NICKNAME_MAX];
    strcpy(nickname, "defalut");
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "vintage", b) {
        nickname = new char[NICKNAME_MAX];
        strncpy(nickname, nn, NICKNAME_MAX-1);
        nickname[NICKNAME_MAX-1] = '\0';
        year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
    : Port(static_cast<const Port&>(vp)), year(vp.year) {
        nickname = new char[NICKNAME_MAX];
        strcpy(nickname, vp.nickname);
}

VintagePort& VintagePort::operator= (const VintagePort& vp) {
    if (this != &vp) {
        Port::operator=(static_cast<const Port&>(vp));
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    return *this;
}

void VintagePort::Show() const {
    Port::Show();
    std::cout << "Nickname: " << nickname
        << "\nYear: " << year <<'\n';
}

std::ostream& operator<< (std::ostream& os, const VintagePort& vp) {
    os << static_cast<const Port>(vp)
        << ", " << vp.nickname << ", " << vp.year;
    return os;
}
