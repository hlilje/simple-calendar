#ifndef TEMPLATE_CALENDAR_HPP
#define TEMPLATE_CALENDAR_HPP

#include "kattistime.h"
#include <iostream>
#include <limits>
#include <map>
#include <unordered_set>

#define UNSET std::numeric_limits<unsigned int>::max()


namespace lab2 {
    template <typename DateType> class Calendar;
    template <typename DateType>
    std::ostream & operator<<(std::ostream & os, const Calendar<DateType> & rhs);

    template <typename DateType>
    class Calendar {
        private:
            DateType _date;
            std::map<DateType, std::unordered_set<std::string>> _events;

        public:
            Calendar();
            template <typename OtherDateType>
            Calendar(const Calendar<OtherDateType> & other);
            ~Calendar() {};

            template <typename OtherDateType>
            Calendar & operator=(const Calendar<OtherDateType> & rhs);

            bool set_date(const unsigned int year,
                          const unsigned int month,
                          const unsigned int day);
            bool add_event(const std::string text,
                           const unsigned int day = UNSET,
                           const unsigned int month = UNSET,
                           const unsigned int year = UNSET);
            bool remove_event(const std::string text,
                              const unsigned int day = UNSET,
                              const unsigned int month = UNSET,
                              const unsigned int year = UNSET);

            template <typename OtherDateType> friend class Calendar;
            //template <typename DateType>
            friend std::ostream & operator<< <>(std::ostream & os, const Calendar<DateType> & rhs);
    };
}

#include "calendar.cpp"
#endif
