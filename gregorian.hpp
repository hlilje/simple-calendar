#pragma once

#include "western_date.hpp"


namespace lab2 {
    class Gregorian : public WesternDate {
        private:
        public:
            ~Gregorian() override;

            Gregorian& operator++() override;
            Gregorian& operator--() override;
            Gregorian& operator+=(const long rhs) override;
            Gregorian& operator-=(const long rhs) override;

            unsigned int week_day() override;
            unsigned int days_this_month() override;
            std::string week_day_name() override;
            std::string month_name() override;
            void add_year(int n = 1) override;
            void add_month(int n = 1) override;
            int mod_julian_day() override;
    };
}
