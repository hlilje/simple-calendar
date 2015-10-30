#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        private:
        public:
            Date();
            Date(const Date & d);
            virtual ~Date();

            virtual Date& operator++();
            virtual Date operator++(int);
            virtual Date& operator--();
            virtual Date operator--(int);
            virtual Date& operator-(const Date& rhs);
            virtual Date& operator=(const Date& rhs);
            virtual Date& operator+=(const Date& rhs);
            virtual Date& operator-=(const Date& rhs);
            virtual bool operator<(const Date& rhs); // TODO: More?

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

            friend std::ostream& operator<<(std::ostream& os, const Date& d);
    };
}
