#pragma once

#include "kattistime.h"
#include "western_date.hpp"


namespace lab2 {
    class Gregorian : public WesternDate {
        private:
            // Return true if the current year is a leap year.
            bool is_leap_year() const override;
            // Convert Julian Day Number to Julian Date
            void jdn_to_gregorian_date(const long jdn,
                                       unsigned int & year,
                                       unsigned int & month,
                                       unsigned int & day) const;

        public:
            Gregorian();
            Gregorian(const Gregorian & other);
            Gregorian(const unsigned int year, const unsigned int month,
                      const unsigned int day);
            ~Gregorian() override {};

            Gregorian & operator=(const Gregorian & rhs);
            Gregorian & operator++(int);
            Gregorian & operator--(int);

            Gregorian & operator++() override;
            Gregorian & operator--() override;
            Gregorian & operator+=(const long rhs) override;
            Gregorian & operator-=(const long rhs) override;

            unsigned int days_this_month() const override;
    };
}
