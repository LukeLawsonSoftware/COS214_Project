#ifndef AIRFACTORY_H
#define AIRFACTORY_H

#include "UnitFactory.h"
class AirVehicle;
class AirUnit;
/**
 * @class AirFactory AirFactory.h
 * The AirFactory class is a derived class derived from the UnitFactory class
 * @ref UnitFactory.h "(See the definition of the UnitFactory class)"
 * 
 * The AirFactory will be used to create Air Units for the War. The AirFactory
 * has methods "createSoldier()" and "createVehicle()" which will create Soldier objects and
 * Vehicle objects respectively.
 * @note This class is ONLY used to create AirUnit objects (Soldiers or Vehicles)
*/
class AirFactory : public UnitFactory
{

public:
	/// @brief Constructor for AirFactory class used to instantiate an AirFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget Starting budget of AirFactory class
	/// @param level Starting level of AirFactory class
	/// @param type Type will be "Air" since this function creates Air army components
	/// @warning The "budget" must be a positive value. The "level" must be greater than zero.
	AirFactory(double budget, int level, std::string type = "Air");

	/// @brief Calls constructor of AirVehicle, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a AirVehicle)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createVehicle();

	/// @brief Calls constructor of AirUnit, using level to determine powerRating.
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a AirUnit)
	/// @note This function may return NULL if the budget has run out.
	ArmyComponent *createSoldier();
};

#endif
