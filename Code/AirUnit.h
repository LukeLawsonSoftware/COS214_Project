#ifndef AIRUNIT_H
#define AIRUNIT_H
#include "Soldier.h"

class AirUnit : public Soldier
{

public:
	/// @brief Constructs AirUnit object, calling constructor of parent Soldier
	/// @param powerRating The powerRating of the particular unit as per factory's cost (higher cost -> higher power)
	AirUnit(int powerRating);

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's AirOffence statistic
	/// @return	int value representing LandOffence statistic of unit
	int calculateAirOffense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's AirDefence statistic
	/// @return	int value representing LandOffence statistic of unit
	int calculateAirDefense();

	/// @brief Calculates the SeaOffense statistic of the unit
	/// @return	0 (no capability)
	int calculateSeaOffense();

	/// @brief Calculates the SeaDefence statistic of the unit
	/// @return	0 (no capability)
	int calculateSeaDefense();

	/// @brief Use Normal Distribution (with mean and stddev scaled by trainingLevel) to randomly generate the unit's LandOffence statistic
	/// @return	int value representing LandOffence statistic of unit
	int calculateLandOffense();

	/// @brief Calculates the LandDefence statistic of the unit
	/// @return	0 (no capability)
	int calculateLandDefense();
};

#endif
