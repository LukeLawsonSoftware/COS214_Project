#include "LandFactory.h"

ArmyComponent *LandFactory::createVehicle()
{
	return new LandVehicle(determineActualLevel());
}

ArmyComponent *LandFactory::createSoldier()
{
	return new LandUnit(determineActualLevel());
}
