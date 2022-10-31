#ifndef LANDUNIT_H
#define LANDUNIT_H

#include "Soldier.h"

class LandUnit : public Soldier
{

public:
	/// @brief Constructs LandUnit object, calling constructor of parent Soldier
	/// @author Luke Lawson (u21433811)
	/// @param powerRating The powerRating of the particular unit as per factory's cost (higher cost -> higher power)
	LandUnit(int powerRating);

	/// @brief Calculates the AirOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateAirDefense();

	/// @brief Calculates the SeaOffense statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandOffence statistic of unit
	int calculateLandOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing LandDefence statistic of unit
	int calculateLandDefense();
};

#endif
