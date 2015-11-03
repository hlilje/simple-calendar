#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        protected:
            long _offset; // Starting at Julian Date 0

            Date() = default;
            Date(const Date & other);
            Date(const Date * const other);

        public:
            virtual ~Date() {};

            virtual long operator-(const Date & rhs);

            virtual Date & operator++() = 0;
            virtual Date & operator--() = 0;
            virtual Date & operator+=(const long rhs) = 0;
            virtual Date & operator-=(const long rhs) = 0;

            virtual bool operator==(const Date & rhs);
            virtual bool operator!=(const Date & rhs);
            virtual bool operator<(const Date & rhs);
            virtual bool operator<=(const Date & rhs);
            virtual bool operator>(const Date & rhs);
            virtual bool operator>=(const Date & rhs);

            virtual int year() const = 0;
            virtual unsigned int month() const = 0;
            virtual unsigned int day() const = 0;
            virtual unsigned int week_day() const = 0;
            virtual unsigned int days_per_week() const = 0;
            virtual std::string week_day_name() const = 0;
            virtual std::string month_name() const = 0;
            virtual long mod_julian_day() const = 0;
            virtual void add_year(int n = 1) = 0;
            virtual void add_month(int n = 1) = 0;
            virtual unsigned int days_this_month() const = 0;
            virtual unsigned int months_per_year() const = 0;
    };
    std::ostream & operator<<(std::ostream & os, const Date & rhs);
}
