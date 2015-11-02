#pragma once

#include "kattistime.h"
#include "western_date.hpp"


namespace lab2 {
    class Gregorian : public WesternDate {
        private:
            // Return true if the current year is a leap year.
            bool is_leap_year();

        public:
            Gregorian();
            Gregorian(const Gregorian& other);
            ~Gregorian() override {};

            Gregorian& operator=(const Gregorian& rhs);
            Gregorian& operator++(int);
            Gregorian& operator--(int);

            Gregorian& operator++() override;
            Gregorian& operator--() override;
            Gregorian& operator+=(const long rhs) override;
            Gregorian& operator-=(const long rhs) override;

            unsigned int days_this_month() override;
            void add_year(int n = 1) override;
            void add_month(int n = 1) override;
            int mod_julian_day() override;
    };
}
