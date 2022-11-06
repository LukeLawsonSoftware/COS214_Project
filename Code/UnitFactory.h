#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "ArmyComponent.h"
#include <iostream>

/**
 * @class UnitFactory UnitFactory.h
 * 
 * This class is a necessity if a Country wants to create different units for its army.
 * There are three types of factories based on which type of WarTheatre the country is fighting in:
 * - AirFactory: This factory will create an AirUnit which includes:
 * 					- Soldiers and Vehicles
 * - LandFactory: This factory will create an LandUnit which includes:
 * 					- Soldiers and Vehicles
 * - SeaFactory: This factory will create an SeaUnit which includes:
 * 					- Soldiers and Vehicles
 * 
 * @note The country will only create units for the specific type of war theatre it is in. In other words air units will only be created for an air-type war theatre etc. 
 * 
 */

class UnitFactory
{
private:
	std::string type;  // the type of factory used to create the type of product
protected:
	double cost;
	int level;
	double totalSpent; // used to determine if we are able to affrod another product

public:
	/// @brief Constructor of the UnitFactory class used to instantiate a UnitFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget The starting budget of the factory
	/// @param level The starting level of the factory (all factories start at level one)
	/// @param type The type of factory
	/// @warning The budget must be a interger value greater than zero.
	/// @warning The level must also be an integer value greate than zero.
	UnitFactory(double budget, int level, std::string type);

	/// @brief Calls constructor of appropriate Vehicle (Air, Land or Sea), using level to determine powerRating. Implemented in child class
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a Land/Sea/AirVehicle)
	virtual ArmyComponent *createVehicle() = 0;

	/// @brief Calls constructor of appropriate Soldier (Air, Land or Sea), using level to determine powerRating. Implemented in child class
	/// @author Luke Lawson (u21433811)
	/// @return pointer to newly created ArmyComponent (which will be a Land/Sea/AirUnit)
	virtual ArmyComponent *createSoldier() = 0;

	/// @brief Getter to get the type of unit factory being used to create products
	/// @author Reuben Jooste (u21457060)
	/// @return The type of factory (Air, Sea or Land)
	std::string getType();

	/// @brief Getter to get the total amount spent so far to determine if we can afford another product
	/// @author Reuben Jooste (u21457060)
	/// @return The amount spent so far on creating products
	double getTotalSpent();

	/// @brief Getter to get the Factory's budget
	/// @author Reuben Jooste (u21457060)
	/// @return The maximum amount we can spent on creating products
	double getBudget();

	/// @brief Function to set the new budget of the factory after we upgraded the factory
	/// @author Reuben Jooste (u21457060)
	/// @param newBudget The new budget of the factory
	/// @warning The passed in value must be a value greater than zero.
	/// @note This function only increases the current budget by the passed in value.
	void setNewBudget(double newBudget);

	/// @brief Upgrades the factory, which will increase the budget capacity and level.
	/// @author Arno Jooste (u21457451)
	void upgrade();

protected:
	/// @brief Function to transform Factory's level to a valid value between 1-10. Purpose is to prevent potential bugs from other functions affecting accurate ArmyComponent creation
	/// @author Luke Lawson (u21433811)
	/// @return int within range 1-10
	int determineActualLevel();
};

#endif
