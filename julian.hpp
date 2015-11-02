#pragma once

#include "kattistime.h"
#include "western_date.hpp"


namespace lab2 {
    class Julian : public WesternDate {
        private:
            // Return true if the current year is a leap year.
            bool is_leap_year() const;
            // Convert Julian Day Number to Julian Date
            void jdn_to_julian_date(const long jdn,
                                    unsigned int & year,
                                    unsigned int & month,
                                    unsigned int & day) const;
            // Convert given Julian date to Julian Day Number
            long julian_date_to_jdn(const unsigned int year,
                                       const unsigned int month,
                                       const unsigned int day) const;

        public:
            Julian();
            Julian(const Julian & other);
            Julian(const unsigned int year, const unsigned int month,
                   const unsigned int day);
            ~Julian() override {};

            Julian & operator=(const Julian& rhs);
            Julian & operator++(int);
            Julian & operator--(int);

            Julian & operator++() override;
            Julian & operator--() override;
            Julian & operator+=(const long rhs) override;
            Julian & operator-=(const long rhs) override;

            unsigned int days_this_month() const override;
            void add_year(int n = 1) override;
            void add_month(int n = 1) override;
    };
}
