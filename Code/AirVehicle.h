#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include "Vehicle.h"

class AirVehicle : public Vehicle
{

public:
	/// @brief Constructs AirVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	AirVehicle(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's AirOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirOffense statistic of vehicle
	int calculateAirOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's AirDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirDefence statistic of vehicle
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's SeaOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffense statistic of vehicle
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of vehicle
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateLandDefense();
};

#endif
