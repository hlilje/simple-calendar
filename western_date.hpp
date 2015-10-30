#pragma once

#include "date.hpp"


namespace lab2 {
    class WesternDate : public Date {
        private:
            unsigned int _year;
            unsigned int _month;
            unsigned int _day;
        public:
            ~WesternDate() override;

            WesternDate& operator++() override;
            WesternDate& operator--() override;
            WesternDate& operator+=(const Date& rhs) override;
            WesternDate& operator-=(const Date& rhs) override;

            int year() override;
            unsigned int month() override;
            unsigned int day() override;
            unsigned int days_per_week() override;
    };
}
