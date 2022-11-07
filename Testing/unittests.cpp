#include "ArmyComponent_unittests.cpp" // include all the files that do testing
#include "Transport_unittests.cpp"
#include "ArmyBuilder_unittests.cpp"
#include "ArmyStrategy_unittests.cpp"
#include "SupplyProduct_unittests.cpp"
#include "EconomicState_unittests.cpp"
#include "WarTheatre_unittests.cpp"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}