#include "western_date.hpp"


lab2::WesternDate::WesternDate(const Date & other) :
    Date(other) {}

lab2::WesternDate::WesternDate(const Date * const other) :
    Date(other) {}

lab2::WesternDate::WesternDate(const unsigned int year,
                               const unsigned int month,
                               const unsigned int day) :
    _year(year), _month(month), _day(day) {}

bool lab2::WesternDate::is_valid_date() const {
    if(_month > 12 || _month < 1 || _day < 1 || _day > days_this_month())
        return false;
    return true;
}

long lab2::WesternDate::gregorian_date_to_jdn(const unsigned int year,
                                              const unsigned int month,
                                              const unsigned int day) const {
    const unsigned int a = (14 - month) / 12;
    const unsigned int y = year + 4800 - a;
    const unsigned int m = month + (12 * a) - 3;

    return day + ((153 * m + 2) / 5) + (365 * y) + (y / 4) - (y / 100) +
           (y / 400) - 32045;
}

int lab2::WesternDate::year() const {
    return _year;
}

unsigned int lab2::WesternDate::month() const {
    return _month;
}

unsigned int lab2::WesternDate::day() const {
    return _day;
}

unsigned int lab2::WesternDate::week_day() const {
    return (_offset  % 7) + 1;
}

unsigned int lab2::WesternDate::days_per_week() const {
    return 7;
}

std::string lab2::WesternDate::week_day_name() const {
    switch (week_day()) {
        case 1:
            return "monday";
        case 2:
            return "tuesday";
        case 3:
            return "wednesday";
        case 4:
            return "thursday";
        case 5:
            return "friday";
        case 6:
            return "saturday";
        case 7:
            return "sunday";
        default:
            return "";
    }
}

std::string lab2::WesternDate::month_name() const {
    switch (_month) {
        case 1:
            return "january";
        case 2:
            return "february";
        case 3:
            return "march";
        case 4:
            return "april";
        case 5:
            return "may";
        case 6:
            return "june";
        case 7:
            return "july";
        case 8:
            return "august";
        case 9:
            return "september";
        case 10:
            return "october";
        case 11:
            return "november";
        case 12:
            return "december";
        default:
            return "";
    }
}

unsigned int lab2::WesternDate::days_this_month() const {
    switch(_month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
        default:
            return is_leap_year() ? 29 : 28;
    }
}

long lab2::WesternDate::mod_julian_day() const {
    // _offset is not real JDN, so we subtract extra 0.5
    return _offset - 2400001;
}

unsigned int lab2::WesternDate::months_per_year() const {
    return 12;
}

void lab2::WesternDate::add_year(int n) {
    _year += n;

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}

void lab2::WesternDate::add_month(int n) {
    const int years = n / 12;
    const int months = n % 12;
    const int new_month = _month + months;

    _year += years;

    if (new_month > 12) {
        _month = new_month - 12;
        ++_year;
    } else {
        _month += months;
    }

    const unsigned int dtm = days_this_month();
    if (_day > dtm) _day = dtm;

    date_to_jdn();
}
