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
            const int g_year  = t->tm_year + 1900;
            const int g_month = t->tm_mon + 1;
            const int g_day   = t->tm_mday;

            Gregorian g;

            TS_ASSERT_EQUALS((int) g.year(), g_year);
            TS_ASSERT_EQUALS((int) g.month(), g_month);
            TS_ASSERT_EQUALS((int) g.day(), g_day);

            tp = 0;
            set_k_time(tp);

            const int j_year = 1969;
            const int j_month = 12;
            const int j_day = 19;

            Julian j;

            TS_ASSERT_EQUALS((int) j.year(), j_year);
            TS_ASSERT_EQUALS((int) j.month(), j_month);
            TS_ASSERT_EQUALS((int) j.day(), j_day);
        }
};
