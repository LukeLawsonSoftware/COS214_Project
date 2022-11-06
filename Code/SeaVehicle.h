#ifndef SEAVEHICLE_H
#define SEAVEHICLE_H
#include "Vehicle.h"

/**
 * @class SeaVehicle SeaVehicle.h
 * @ref Vehicle.h "(See the definition of the Vehicle class)"
 * 
 * The SeaVehicle class is a derived class derived from the Vehicle class.
 * The SeaVehicle will be used to create an individual unit (vehicle) which will fight alongside soldier units in the war.
 * @note This class is used to do the calculations for a Vehicle and to instantiate a Vehicle object.
*/

class SeaVehicle : public Vehicle
{

public:
	/// @brief Constructs SeaVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	/// @warning The powerRating must be a value greater than zero.
	SeaVehicle(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's AirOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing AirOffense statistic of vehicle
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaVehicle and not an AirVehicle.
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaVehicle and not an AirVehicle.
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's SeaOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffense statistic of vehicle
	/// @note The returned value is a random integer value.
	int calculateSeaOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by armourRating) to randomly generate the unit's SeaDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaDefence statistic of vehicle
	/// @note The returned value is a random integer value.
	int calculateSeaDefense();

	/// @brief Calculates the LandOffence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaVehicle and not a LandVehicle.
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaVehicle and not a LandVehicle.
	int calculateLandDefense();
};

#endif
