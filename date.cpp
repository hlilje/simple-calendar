#include "date.hpp"


lab2::Date::Date(const Date & other) : _offset(other._offset) {};

lab2::Date::Date(const Date * const other) : _offset(other->_offset) {};

lab2::Date & lab2::Date::operator=(const Date & rhs) {
    _offset = rhs._offset;
    return *this;
};

long lab2::Date::operator-(const Date & rhs) const {
    return _offset - rhs._offset;
}

bool lab2::Date::operator==(const Date & rhs) const {
    return _offset == rhs._offset;
}

bool lab2::Date::operator!=(const Date & rhs) const {
    return _offset != rhs._offset;
}

bool lab2::Date::operator<(const Date & rhs) const {
    return _offset < rhs._offset;
}

bool lab2::Date::operator<=(const Date & rhs) const {
    return _offset <= rhs._offset;
}

bool lab2::Date::operator>(const Date & rhs) const {
    return _offset > rhs._offset;
}

bool lab2::Date::operator>=(const Date & rhs) const {
    return _offset >= rhs._offset;
}

std::ostream & lab2::operator<<(std::ostream & os, const Date & rhs) {
    os << rhs.year() << "-";
    if(rhs.month() < 10) os << "0";
    os << rhs.month() << "-";
    if(rhs.day() < 10) os << "0";
    os << rhs.day();
    return os;
}
