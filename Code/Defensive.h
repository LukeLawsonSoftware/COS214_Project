#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "ArmyStrategy.h"
class BattleStatistics;
class Battalion;

class Defensive : public ArmyStrategy
{

public:
	/// @brief Applies desired Defensive bonuses to BattleStatistics
	/// @author Thomas Blendulf (u21446131)
	/// @param BattleStatistics passes in the BattleStatistics to be edited.
	/// @param Battalion passes in the Battalion to calculate base statistics to be editted.

	void applyStrategyBonus(BattleStatistics, Battalion *, std::string country);
};

#endif
