#include "SeaFactory.h"

SeaFactory::SeaFactory(double budget, int level, std::string type = "Sea")
	:UnitFactory(budget,level, type){}

ArmyComponent *SeaFactory::createVehicle()
{
	return new SeaVehicle(determineActualLevel());
}

ArmyComponent *SeaFactory::createSoldier()
{
	return new SeaUnit(determineActualLevel());
}
