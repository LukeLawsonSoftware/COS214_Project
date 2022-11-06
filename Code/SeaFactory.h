#ifndef SEAFACTORY_H
#define SEAFACTORY_H
#include "UnitFactory.h"
class SeaVehicle;
class SeaUnit;

/**
 * @class SeaFactory SeaFactory.h
 * The SeaFactory class is a derived class derived from the UnitFactory class
 * @ref UnitFactory.h "(See the definition of the UnitFactory class)"
 * 
 * The SeaFactory will be used to create Sea Units for the War. The SeaFactory
 * has methods "createSoldier()" and "createVehicle()" which will create Soldier objects and
 * Vehicle objects respectively.
 * @note This class is ONLY used to create SeaUnit objects (Soldiers or Vehicles)
*/

class SeaFactory : public UnitFactory
{

public:
	/// @brief Constructor for SeaFactory class used to instantiate an SeaFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of SeaFactory class
	/// @param level Starting level of SeaFactory class
	/// @param type Type will be "Sea" since this function creates Sea army components
	/// @warning The "budget" must be a positive value. The "level" must be greater than zero.
	SeaFactory(double budget, int level, std::string type = "Sea");

	/// @brief Calls constructor of SeaVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a SeaVehicle)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of SeaUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a SeaUnit)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createSoldier();
};

#endif
