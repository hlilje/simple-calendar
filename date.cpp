#include "date.hpp"


lab2::Date::Date(const Date& other) : _offset(other._offset) {};

long lab2::Date::operator-(const Date& rhs) {
    return _offset - rhs._offset;
}

bool lab2::Date::operator==(const Date& rhs) {
    return _offset == rhs._offset;
}

bool lab2::Date::operator!=(const Date& rhs) {
    return _offset != rhs._offset;
}

bool lab2::Date::operator<(const Date& rhs) {
    return _offset < rhs._offset;
}

bool lab2::Date::operator<=(const Date& rhs) {
    return _offset <= rhs._offset;
}

bool lab2::Date::operator>(const Date& rhs) {
    return _offset > rhs._offset;
}

bool lab2::Date::operator>=(const Date& rhs) {
    return _offset >= rhs._offset;
}
