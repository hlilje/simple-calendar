#include "western_date.hpp"


lab2::WesternDate& lab2::WesternDate::operator++() {
    return *this;
}

lab2::WesternDate& lab2::WesternDate::operator--() {
    return *this;
}

lab2::WesternDate& lab2::WesternDate::operator+=(const Date& rhs) {
    return *this;
}

lab2::WesternDate& lab2::WesternDate::operator-=(const Date& rhs) {
    return *this;
}

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
