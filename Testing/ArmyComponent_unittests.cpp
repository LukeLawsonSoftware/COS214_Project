// In these files you write the actual code to do the testing
#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/AirUnit.h"
#include "../Code/AirVehicle.h"
#include "../Code/LandUnit.h"
#include "../Code/LandVehicle.h"
#include "../Code/SeaUnit.h"
#include "../Code/SeaVehicle.h"
#include "../Code/Battalion.h"

namespace
{
    // Check for stats that should return zero
    TEST(AirUnitCalculations, ZeroStats)
    {
        AirUnit *u = new AirUnit(3);
        ASSERT_EQ(0, u->calculateLandDefense());
        ASSERT_EQ(0, u->calculateSeaDefense());
        ASSERT_EQ(0, u->calculateSeaOffense());
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(AirUnitCalculations, NonZeroStats)
    {
        AirUnit *u = new AirUnit(3);
        ASSERT_GT(u->calculateAirDefense(), 0);
        ASSERT_GT(u->calculateAirOffense(), 0);
        ASSERT_GT(u->calculateLandOffense(), 0);
        delete u;
    }

    // Check for stats that should return zero
    TEST(AirVehicleCalculations, ZeroStats)
    {
        AirVehicle *u = new AirVehicle(3);
        ASSERT_EQ(0, u->calculateLandDefense());
        ASSERT_EQ(0, u->calculateSeaDefense());
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(AirVehicleCalculations, NonZeroStats)
    {
        AirVehicle *u = new AirVehicle(3);
        ASSERT_GT(u->calculateAirDefense(), 0);
        ASSERT_GT(u->calculateAirOffense(), 0);
        ASSERT_GT(u->calculateLandOffense(), 0);
        ASSERT_GT(u->calculateSeaOffense(), 0);
        delete u;
    }

    // Check for stats that should return zero
    TEST(LandUnitCalculations, ZeroStats)
    {
        LandUnit *u = new LandUnit(3);
        ASSERT_EQ(u->calculateAirDefense(), 0);
        ASSERT_EQ(u->calculateAirOffense(), 0);
        ASSERT_EQ(u->calculateSeaDefense(), 0);
        ASSERT_EQ(u->calculateSeaOffense(), 0);
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(LandUnitCalculations, NonZeroStats)
    {
        LandUnit *u = new LandUnit(3);
        ASSERT_GT(u->calculateLandDefense(), 0);
        ASSERT_GT(u->calculateLandOffense(), 0);
        delete u;
    }

    // Check for stats that should return zero
    TEST(LandVehicleCalculations, ZeroStats)
    {
        LandVehicle *u = new LandVehicle(3);
        ASSERT_EQ(u->calculateAirOffense(), 0);
        ASSERT_EQ(u->calculateSeaDefense(), 0);
        ASSERT_EQ(u->calculateSeaOffense(), 0);
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(LandVehicleCalculations, NonZeroStats)
    {
        LandVehicle *u = new LandVehicle(3);
        ASSERT_GT(u->calculateLandDefense(), 0);
        ASSERT_GT(u->calculateLandOffense(), 0);
        ASSERT_GT(u->calculateAirDefense(), 0);
        delete u;
    }

    // Check for stats that should return zero
    TEST(SeaUnitCalculations, ZeroStats)
    {
        SeaUnit *u = new SeaUnit(3);
        ASSERT_EQ(u->calculateAirDefense(), 0);
        ASSERT_EQ(u->calculateAirOffense(), 0);
        ASSERT_EQ(u->calculateLandDefense(), 0);
        ASSERT_EQ(u->calculateLandOffense(), 0);
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(SeaUnitCalculations, NonZeroStats)
    {
        SeaUnit *u = new SeaUnit(3);
        ASSERT_GT(u->calculateSeaDefense(), 0);
        ASSERT_GT(u->calculateSeaOffense(), 0);
        delete u;
    }

    // Check for stats that should return zero
    TEST(SeaVehicleCalculations, ZeroStats)
    {
        SeaVehicle *u = new SeaVehicle(3);
        ASSERT_EQ(u->calculateAirDefense(), 0);
        ASSERT_EQ(u->calculateLandDefense(), 0);
        ASSERT_EQ(u->calculateLandOffense(), 0);
        delete u;
    }

    // Check for stats that should return a positive value
    TEST(SeaVehicleCalculations, NonZeroStats)
    {
        SeaVehicle *u = new SeaVehicle(3);
        ASSERT_GT(u->calculateSeaDefense(), 0);
        ASSERT_GT(u->calculateSeaOffense(), 0);
        ASSERT_GT(u->calculateAirOffense(), 0);
        delete u;
    }

    // Testing the addMember functions
    TEST(AddingMemberToAirUnit, NegativeCase)
    {
        try
        {
            AirUnit *u1 = new AirUnit(3);
            AirUnit *u2 = new AirUnit(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Soldier object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    // Testing the addMember functions
    TEST(AddingMemberToLandUnit, NegativeCase)
    {
        try
        {
            LandUnit *u1 = new LandUnit(3);
            LandUnit *u2 = new LandUnit(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Soldier object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    // Testing the addMember functions
    TEST(AddingMemberToSeaUnit, NegativeCase)
    {
        try
        {
            SeaUnit *u1 = new SeaUnit(3);
            SeaUnit *u2 = new SeaUnit(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Soldier object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    // Testing the addMember functions
    TEST(AddingMemberToAirVehicle, NegativeCase)
    {
        try
        {
            AirVehicle *u1 = new AirVehicle(3);
            AirVehicle *u2 = new AirVehicle(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Vehicle object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    // Testing the addMember functions
    TEST(AddingMemberToLandVehicle, NegativeCase)
    {
        try
        {
            LandVehicle *u1 = new LandVehicle(3);
            LandVehicle *u2 = new LandVehicle(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Vehicle object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    // Testing the addMember functions
    TEST(AddingMemberToSeaVehicle, NegativeCase)
    {
        try
        {
            SeaVehicle *u1 = new SeaVehicle(3);
            SeaVehicle *u2 = new SeaVehicle(3);
            u1->addMember(u2);
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot add ArmyComponent to a Vehicle object"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(AddingMemberToBattalion, PositiveCase)
    {
        try
        {
            Battalion *b = new Battalion();
            b->addMember(new SeaUnit(3));
            b->addMember(new LandVehicle(3));
        }
        catch (...)
        {
            FAIL();
        }
    }

}