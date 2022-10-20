#ifndef SEAUNIT_H
#define SEAUNIT_H
#include "Soldier.h"

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
	int calculateAirOffense();

	/// @brief Calculates the AirDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateAirDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's SeaOffence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaOffence statistic of unit
	int calculateSeaOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's SeaDefence statistic
	/// @author Luke Lawson (u21433811)
	/// @return	int value representing SeaDefence statistic of unit
	int calculateSeaDefense();

	/// @brief Calculates the LandOffence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the unit
	/// @author Luke Lawson (u21433811)
	/// @return	0 (no capability)
	int calculateLandDefense();
};

#endif
