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
}

template <typename DateType>
bool lab2::Calendar<DateType>::set_date(
        const unsigned int year,
        const unsigned int month,
        const unsigned int day) {

}

template <typename DateType>
bool lab2::Calendar<DateType>::add_event(
        const std::string text,
        const unsigned int year,
        const unsigned int month,
        const unsigned int day) {

}

template <typename DateType>
bool lab2::Calendar<DateType>::remove_event(
        const std::string text,
        const unsigned int year,
        const unsigned int month,
        const unsigned int day) {

}
