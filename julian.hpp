#pragma once

#include "kattistime.h"
#include "western_date.hpp"


namespace lab2 {
    class Julian : public WesternDate {
        private:
            // Return true if the current year is a leap year.
            bool is_leap_year() const override;
            // Convert Julian Day Number to Julian Date
            void jdn_to_date() override;
            // Convert given Julian date to Julian Day Number
            void date_to_jdn() override;

        public:
            Julian();
            Julian(const Julian & other);
            Julian(const unsigned int year, const unsigned int month,
                   const unsigned int day);
            ~Julian() override {};

            Julian & operator=(const Julian& rhs);
            Julian operator++(int);
            Julian operator--(int);

            Julian & operator++() override;
            Julian & operator--() override;
            Julian & operator+=(const long rhs) override;
            Julian & operator-=(const long rhs) override;
    };
}
