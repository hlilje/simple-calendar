#pragma once

#include <iostream>


namespace lab2 {
    class Date {
        protected:
            long _offset; // Starting at Julian Date 0

            Date() = default;
            Date(const Date & other);

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

            /* friend std::ostream& operator<<(std::ostream& os, const Date& d); */
    };
}
