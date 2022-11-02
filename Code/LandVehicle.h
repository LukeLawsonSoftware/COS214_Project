#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H
#include "Vehicle.h"
// #include "Vehicle.h"

class LandVehicle : public Vehicle
{

public:
	/// @brief Constructs LandVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	LandVehicle(int powerRating);

	/// @brief Calculates the AirOffense statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateAirOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's AirDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirDefence statistic of vehicle
	int calculateAirDefense();

	/// @brief Calculates the SeaOffense statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of vehicle
	int calculateLandOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's LandDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandDefence statistic of vehicle
	int calculateLandDefense();
};

#endif
