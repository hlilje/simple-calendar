#include "calendar.hpp"


template <typename DateType>
lab2::Calendar<DateType>::Calendar() {
}

template <typename DateType>
lab2::Calendar<DateType>::Calendar(const Calendar<DateType> & other) {

}

template <typename DateType> lab2::Calendar<DateType> &
lab2::Calendar<DateType>::operator=(const Calendar<DateType> & rhs) {

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
