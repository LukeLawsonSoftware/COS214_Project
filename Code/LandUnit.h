#ifndef LANDUNIT_H
#define LANDUNIT_H

#include "Soldier.h"
/**
 * @class LandUnit LandUnit.h
 * @ref Soldier.h "(See the definition of the Soldier class)"
 * 
 * The LandUnit class is a derived class derived from the Soldier class.
 * The LandUnit will be used to create Land unit such as a Soldier to fight on the battlefield i.e. an Land WarTheatre.
 * @note This class is used to do the calculations for a Soldier and to instantiate a Soldier object.
*/
class LandUnit : public Soldier
{

public:
	/// @brief Constructs LandUnit object, calling constructor of parent Soldier
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular unit as per factory's cost (higher cost -> higher power)
	/// @warning The powerRating must be greater than zero.
	LandUnit(int powerRating);

	/// @brief Calculates the AirOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a LandUnit and not an AirUnit.
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a LandUnit and not an AirUnit.
	int calculateAirDefense();

	/// @brief Calculates the SeaOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a LandUnit and not a SeaUnit.
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a LandUnit and not a SeaUnit.
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateLandOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandDefence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateLandDefense();
};

#endif
