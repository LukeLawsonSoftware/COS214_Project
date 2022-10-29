// In these files you write the actual code to do the testing
#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/AirUnit.h"

namespace
{

    // Testing that necessary functions return 0
    TEST(StatsCalculations, ZeroStats)
    {
        AirUnit *u = new AirUnit(3);
        ASSERT_EQ(0, u->calculateLandDefense());
        ASSERT_EQ(0, u->calculateSeaDefense());
        ASSERT_EQ(0, u->calculateSeaOffense());
    }

    // Testing that other calculations return appropriate value
    TEST(StatsCalculations, NonZeroStats)
    {
        AirUnit *u = new AirUnit(3);
        ASSERT_GT(u->calculateAirDefense(), 0);
        ASSERT_GT(u->calculateAirOffense(), 0);
        ASSERT_GT(u->calculateLandOffense(), 0);
    }

}