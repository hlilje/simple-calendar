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

unsigned int lab2::WesternDate::days_per_week() {
    return 7;
}
