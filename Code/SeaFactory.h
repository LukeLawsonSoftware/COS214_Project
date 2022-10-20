#ifndef SEAFACTORY_H
#define SEAFACTORY_H
#include "UnitFactory.h"
#include "ArmyComponent.h"

class SeaFactory : public UnitFactory
{

public:
	ArmyComponent *createVehicle();

	ArmyComponent *createSoldier();
};

#endif
