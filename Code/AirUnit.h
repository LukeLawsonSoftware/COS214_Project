#ifndef AIRUNIT_H
#define AIRUNIT_H

#include "Soldier.h"
/**
 * @class AirUnit AirUnit.h
 * @ref Soldier.h "(See the definition of the Soldier class)"
 * 
 * The AirUnit class is a derived class derived from the Soldier class.
 * The AirUnit will be used to create Air unit such as a Soldier to fight on the battlefield i.e. an air WarTheatre.
 * @note This class is used to do the calculations for a Soldier and to instantiate a Soldier object.
*/
class AirUnit : public Soldier
{

public:
	/// @brief Constructs AirUnit object, calling constructor of parent Soldier
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular unit as per factory's cost (higher cost -> higher power)
	/// @warning The powerRating must be greater than zero.
	AirUnit(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's AirOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateAirOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's AirDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateAirDefense();

	/// @brief Calculates the SeaOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirUnit and not a SeaUnit.
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirUnit and not a SeaUnit.
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirUnit and not a LandUnit.
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is an AirUnit and not a LandUnit.
	int calculateLandDefense();
};

#endif
