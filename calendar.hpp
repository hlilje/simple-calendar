#include <iostream>
#include <limits>
#include <map>
#include <vector>

#define UNSET std::numeric_limits<unsigned int>::max()


namespace lab2 {
    template <typename DateType>
    class Calendar {
        private:
            std::map<DateType, std::vector<std::string>> _events;

        public:
            Calendar();
            Calendar(const Calendar& other);
            ~Calendar();

            bool set_date(const unsigned int year,
                          const unsigned int month,
                          const unsigned int day);

            bool dd_event(const std::string text,
                          const unsigned int year = UNSET,
                          const unsigned int month = UNSET,
                          const unsigned int day = UNSET);

            bool emove_event(const std::string text,
                             const unsigned int year = UNSET,
                             const unsigned int month = UNSET,
                             const unsigned int day = UNSET);
    };

    template <typename DateType>
    std::ostream & operator<<(std::ostream & os, const Calendar<DateType> & rhs);
}
