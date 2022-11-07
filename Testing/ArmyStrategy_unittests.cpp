#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/Defensive.h"
#include "../Code/Neutral.h"
#include "../Code/Offensive.h"
#include "../Code/BattleStatistics.h"
#include "../Code/Battalion.h"
#include "../Code/ArmyComponent.h"
#include "../Code/LandUnit.h"
#include "../Code/SeaUnit.h"
#include "../Code/AirUnit.h"
#include "../Code/Soldier.h"
namespace
{
    TEST(ApplyingStrategyNormalDefensive, NormalCase)
    {
        try
        {
            Battalion *army = new Battalion();
            LandUnit *u1 = new LandUnit(3);
            LandUnit *u2 = new LandUnit(3);
            SeaUnit *u3 = new SeaUnit(3);
            SeaUnit *u4 = new SeaUnit(3);
            BattleStatistics stats;

            army->addMember(u1);
            army->addMember(u2);
            army->addMember(u3);
            army->addMember(u4);

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Defensive *d = new Defensive();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete u1;
            delete u2;
            delete u3;
            delete u4;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyEmptyDefensive, EmptyCase)
    {
        try
        {
            Battalion *army = new Battalion();

            BattleStatistics stats;

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Defensive *d = new Defensive();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyNormalNeutral, NormalCase)
    {
        try
        {
            Battalion *army = new Battalion();
            LandUnit *u1 = new LandUnit(3);
            LandUnit *u2 = new LandUnit(3);
            SeaUnit *u3 = new SeaUnit(3);
            SeaUnit *u4 = new SeaUnit(3);
            BattleStatistics stats;

            army->addMember(u1);
            army->addMember(u2);
            army->addMember(u3);
            army->addMember(u4);

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Neutral *d = new Neutral();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete u1;
            delete u2;
            delete u3;
            delete u4;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyEmptyNeutral, EmptyCase)
    {
        try
        {
            Battalion *army = new Battalion();

            BattleStatistics stats;

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Neutral *d = new Neutral();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyNormalOffensive, NormalCase)
    {
        try
        {
            Battalion *army = new Battalion();
            LandUnit *u1 = new LandUnit(3);
            LandUnit *u2 = new LandUnit(3);
            SeaUnit *u3 = new SeaUnit(3);
            SeaUnit *u4 = new SeaUnit(3);
            BattleStatistics stats;

            army->addMember(u1);
            army->addMember(u2);
            army->addMember(u3);
            army->addMember(u4);

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Offensive *d = new Offensive();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete u1;
            delete u2;
            delete u3;
            delete u4;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyEmptyOffensive, EmptyCase)
    {
        try
        {
            Battalion *army = new Battalion();

            BattleStatistics stats;

            stats.setLandAttack(army->calculateLandOffense());
            stats.setLandDefence(army->calculateLandDefense());
            stats.setSeaAttack(army->calculateSeaOffense());
            stats.setSeaDefence(army->calculateSeaDefense());

            Offensive *d = new Offensive();
            d->applyStrategyBonus(stats, army, "Country_Name");
            delete d;
            delete army;
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyNullOffensive, NullArmyCase)
    {
        try
        {

            BattleStatistics stats;

            Offensive *d = new Offensive();
            d->applyStrategyBonus(stats, NULL, "Country_Name");
            FAIL();
            delete d;
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot accept an ArmyComponent of Null"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyNullNeutral, NullArmyCase)
    {
        try
        {

            BattleStatistics stats;

            Neutral *d = new Neutral();
            d->applyStrategyBonus(stats, NULL, "Country_Name");
            FAIL();
            delete d;
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot accept an ArmyComponent of Null"));
        }
        catch (...)
        {
            FAIL();
        }
    }

    TEST(ApplyingStrategyNullDefensive, NullArmyCase)
    {
        try
        {

            BattleStatistics stats;

            Defensive *d = new Defensive();
            d->applyStrategyBonus(stats, NULL, "Country_Name");
            FAIL();
            delete d;
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot accept an ArmyComponent of Null"));
        }
        catch (...)
        {
            FAIL();
        }
    }

}