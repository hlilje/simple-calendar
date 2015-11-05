#include "julian.hpp"


lab2::Julian::Julian() {
    time_t time; k_time(&time); // Init time
    const struct tm *t = gmtime(&time);
    unsigned int year  = t->tm_year + 1900;
    unsigned int month = t->tm_mon + 1;
    unsigned int day   = t->tm_mday;
    const long jdn     = gregorian_date_to_jdn(year, month, day);

    _offset = jdn;
    jdn_to_date(); // sets _year, _month, _day
}

lab2::Julian::Julian(const unsigned int year,
                     const unsigned int month,
                     const unsigned int day) :
    WesternDate(year, month, day) {
    if(!is_valid_date())
        throw std::invalid_argument("invalid date");
    date_to_jdn(); // sets _offset
}

lab2::Julian::Julian(const Date & other) : WesternDate(other) {
    jdn_to_date();
}

lab2::Julian::Julian(const Date * const other) : WesternDate(other) {
    jdn_to_date();
}

bool lab2::Julian::is_leap_year() const {
    return _year % 4 == 0;
}

void lab2::Julian::jdn_to_date() {
    long jdn = _offset;
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
    _day = ((h % s) / u) + 1;
    _month = (((h / s) + m) % n) + 1;
    _year = (e / p) - y + ((n + m - _month) / n);
}

void lab2::Julian::date_to_jdn() {
    const unsigned int a = (14 - _month) / 12;
    const unsigned int y = _year + 4800 - a;
    const unsigned int m = _month + (12 * a) - 3;

    _offset = _day + ((153 * m + 2) / 5) + (365 * y) + (y / 4) - 32083;
}

lab2::Julian & lab2::Julian::operator=(const Julian & rhs) {
    _offset = rhs._offset;
    _year = rhs._year;
    _month = rhs._month;
    _day = rhs._day;

    return *this;
}

lab2::Julian lab2::Julian::operator++(int) {
    Julian tmp = *this;
    _offset++;
    jdn_to_date();
    return tmp;
}

lab2::Julian lab2::Julian::operator--(int) {
    Julian tmp = *this;
    _offset--;
    jdn_to_date();
    return tmp;
}

lab2::Julian & lab2::Julian::operator++() {
    _offset++;
    jdn_to_date();
    return *this;
}

lab2::Julian & lab2::Julian::operator--() {
    _offset--;
    jdn_to_date();
    return *this;
}

lab2::Julian & lab2::Julian::operator+=(const long rhs) {
    _offset += rhs;
    jdn_to_date();
    return *this;
}

lab2::Julian & lab2::Julian::operator-=(const long rhs) {
    _offset -= rhs;
    jdn_to_date();
    return *this;
}

void lab2::Julian::add_year(int n) {
    _year += n;

    // Year 0 is -1 in Julian
    if ((_year == 0) && (n > 0))
        _year = 1;
    else if ((_year == 0) && (n < 0))
        _year = -1;

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}

void lab2::Julian::add_month(int n) {
    const int years = n / 12;
    const int months = n % 12;
    const int new_month = _month + months;

    _year += years;

    if (new_month > 12) {
        _month = new_month - 12;
        ++_year;
    } else if (new_month < 1) {
        _month = new_month + 12;
        --_year;
    } else {
        _month += months;
    }

    // Year 0 is -1 in Julian
    if ((_year == 0) && (n > 0))
        _year = 1;
    else if ((_year == 0) && (n < 0))
        _year = -1;

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}
