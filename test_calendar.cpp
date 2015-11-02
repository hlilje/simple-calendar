#include "gregorian.hpp"
#include "julian.hpp"
#include <cxxtest/TestSuite.h>

using namespace lab2;


class CalendarSuite : public CxxTest::TestSuite {
    public:
        void test_initialisation() {
            // Init kattistime
            time_t tp;
            time(&tp);
            set_k_time(tp);

            const struct tm *t = gmtime(&tp);
            const long year  = t->tm_year + 1900;
            const long month = t->tm_mon + 1;
            const long day   = t->tm_mday;

            Julian j;
            Gregorian g;

            TS_ASSERT_EQUALS(g.year(), year);
            TS_ASSERT_EQUALS(g.month(), month);
            TS_ASSERT_EQUALS(g.day(), day);
        }
};
