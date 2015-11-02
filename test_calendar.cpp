#include "gregorian.hpp"
#include "julian.hpp"
#include <cxxtest/TestSuite.h>

using namespace lab2;


class CalendarSuite : public CxxTest::TestSuite {
    public:
        void test_default_init() {
            time_t tp;
            time(&tp);
            set_k_time(tp);

            const struct tm *t = gmtime(&tp);
            const int g_year   = t->tm_year + 1900;
            const int g_month  = t->tm_mon + 1;
            const int g_day    = t->tm_mday;

            Gregorian g;

            TS_ASSERT_EQUALS((int) g.year(), g_year);
            TS_ASSERT_EQUALS((int) g.month(), g_month);
            TS_ASSERT_EQUALS((int) g.day(), g_day);

            tp = 0;
            set_k_time(tp);

            Julian j;

            TS_ASSERT_EQUALS((int) j.year(), 1969);
            TS_ASSERT_EQUALS((int) j.month(), 12);
            TS_ASSERT_EQUALS((int) j.day(), 19);
        }

        void test_copy_init() {
            time_t tp;
            time(&tp);
            set_k_time(tp);

            Gregorian g1;
            Gregorian g2(g1);
            Gregorian g3 = g1;
            Gregorian g4; g4 = g1;

            TS_ASSERT_EQUALS(g1.year(), g2.year());
            TS_ASSERT_EQUALS(g1.month(), g2.month());
            TS_ASSERT_EQUALS(g1.day(), g2.day());

            TS_ASSERT_EQUALS(g1.year(), g3.year());
            TS_ASSERT_EQUALS(g1.month(), g3.month());
            TS_ASSERT_EQUALS(g1.day(), g3.day());

            TS_ASSERT_EQUALS(g1.year(), g4.year());
            TS_ASSERT_EQUALS(g1.month(), g4.month());
            TS_ASSERT_EQUALS(g1.day(), g4.day());

            Julian j1;
            Julian j2(j1);
            Julian j3 = j1;
            Julian j4; j4 = j1;

            TS_ASSERT_EQUALS(j1.year(), j2.year());
            TS_ASSERT_EQUALS(j1.month(), j2.month());
            TS_ASSERT_EQUALS(j1.day(), j2.day());

            TS_ASSERT_EQUALS(j1.year(), j3.year());
            TS_ASSERT_EQUALS(j1.month(), j3.month());
            TS_ASSERT_EQUALS(j1.day(), j3.day());

            TS_ASSERT_EQUALS(j1.year(), j4.year());
            TS_ASSERT_EQUALS(j1.month(), j4.month());
            TS_ASSERT_EQUALS(j1.day(), j4.day());
        }

        void test_date_constructors() {
            Gregorian g(1970, 1, 1);
            long mod_jul = 40587;
            TS_ASSERT_EQUALS(g.mod_julian_day(), mod_jul);
            TS_ASSERT_EQUALS(g.year(), 1970);
            TS_ASSERT_EQUALS(g.month(), 1);
            TS_ASSERT_EQUALS(g.day(), 1);
            

            Julian j(1969, 12, 19);
            TS_ASSERT_EQUALS(j.mod_julian_day(), mod_jul);
            TS_ASSERT_EQUALS(j.year(), 1969);
            TS_ASSERT_EQUALS(j.month(), 12);
            TS_ASSERT_EQUALS(j.day(), 19);

            Gregorian g2(1858, 11, 17);
            TS_ASSERT_EQUALS(g2.mod_julian_day(), 0);
        }

        void test_mod_julian_day() {
            Gregorian g1(2000, 10, 10);
            long mjd = 51827;
            TS_ASSERT_EQUALS(mjd, g1.mod_julian_day());

            Gregorian j1(2000, 10, 10);
            mjd = 51840;
            TS_ASSERT_EQUALS(mjd, j1.mod_julian_day());

            time_t t; t = 0; set_k_time(t);
            Gregorian g2;
            mjd = 40587;
            TS_ASSERT_EQUALS(mjd, g2.mod_julian_day());

            set_k_time(t);
            Julian j2;
            mjd = 40600;
            TS_ASSERT_EQUALS(mjd, j2.mod_julian_day());
        }
};
