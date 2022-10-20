#ifndef SEAFACTORY_H
#define SEAFACTORY_H
#include "UnitFactory.h"
#include "SeaVehicle.h"
#include "SeaUnit.h"

class SeaFactory : public UnitFactory
{

public:
	/// @brief Calls constructor of SeaVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a SeaVehicle)
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of SeaUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a SeaUnit)
	ArmyComponent *createSoldier();
};

#endif
