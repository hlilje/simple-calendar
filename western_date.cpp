#include "western_date.hpp"


int lab2::WesternDate::year() {
    return _year;
}

unsigned int lab2::WesternDate::month() {
    return _month;
}

unsigned int lab2::WesternDate::day() {
    return _day;
}

unsigned int lab2::WesternDate::days_per_week() {
    return 7;
}
