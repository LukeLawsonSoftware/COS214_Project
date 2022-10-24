#ifndef AIRFACTORY_H
#define AIRFACTORY_H
#include "UnitFactory.h"
#include "AirVehicle.h"
#include "AirUnit.h"

class AirFactory : public UnitFactory
{

public:
	/// @brief Constructor for AirFactory class used to instantiate an AirFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of AirFactory class
	/// @param level Starting level of AirFactory class
	/// @param type Type will be "Air" since this function creates Air army components
	AirFactory(double budget, int level, std::string type = "Air");

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
