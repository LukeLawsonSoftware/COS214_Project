#ifndef ARMYCOMPONENT_H
#define ARMYCOMPONENT_H
#include <cstdlib>
#include <cmath>
#include <ctime>

/**
 * @class ArmyComponent ArmyComponent.h
 * 
 * This class is just an abstract class for the following classes:
 * - Soldier
 * - Vehicle
 * - Battalion
 * 
 * We use this class to instantiate different components of an army such that those components can be used to help fight the on going war.
 * 
 */

class ArmyComponent
{

public:
	/// @brief Determines AirOffence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the AirOffence statistic of the ArmyComponent
	virtual int calculateAirOffense() = 0;

	/// @brief Determines AirDefence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the AirDefence statistic of the ArmyComponent
	virtual int calculateAirDefense() = 0;

	/// @brief Determines SeaOffence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the SeaOffence statistic of the ArmyComponent
	virtual int calculateSeaOffense() = 0;

	/// @brief Determines SeaDefence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the SeaDefence statistic of the ArmyComponent
	virtual int calculateSeaDefense() = 0;

	/// @brief Determines LandOffence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the LandOffence statistic of the ArmyComponent
	virtual int calculateLandOffense() = 0;

	/// @brief Determines LandDefence statistic of the ArmyComponent. Implemented in derived classes
	/// @author Luke Lawson (u21433811)
	/// @return int representing value of the LandDefence statistic of the ArmyComponent
	virtual int calculateLandDefense() = 0;

	/// @brief Interface function for adding objects to composite objects (Battalion)
	/// @author Luke Lawson (u21433811)
	/// @param newMember pointer to the ArmyComponent to be added to the Battalion (Composite)
	virtual void addMember(ArmyComponent *newMember) = 0;
};

#endif
