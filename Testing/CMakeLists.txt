cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests unittests.cpp ArmyComponent_unittests.cpp ../Code/Battalion.cpp ../Code/AirUnit.cpp ../Code/AirVehicle.cpp ../Code/LandUnit.cpp ../Code/LandVehicle.cpp ../Code/SeaUnit.cpp ../Code/SeaVehicle.cpp ../Code/Soldier.cpp ../Code/Vehicle.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)