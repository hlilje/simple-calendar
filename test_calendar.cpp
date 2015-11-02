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

            Julian j;
            Gregorian g;
        }
};
