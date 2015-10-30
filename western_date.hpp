#pragma once

#include "date.hpp"


namespace lab2 {
    class WesternDate : public Date {
        private:
        public:
            WesternDate();
            WesternDate(const WesternDate& wd);
            virtual ~WesternDate();

            virtual WesternDate& operator++();
            virtual WesternDate& operator--();
            virtual WesternDate& operator-(const WesternDate& rhs);
            virtual WesternDate& operator=(const WesternDate& rhs);
            virtual WesternDate& operator+=(const WesternDate& rhs);
            virtual WesternDate& operator-=(const WesternDate& rhs);
            virtual bool operator==(const WesternDate& rhs);
            virtual bool operator!=(const WesternDate& rhs);
            virtual bool operator<(const WesternDate& rhs);
            virtual bool operator<=(const WesternDate& rhs);
            virtual bool operator>(const WesternDate& rhs);
            virtual bool operator>=(const WesternDate& rhs);

            virtual int year();
            virtual unsigned int month();
            virtual unsigned int day();
            virtual unsigned int week_day();
            virtual unsigned int days_per_week();
            virtual unsigned int days_this_month();
            virtual std::string week_day_name();
            virtual std::string month_name();
            virtual void add_year(int n = 1); // TODO: Unspecified return type
            virtual void add_month(int n = 1); // TODO: Unspecified return type
            virtual int mod_julian_day();
    };
}
