#include "julian.hpp"


lab2::Julian::Julian() {
    time_t time; k_time(&time); // Init time
    const struct tm *t = gmtime(&time);
    unsigned int year  = t->tm_year + 1900;
    unsigned int month = t->tm_mon + 1;
    unsigned int day   = t->tm_mday;
    const long jdn     = gregorian_date_to_jdn(year, month, day);

    jdn_to_julian_date(jdn, year, month, day);

    _offset = jdn;
    _year = year;
    _month = month;
    _day = day;
}

lab2::Julian::Julian(const unsigned int year,
                     const unsigned int month,
                     const unsigned int day) :
    WesternDate(year, month, day) {
    _offset = julian_date_to_jdn(_year, _month, _day);
}

lab2::Julian::Julian(const Julian & other) : WesternDate(other) {}

long lab2::Julian::julian_date_to_jdn(const unsigned int year,
                                      const unsigned int month,
                                      const unsigned int day) const {
    const unsigned int a = (14 - month) / 2;
    const unsigned int y = year + 4800 - a;
    const unsigned int m = month + (12 * a) - 3;

    return day + ((153 * m + 2) / 5) + (365 * y) + (y / 4) - 32083;
}

lab2::Julian & lab2::Julian::operator=(const Julian & rhs) {
    _offset = rhs._offset;
    _year = rhs._year;
    _month = rhs._month;
    _day = rhs._day;

    return *this;
}

lab2::Julian & lab2::Julian::operator++(int) {
    return *this;
}

lab2::Julian & lab2::Julian::operator--(int) {
    return *this;
}

lab2::Julian & lab2::Julian::operator++() {
    return *this;
}

lab2::Julian & lab2::Julian::operator--() {
    return *this;
}

lab2::Julian & lab2::Julian::operator+=(const long rhs) {
    return *this;
}

lab2::Julian & lab2::Julian::operator-=(const long rhs) {
    return *this;
}

unsigned int lab2::Julian::days_this_month() const {
    return 0;
}

void lab2::Julian::add_year(int n) {
}

void lab2::Julian::add_month(int n) {
}

bool lab2::Julian::is_leap_year() const {
    return _year % 4 == 0;
}

void lab2::Julian::jdn_to_julian_date(const long jdn,
                                      unsigned int & year,
                                      unsigned int & month,
                                      unsigned int & day) const {
    unsigned int y = 4716;
    unsigned int j = 1401;
    unsigned int m = 2;
    unsigned int n = 12;
    unsigned int r = 4;
    unsigned int p = 1461;
    unsigned int v = 3;
    unsigned int u = 5;
    unsigned int s = 153;
    unsigned int w = 2;

    unsigned long f = jdn + j;
    unsigned long e = (r * f) + v;
    unsigned long g = (e % p) / r;
    unsigned long h = (u * g) + w;
    day = ((h % s) / u) + 1;
    month = (((h / s) + m) % n) + 1;
    year = (e / p) - y + ((n + m - month) / n);
}
