#include "AirFactory.h"

AirFactory::AirFactory(double budget, int level, std::string type = "Air")
	:UnitFactory(budget,level, type){}

ArmyComponent *AirFactory::createVehicle()
{
	return new AirVehicle(determineActualLevel());
}

ArmyComponent *AirFactory::createSoldier()
{
	return new AirUnit(determineActualLevel());
}
