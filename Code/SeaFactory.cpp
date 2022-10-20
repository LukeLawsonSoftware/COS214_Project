#include "SeaFactory.h"

ArmyComponent *SeaFactory::createVehicle()
{
	return new SeaVehicle(determineActualLevel());
}

ArmyComponent *SeaFactory::createSoldier()
{
	return new SeaUnit(determineActualLevel());
}
