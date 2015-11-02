#include "julian.hpp"


lab2::Julian::Julian() {
    time_t time; k_time(&time); // Init time
}

lab2::Julian::Julian(const Julian& other) {
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

unsigned int lab2::Julian::days_this_month() {
    return 0;
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

void lab2::Gregorian::jdn_to_julian_date(const long jdn,
                                         unsigned int & year,
                                         unsigned int & month,
                                         unsigned int & day) {
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

    unsigned int f = jdn + j;
    unsigned int e = (r * f) + v;
    unsigned int g = (e % p) / r;
    unsigned int h = (u * g) + w;
    day = ((h % s) / u) + 1;
    month = (((h / s) + m) % n) + 1;
    year = (e / p) - y + ((n + m - month) / n);
}
