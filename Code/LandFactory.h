#ifndef LANDFACTORY_H
#define LANDFACTORY_H
#include "UnitFactory.h"
#include "LandVehicle.h"
#include "LandUnit.h"

class LandFactory : public UnitFactory
{

public:
	/// @brief Constructor for LandFactory class used to instantiate an LandFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of LandFactory class
	/// @param level Starting level of LandFactory class
	/// @param type Type will be "Land" since this function creates Land army components
	LandFactory(double budget, int level, std::string type = "Land");

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
