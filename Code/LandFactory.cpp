#include "LandFactory.h"

LandFactory::LandFactory(double budget, int level, std::string type = "Land")
	:UnitFactory(budget,level, type){}

ArmyComponent *LandFactory::createVehicle()
{
	return new LandVehicle(determineActualLevel());
}

ArmyComponent *LandFactory::createSoldier()
{
	return new LandUnit(determineActualLevel());
}
