#ifndef SEAFACTORY_H
#define SEAFACTORY_H
#include "UnitFactory.h"
class SeaVehicle;
class SeaUnit;

class SeaFactory : public UnitFactory
{

public:
	/// @brief Constructor for SeaFactory class used to instantiate an SeaFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of SeaFactory class
	/// @param level Starting level of SeaFactory class
	/// @param type Type will be "Sea" since this function creates Sea army components
	SeaFactory(double budget, int level, std::string type = "Sea");

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
