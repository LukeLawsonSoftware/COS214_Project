#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "ArmyComponent.h"

class UnitFactory
{

protected:
	double cost;
	int level;

public:
	/// @brief Calls constructor of appropriate Vehicle (Air, Land or Sea), using level to determine powerRating. Implemented in child class
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a Land/Sea/AirVehicle)
	virtual ArmyComponent *createVehicle() = 0;

	/// @brief Calls constructor of appropriate Soldier (Air, Land or Sea), using level to determine powerRating. Implemented in child class
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a Land/Sea/AirUnit)
	virtual ArmyComponent *createSoldier() = 0;

protected:
	/// @brief Function to transform Factory's level to a valid value between 1-10. Purpose is to prevent potential bugs from other functions affecting accurate ArmyComponent creation
	/// @author Luke Lawson (u21433811)
	/// @return int within range 1-10
	int determineActualLevel();
};

#endif
