#pragma once

#include "kattistime.h"
#include "western_date.hpp"


namespace lab2 {
    class Gregorian : public WesternDate {
        private:
            // Return true if the current year is a leap year.
            bool is_leap_year() const override;
            // Convert Julian Day Number to Gregorian Date
            void jdn_to_date() override;
            // Convert given Gregorian date to Julian Day Number
            void date_to_jdn() override;

        public:
            Gregorian();
            Gregorian(const Date & other);
            Gregorian(const Date * const other);
            Gregorian(const unsigned int year, const unsigned int month,
                      const unsigned int day);
            ~Gregorian() override {};

            Gregorian & operator=(const Date & rhs) override;
            Gregorian operator++(int);
            Gregorian operator--(int);

            Gregorian & operator++() override;
            Gregorian & operator--() override;
            Gregorian & operator+=(const long rhs) override;
            Gregorian & operator-=(const long rhs) override;

            void add_year(int n = 1) override;
            void add_month(int n = 1) override;
    };
}
