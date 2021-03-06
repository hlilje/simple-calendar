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
    if(!is_valid_date())
        throw std::invalid_argument("invalid date");
    date_to_jdn(); // sets _offset
}

lab2::Gregorian::Gregorian(const Date & other) : WesternDate(other) {
    jdn_to_date();
}

lab2::Gregorian::Gregorian(const Date * const other) : WesternDate(other) {
    jdn_to_date();
}

bool lab2::Gregorian::is_leap_year() const {
    return (_year % 4 == 0) && ((_year % 100) != 0 || (_year % 400) == 0);
}

void lab2::Gregorian::jdn_to_date() {
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
    unsigned long B = 274277;
    unsigned int C = 38;

    unsigned long f = jdn + j + (((((4 * jdn) + B) / 146097) * 3) / 4) - C;
    unsigned long e = (r * f) + v;
    unsigned long g = (e % p) / r;
    unsigned long h = (u * g) + w;
    _day = ((h % s) / u) + 1;
    _month = (((h / s) + m) % n) + 1;
    _year = (e / p) - y + ((n + m - _month) / n);
}

void lab2::Gregorian::date_to_jdn() {
    _offset = gregorian_date_to_jdn(_year, _month, _day);
}

lab2::Gregorian & lab2::Gregorian::operator=(const Date & rhs) {
    Date::operator=(rhs);
    jdn_to_date();

    return *this;
}

lab2::Gregorian lab2::Gregorian::operator++(int) {
    Gregorian tmp = *this;
    _offset++;
    jdn_to_date();
    return tmp;
}

lab2::Gregorian lab2::Gregorian::operator--(int) {
    Gregorian tmp = *this;
    _offset--;
    jdn_to_date();
    return tmp;
}

lab2::Gregorian & lab2::Gregorian::operator++() {
    _offset++;
    jdn_to_date();
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator--() {
    _offset--;
    jdn_to_date();
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator+=(const long rhs) {
    _offset += rhs;
    jdn_to_date();
    return *this;
}

lab2::Gregorian & lab2::Gregorian::operator-=(const long rhs) {
    _offset -= rhs;
    jdn_to_date();
    return *this;
}

void lab2::Gregorian::add_year(int n) {
    _year += n;

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}

void lab2::Gregorian::add_month(int n) {
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

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}
