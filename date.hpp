#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        private:
            long _offset;
        public:
            virtual ~Date() {};

            virtual long operator-(const Date& rhs);

            virtual Date& operator++() = 0;
            virtual Date& operator--() = 0;
            virtual Date& operator+=(const long rhs) = 0;
            virtual Date& operator-=(const long rhs) = 0;

            virtual bool operator==(const Date& rhs);
            virtual bool operator!=(const Date& rhs);
            virtual bool operator<(const Date& rhs);
            virtual bool operator<=(const Date& rhs);
            virtual bool operator>(const Date& rhs);
            virtual bool operator>=(const Date& rhs);

            /* friend std::ostream& operator<<(std::ostream& os, const Date& d); */
    };
}
