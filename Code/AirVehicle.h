#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include "Vehicle.h"

/**
 * @class AirVehicle AirVehicle.h
 * @ref Vehicle.h "(See the definition of the Vehicle class)"
 * 
 * The AirVehicle class is a derived class derived from the Vehicle class.
 * The AirVehicle will be used to create an individual unit (vehicle) which will fight alongside soldier units in the war.
 * @note This class is used to do the calculations for a Vehicle and to instantiate a Vehicle object.
*/

class AirVehicle : public Vehicle
{

public:
	/// @brief Constructs AirVehicle object, using powerRating to randomly generate attributes from Normal Dist. (higher power -> better attributes)
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular vehicle as per factory's cost (higher cost -> higher power)
	/// @warning The powerRating cannot be a negative number.
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
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirVehicle and not a SeaVehicle.
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirVehicle and not a SeaVehicle.
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by weaponClass) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of vehicle
	/// @warning It returns 0 since this is an AirVehicle and not a LandVehicle.
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the vehicle.
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirVehicle and not a LandVehicle.
	int calculateLandDefense();
};

#endif
