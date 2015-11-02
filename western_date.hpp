#pragma once

#include "date.hpp"
#include <stdexcept>


namespace lab2 {
    class WesternDate : public Date {
        protected:
            unsigned int _year;
            unsigned int _month;
            unsigned int _day;

            WesternDate() = default;
            WesternDate(const unsigned int year,
                        const unsigned int month,
                        const unsigned int day);
            WesternDate(const WesternDate & other);

            // Return true if the current year is a leap year.
            virtual bool is_leap_year() const = 0;
            // Return true if the date is valid
            bool is_valid_date() const;
            // Convert given Gregorian date to Julian Day Number.
            long gregorian_date_to_jdn(const unsigned int year,
                                       const unsigned int month,
                                       const unsigned int day) const;
            // Convert current date to Julian Day Number
            virtual void date_to_jdn() = 0;
            // Convert current Julian Day Number to date
            virtual void jdn_to_date() = 0;

        public:
            ~WesternDate() override {};

            int year() const;
            unsigned int month() const;
            unsigned int day() const;
            unsigned int week_day() const;
            unsigned int days_per_week() const;
            std::string week_day_name() const;
            std::string month_name() const;
            long mod_julian_day() const;
            void add_year(int n = 1);
            void add_month(int n = 1);
            unsigned int days_this_month() const;
    };
}
