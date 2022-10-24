#ifndef VEHICLE_H
#define VEHICLE_H
#include "ArmyComponent.h"

class Vehicle : public ArmyComponent
{

protected:
	int armourRating;
	int weaponClass;
	double vehicleCost;

public:
	/// @brief Construct Vehicle using powerRating to determine attribute values
	/// @author Luke Lawson (u21433811)
	/// @param powerRating int used to determine armourRating and weaponClass of Vehicle
	Vehicle(int powerRating);

	/// @brief Calculates the AirOffense statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirOffense statistic of vehicle
	virtual int calculateAirOffense() = 0;

	/// @brief Calculates the AirDefence statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirDefence statistic of vehicle
	virtual int calculateAirDefense() = 0;

	/// @brief Calculates the SeaOffense statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffense statistic of vehicle
	virtual int calculateSeaOffense() = 0;

	/// @brief Calculates the SeaDefence statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaDefence statistic of vehicle
	virtual int calculateSeaDefense() = 0;

	/// @brief Calculates the LandOffence statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of vehicle
	virtual int calculateLandOffense() = 0;

	/// @brief Calculates the LandDefence statistic of the vehicle. Implemented in child classes
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandDefence statistic of vehicle
	virtual int calculateLandDefense() = 0;

	/// @brief Composite method to create composite ArmyComponents. Stubbed here
	/// @author Luke Lawson (u21433811)
	/// @param newMember pointer to ArmyComponent to add to composite object
	void addMember(ArmyComponent *newMember);

	/// @brief Function to get teh cost of creating one Vehicle object
	/// @author Reuben Jooste (u21457060)
	/// @return The cost of one Vehicle object
	double getVehicleCost();
};

#endif
