#ifndef SOLDIER_H
#define SOLDIER_H
#include "ArmyComponent.h"
#include <iostream>

class Soldier : public ArmyComponent
{

protected:
	int trainingLevel;

public:
	/// @brief Construct Solider using powerLevel to determine trainingLevel
	/// @author Luke Lawson (u21433811)
	/// @param powerRating	powerRating of the Soldier (powerRating = trainingLevel)
	Soldier(int powerRating);

	/// @brief Calculates the AirOffense statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirOffense statistic of unit
	virtual int calculateAirOffense() = 0;

	/// @brief Calculates the AirDefence statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirDefence statistic of unit
	virtual int calculateAirDefense() = 0;

	/// @brief Calculates the SeaOffense statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffense statistic of unit
	virtual int calculateSeaOffense() = 0;

	/// @brief Calculates the SeaDefence statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaDefence statistic of unit
	virtual int calculateSeaDefense() = 0;

	/// @brief Calculates the LandOffence statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	virtual int calculateLandOffense() = 0;

	/// @brief Calculates the LandDefence statistic of the unit. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandDefence statistic of unit
	virtual int calculateLandDefense() = 0;

	/// @brief Composite method to create composite ArmyComponents. Stubbed here
	/// @author Luke Lawson (u21433811)
	/// @param newMember pointer to ArmyComponent to add to composite object
	void addMember(ArmyComponent *newMember);
};

#endif
