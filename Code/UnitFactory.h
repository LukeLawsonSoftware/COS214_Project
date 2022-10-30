#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "ArmyComponent.h"
#include <iostream>

class UnitFactory
{
private:
	std::string type;  // the type of factory used to create the type of product
	double totalSpent; // used to determine if we are able to affrod another product
protected:
	double cost;
	int level;

public:
	/// @brief Constructor of the UnitFactory class used to instantiate a UnitFactory object
	/// @author Reuben Jooste (u21457060)
	/// @param budget The starting budget of the factory
	/// @param level The starting level of the factory (all factories start at level one)
	/// @param type The type of factory
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

	/// @brief Function to set the new budgett of the factory after we upgraded the factory
	/// @author Reuben Jooste (u21457060)
	/// @param newBudget The new budget of the factory
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
