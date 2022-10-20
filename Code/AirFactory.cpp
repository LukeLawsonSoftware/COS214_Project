#include "AirFactory.h"

ArmyComponent *AirFactory::createVehicle()
{
	return new AirVehicle(determineActualLevel());
}

ArmyComponent *AirFactory::createSoldier()
{
	return new AirUnit(determineActualLevel());
}
