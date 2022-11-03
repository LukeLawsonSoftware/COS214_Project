cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 


# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests unittests.cpp WarPhase_unittests.cpp ../Code/Battalion.cpp ../Code/AirUnit.cpp ../Code/AirVehicle.cpp 
../Code/LandUnit.cpp ../Code/LandVehicle.cpp ../Code/SeaUnit.cpp 
../Code/SeaVehicle.cpp ../Code/Soldier.cpp ../Code/Vehicle.cpp 
../Code/Transporter.cpp ../Code/MedicTransporter.cpp ../Code/AmmoTransporter.cpp 
../Code/Country.cpp ../Code/Army.cpp ../Code/AirFactory.cpp ../Code/SeaFactory.cpp ../Code/LandFactory.cpp
../Code/MilitaryCommander.cpp ../Code/MedicalFactory.cpp ../Code/AmmoFactory.cpp ../Code/SupplyFactory.cpp
../Code/ArmyBuilder.cpp ../Code/ArmyDirector.cpp ../Code/War.cpp ../Code/AirTerrain ../Code/AmmoSupply.cpp
../Code/ArmyStrategy.cpp ../Code/AttackTransport.cpp ../Code/Average.cpp ../Code/BattleStatistics.cpp 
../Code/ChangeStrategy.cpp ../Code/Civilian.cpp ../Code/Command.cpp ../Code/Corresponder.cpp ../Code/Defensive.cpp
../Code/EarlyCrisis.cpp ../Code/EarlyOpenConflict.cpp ../Code/EarlyPeace.cpp ../Code/EarlyPhase.cpp ../Code/EarlyUnstablePeace.cpp 
../Code/LandTerrain.cpp ../Code/LateCrisis.cpp ../Code/LateOpenConflict.cpp ../Code/LatePeace.cpp ../Code/LatePhase.cpp 
../Code/LateUnstablePeace.cpp ../Code/Medic.cpp ../Code/MedicalSupply.cpp ../Code/MidPhase.cpp ../Code/MoveIntoTheatre.cpp 
../Code/Neutral.cpp ../Code/Offensive.cpp ../Code/Poor.cpp ../Code/Rich.cpp ../Code/SeaTerrain.cpp 
../Code/UnitFactory.cpp ../Code/WarPhase.cpp ../Code/WarTheatre.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)