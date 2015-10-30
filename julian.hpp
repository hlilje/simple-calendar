#pragma once

#include "western_date.hpp"


namespace lab2 {
    class Julian : public WesternDate {
        private:
        public:
            Julian();
            Julian(const Julian& other);
            ~Julian() override;

            Julian& operator=(const Julian& rhs);
            Julian& operator++(int);
            Julian& operator--(int);

            Julian& operator++() override;
            Julian& operator--() override;
            Julian& operator+=(const long rhs) override;
            Julian& operator-=(const long rhs) override;

            unsigned int week_day() override;
            unsigned int days_this_month() override;
            std::string week_day_name() override;
            std::string month_name() override;
            void add_year(int n = 1) override;
            void add_month(int n = 1) override;
            int mod_julian_day() override;
    };
}
