#ifndef TEMPLATE_CALENDAR_CPP
#define TEMPLATE_CALENDAR_CPP

#include "calendar.hpp"


template <typename DateType>
lab2::Calendar<DateType>::Calendar() {
    time_t time; k_time(&time); // Init time
    const struct tm *t       = gmtime(&time);
    const unsigned int year  = t->tm_year + 1900;
    const unsigned int month = t->tm_mon + 1;
    const unsigned int day   = t->tm_mday;

    _date = DateType(year, month, day);
}

template <typename DateType>
lab2::Calendar<DateType>::Calendar(const Calendar<DateType> & other) :
    _date(other._date), _events(other._events) {}

template <typename DateType> lab2::Calendar<DateType> &
lab2::Calendar<DateType>::operator=(const Calendar<DateType> & rhs) {
    _date = rhs._date;
    _events = rhs._events;

    return *this;
}

template <typename DateType>
bool lab2::Calendar<DateType>::set_date(
        const unsigned int year,
        const unsigned int month,
        const unsigned int day) {
    DateType date;
    try {
        date = DateType(year, month, day);
    } catch (std::invalid_argument e) {
        return false;
    }
    return true;
}

template <typename DateType>
bool lab2::Calendar<DateType>::add_event(
        const std::string text,
        const unsigned int day,
        const unsigned int month,
        const unsigned int year) {
    DateType date;
    unsigned int set_year = year;
    unsigned int set_month = month;
    unsigned int set_day = day;
    try {
        if (year == UNSET) set_year = _date.year();
        if (month == UNSET) set_month = _date.month();
        if (day == UNSET) set_day = _date.day();
        date = DateType(set_year, set_month, set_day);

        if (_events.count(date) > 0) {
            for (const auto& t : _events[date]) {
                if (t == text) return false;
            }
        }

        _events[date].insert(text);

        return true;
    } catch (std::invalid_argument e) {
        return false;
    }
}

template <typename DateType>
bool lab2::Calendar<DateType>::remove_event(
        const std::string text,
        const unsigned int day,
        const unsigned int month,
        const unsigned int year) {
    DateType date;
    unsigned int set_year = year;
    unsigned int set_month = month;
    unsigned int set_day = day;
    try {
        if (year == UNSET) set_year = _date.year();
        if (month == UNSET) set_month = _date.month();
        if (day == UNSET) set_day = _date.day();
        date = DateType(set_year, set_month, set_day);

        if (_events.count(date) > 0)
            return _events[date].erase(text) > 0;
        else
            return false;
    } catch (std::invalid_argument e) {
        return false;
    }
}

template <typename DateType>
std::ostream & lab2::operator<<(std::ostream & os, const Calendar<DateType> & rhs) {
    os << "BEGIN:VCALENDAR" << std::endl << "VERSION:2.0" << std::endl;
    for(auto it = rhs._events.lower_bound(rhs._date); it != rhs._events.end(); ++it) {
        for(const std::string & desc : it->second) {
            os << "BEGIN:VEVENT" << std::endl;
            os << "DTSTART:" << it->first.year();
            if(it->first.month() < 10) os << "0";
            os << it->first.month();
            if(it->first.day() < 10) os << "0";
            os << it->first.day();
            // time component shouldn't be needed according to spec
            os << "T000000Z";
            os << std::endl;
            os << "SUMMARY:" << desc << std::endl;
            os << "END:VEVENT" << std::endl;
        }
    }
    os << "END:VCALENDAR" << std::endl;
    return os;
}

#endif
