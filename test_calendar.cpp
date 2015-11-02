#include "gregorian.hpp"
#include "julian.hpp"
#include <cxxtest/TestSuite.h>

using namespace lab2;


class CalendarSuite : public CxxTest::TestSuite {
    public:
        void test_initialisation() {
            time_t tp;
            time(&tp);
            set_k_time(tp);

            const struct tm *t = gmtime(&tp);
            const unsigned int g_year  = t->tm_year + 1900;
            const unsigned int g_month = t->tm_mon + 1;
            const unsigned int g_day   = t->tm_mday;

            time_t custom_time = 0;
            set_k_time(custom_time);

            const unsigned int j_year = 1969;
            const unsigned int j_month = 12;
            const unsigned int j_day = 19;

            Julian j;
            Gregorian g;

            TS_ASSERT_EQUALS(g.year(), g_year);
            TS_ASSERT_EQUALS(g.month(), g_month);
            TS_ASSERT_EQUALS(g.day(), g_day);

            TS_ASSERT_EQUALS(j.year(), j_year);
            TS_ASSERT_EQUALS(j.month(), j_month);
            TS_ASSERT_EQUALS(j.day(), j_day);
        }
};
