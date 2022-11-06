#ifndef LANDFACTORY_H
#define LANDFACTORY_H
#include "UnitFactory.h"
class LandVehicle;
class LandUnit;

/**
 * @class LandFactory LandFactory.h
 * The LandFactory class is a derived class derived from the UnitFactory class
 * @ref UnitFactory.h "(See the definition of the UnitFactory class)"
 * 
 * The LandFactory will be used to create Land Units for the War. The LandFactory
 * has methods "createSoldier()" and "createVehicle()" which will create Soldier objects and
 * Vehicle objects respectively.
 * @note This class is ONLY used to create LandUnit objects (Soldiers or Vehicles)
*/

class LandFactory : public UnitFactory
{

public:
	/// @brief Constructor for LandFactory class used to instantiate an LandFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of LandFactory class
	/// @param level Starting level of LandFactory class
	/// @param type Type will be "Land" since this function creates Land army components
	/// @warning The "budget" must be a positive value. The "level" must be greater than zero.
	LandFactory(double budget, int level, std::string type = "Land");

	/// @brief Calls constructor of LandVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a LandVehicle)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of LandUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a LandUnit)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createSoldier();
};

#endif
