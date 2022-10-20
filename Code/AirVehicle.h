#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H
#include "Vehicle.h"

class AirVehicle : public Vehicle
{

public:
	/// @brief Constructs AirVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	AirVehicle(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's AirOffence statistic
	/// @return	int value representing AirOffense statistic of vehicle
	int calculateAirOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's AirDefence statistic
	/// @return	int value representing AirDefence statistic of vehicle
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's SeaOffence statistic
	/// @return	int value representing SeaOffense statistic of vehicle
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the vehicle.
	/// @return	0 (no capability)
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's LandOffence statistic
	/// @return	int value representing LandOffence statistic of vehicle
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the vehicle.
	/// @return	0 (no capability)
	int calculateLandDefense();
};

#endif
