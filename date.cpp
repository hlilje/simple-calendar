#include "date.hpp"


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
