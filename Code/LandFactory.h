#ifndef LANDFACTORY_H
#define LANDFACTORY_H
#include "UnitFactory.h"
#include "LandVehicle.h"
#include "LandUnit.h"

class LandFactory : public UnitFactory
{

public:
	/// @brief Calls constructor of LandVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a LandVehicle)
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of LandUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a LandUnit)
	ArmyComponent *createSoldier();
};

#endif
