#include "western_date.hpp"


lab2::WesternDate::WesternDate(const WesternDate & other) :
    Date(other), _year(other._year), _month(other._month), _day(other._day) {}

lab2::WesternDate::WesternDate(const unsigned int year,
                               const unsigned int month,
                               const unsigned int day) :
    _year(year), _month(month), _day(day) {}

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
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 7:
            return "Sunday";
        default:
            return "";
    }
}

std::string lab2::WesternDate::month_name() const {
    switch (_month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}

long lab2::WesternDate::mod_julian_day() const {
    // _offset is not real JDN, so we subtract extra 0.5
    return _offset - 2400001;
}
