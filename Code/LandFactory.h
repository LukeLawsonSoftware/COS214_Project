#ifndef LANDFACTORY_H
#define LANDFACTORY_H
#include "UnitFactory.h"
#include "ArmyComponent.h"

class LandFactory : public UnitFactory
{

public:
	ArmyComponent *createVehicle();

	ArmyComponent *createSoldier();
};

#endif
