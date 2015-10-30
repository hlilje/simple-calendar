#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        private:
            long _offset;
        public:
            virtual ~Date();

            virtual long operator-(const Date& rhs);

            virtual Date& operator++() = 0;
            virtual Date& operator--() = 0;
            virtual Date& operator+=(const Date& rhs) = 0;
            virtual Date& operator-=(const Date& rhs) = 0;

            virtual bool operator==(const Date& rhs);
            virtual bool operator!=(const Date& rhs);
            virtual bool operator<(const Date& rhs);
            virtual bool operator<=(const Date& rhs);
            virtual bool operator>(const Date& rhs);
            virtual bool operator>=(const Date& rhs);

            virtual int year() = 0;
            virtual unsigned int month() = 0;
            virtual unsigned int day() = 0;
            virtual unsigned int week_day() = 0;
            virtual unsigned int days_per_week() = 0;
            virtual unsigned int days_this_month() = 0;
            virtual std::string week_day_name() = 0;
            virtual std::string month_name() = 0;
            virtual void add_year(int n = 1) = 0; // TODO: Unspecified return type
            virtual void add_month(int n = 1) = 0; // TODO: Unspecified return type
            virtual int mod_julian_day() = 0;

            /* friend std::ostream& operator<<(std::ostream& os, const Date& d); */
    };
}
