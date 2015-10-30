#include "julian.hpp"


lab2::Julian::Julian() {
}

lab2::Julian::Julian(const Julian& other) {
}

lab2::Julian::~Julian() {
}

lab2::Julian& lab2::Julian::operator=(const Julian& rhs) {
    return *this;
}

lab2::Julian& lab2::Julian::operator++(int) {
    return *this;
}

lab2::Julian& lab2::Julian::operator--(int) {
    return *this;
}

lab2::Julian& lab2::Julian::operator++() {
    return *this;
}

lab2::Julian& lab2::Julian::operator--() {
    return *this;
}

lab2::Julian& lab2::Julian::operator+=(const long rhs) {
    return *this;
}

lab2::Julian& lab2::Julian::operator-=(const long rhs) {
    return *this;
}

unsigned int lab2::Julian::week_day() {
    return 0;
}

unsigned int lab2::Julian::days_this_month() {
    return 0;
}

std::string lab2::Julian::week_day_name() {
    return std::string();
}

void lab2::Julian::add_year(int n) {
}

void lab2::Julian::add_month(int n) {
}

int lab2::Julian::mod_julian_day() {
    return 0;
}

bool lab2::Julian::is_leap_year() {
    return _year % 4 == 0;
}
