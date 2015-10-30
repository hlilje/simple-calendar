#include "gregorian.hpp"


lab2::Gregorian& lab2::Gregorian::operator++() {
    return *this;
}

lab2::Gregorian& lab2::Gregorian::operator--() {
    return *this;
}

lab2::Gregorian& lab2::Gregorian::operator+=(const long rhs) {
    return *this;
}

lab2::Gregorian& lab2::Gregorian::operator-=(const long rhs) {
    return *this;
}

unsigned int lab2::Gregorian::week_day() {
    return 0;
}

unsigned int lab2::Gregorian::days_this_month() {
    return 0;
}

std::string lab2::Gregorian::week_day_name() {
    return std::string();
}

std::string lab2::Gregorian::month_name() {
    return std::string();
}

void lab2::Gregorian::add_year(int n) {
}

void lab2::Gregorian::add_month(int n) {
}

int lab2::Gregorian::mod_julian_day() {
    return 0;
}
