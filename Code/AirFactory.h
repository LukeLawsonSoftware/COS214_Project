#ifndef AIRFACTORY_H
#define AIRFACTORY_H
#include "UnitFactory.h"
#include "ArmyComponent.h"

class AirFactory : public UnitFactory
{

public:
	ArmyComponent *createVehicle();
	ArmyComponent *createSoldier();
};

#endif
