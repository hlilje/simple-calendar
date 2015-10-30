#pragma once

#include "date.hpp"


namespace lab2 {
    class WesternDate : public Date {
        private:
        public:
            ~WesternDate() override;

            WesternDate& operator++() override;
            WesternDate& operator--() override;
            WesternDate& operator+=(const Date& rhs) override;
            WesternDate& operator-=(const Date& rhs) override;

            unsigned int days_per_week() override;
    };
}
