#ifndef SEAVEHICLE_H
#define SEAVEHICLE_H
#include "Vehicle.h"

class SeaVehicle : public Vehicle
{

public:
	/// @brief Constructs SeaVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	SeaVehicle(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's AirOffence statistic
	/// @return	int value representing AirOffense statistic of vehicle
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the vehicle.
	/// @return	0 (no capability)
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's SeaOffence statistic
	/// @return	int value representing SeaOffense statistic of vehicle
	int calculateSeaOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's SeaDefence statistic
	/// @return	int value representing SeaDefence statistic of vehicle
	int calculateSeaDefense();

	/// @brief Calculates the LandOffence statistic of the vehicle.
	/// @return	0 (no capability)
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the vehicle.
	/// @return	0 (no capability)
	int calculateLandDefense();
};

#endif
