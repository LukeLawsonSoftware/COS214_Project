#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "ArmyComponent.h"

class UnitFactory
{

protected:
	double cost;

public:
	virtual ArmyComponent *createVehicle() = 0;

	virtual ArmyComponent *createSoldier() = 0;
};

#endif
