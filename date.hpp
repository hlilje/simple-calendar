#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        private:
        public:
            Date();
            Date(const Date& d);
            virtual ~Date();

            virtual Date& operator++() = 0;
            virtual Date& operator--() = 0;
            virtual Date& operator-(const Date& rhs) = 0;
            virtual Date& operator=(const Date& rhs) = 0;
            virtual Date& operator+=(const Date& rhs) = 0;
            virtual Date& operator-=(const Date& rhs) = 0;
            virtual bool operator==(const Date& rhs) = 0;
            virtual bool operator!=(const Date& rhs) = 0;
            virtual bool operator<(const Date& rhs) = 0;
            virtual bool operator<=(const Date& rhs) = 0;
            virtual bool operator>(const Date& rhs) = 0;
            virtual bool operator>=(const Date& rhs) = 0;

            /* friend std::ostream& operator<<(std::ostream& os, const Date& d); */
    };
}
