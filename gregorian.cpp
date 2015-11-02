#include "gregorian.hpp"


lab2::Gregorian::Gregorian() {
    time_t time; k_time(&time); // Init time
    const struct tm *t = gmtime(&time);
    _year  = t->tm_year + 1900;
    _month = t->tm_mon + 1;
    _day   = t->tm_mday;

    _offset = gregorian_date_to_jdn(_year, _month, _day);
}

lab2::Gregorian::Gregorian(const Gregorian& other) : WesternDate(other) {}

lab2::Gregorian& lab2::Gregorian::operator=(const Gregorian& rhs) {
    return *this;
}

lab2::Gregorian& lab2::Gregorian::operator++(int) {
    return *this;
}

lab2::Gregorian& lab2::Gregorian::operator--(int) {
    return *this;
}

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

unsigned int lab2::Gregorian::days_this_month() {
    return 0;
}

void lab2::Gregorian::add_year(int n) {
}

void lab2::Gregorian::add_month(int n) {
}

int lab2::Gregorian::mod_julian_day() {
    return 0;
}

bool lab2::Gregorian::is_leap_year() {
    return (_year % 4 == 0) && ((_year % 100) != 0 || (_year % 400) == 0);
}
