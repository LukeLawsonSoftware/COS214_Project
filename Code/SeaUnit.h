#ifndef SEAUNIT_H
#define SEAUNIT_H
#include "Soldier.h"

/**
 * @class SeaUnit SeaUnit.h
 * @ref Soldier.h "(See the definition of the Soldier class)"
 * 
 * The SeaUnit class is a derived class derived from the Soldier class.
 * The SeaUnit will be used to create Sea unit such as a Soldier to fight on the battlefield i.e. an Sea WarTheatre.
 * @note This class is used to do the calculations for a Soldier and to instantiate a Soldier object.
*/
class SeaUnit : public Soldier
{

public:
	/// @brief Constructs LandUnit object, calling constructor of parent Soldier
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular unit as per factory's cost (higher cost -> higher power)
	SeaUnit(int powerRating);

	/// @brief Calculates the AirOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaUnit and not an AirUnit.
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaUnit and not an AirUnit.
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's SeaOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateSeaOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's SeaDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaDefence statistic of unit
	/// @note The returned value is a random integer value.
	int calculateSeaDefense();

	/// @brief Calculates the LandOffence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaUnit and not a LandUnit.
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	/// @note The returned value is a random integer value.
	/// @warning It returns 0 since this is a SeaUnit and not a LandUnit.
	int calculateLandDefense();
};

#endif
