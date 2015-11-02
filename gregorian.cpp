#include "gregorian.hpp"


lab2::Gregorian::Gregorian() {
    time_t time; k_time(&time); // Init time
    const struct tm *t = gmtime(&time);
    _year  = t->tm_year + 1900;
    _month = t->tm_mon + 1;
    _day   = t->tm_mday;

    _offset = gregorian_date_to_jdn(_year, _month, _day);
}

lab2::Gregorian::Gregorian(const unsigned int year,
                           const unsigned int month,
                           const unsigned int day) :
    WesternDate(year, month, day) {
    _offset = gregorian_date_to_jdn(_year, _month, _day);
}

lab2::Gregorian::Gregorian(const Gregorian & other) : WesternDate(other) {}

lab2::Gregorian & lab2::Gregorian::operator=(const Gregorian & rhs) {
    _offset = rhs._offset;
    _year = rhs._year;
    _month = rhs._month;
    _day = rhs._day;

    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator++(int) {
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator--(int) {
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator++() {
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator--() {
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator+=(const long rhs) {
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator-=(const long rhs) {
    return *this;
}

unsigned int lab2::Gregorian::days_this_month() const {
    return 0;
}

void lab2::Gregorian::add_year(int n) {
}

void lab2::Gregorian::add_month(int n) {
}

bool lab2::Gregorian::is_leap_year() const {
    return (_year % 4 == 0) && ((_year % 100) != 0 || (_year % 400) == 0);
}

void lab2::Gregorian::jdn_to_gregorian_date(const long jdn,
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
    unsigned int B = 274277;
    unsigned int C = 38;

    unsigned int f = jdn + j + (((((4 * jdn) + B) / 146097) * 3) / 4) - C;
    unsigned int e = (r * f) + v;
    unsigned int g = (e % p) / r;
    unsigned int h = (u * g) + w;
    day = ((h % s) / u) + 1;
    month = (((h / s) + m) % n) + 1;
    year = (e / p) - y + ((n + m - month) / n);
}
