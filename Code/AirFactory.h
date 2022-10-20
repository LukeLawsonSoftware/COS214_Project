#ifndef AIRFACTORY_H
#define AIRFACTORY_H
#include "UnitFactory.h"
#include "AirVehicle.h"
#include "AirUnit.h"

class AirFactory : public UnitFactory
{

public:
	/// @brief Calls constructor of AirVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a AirVehicle)
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of AirUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a AirUnit)
	ArmyComponent *createSoldier();
};

#endif