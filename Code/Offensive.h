#ifndef OFFENSIVE_H
#define OFFENSIVE_H
#include "ArmyStrategy.h"

class Offensive : public ArmyStrategy
{

public:
	/// @brief Applies desired Offensive bonuses to BattleStatistics
	/// @author Thomas Blendulf (u21446131)
	/// @param BattleStatistics passes in the BattleStatistics to be edited.
	/// @param Battalion passes in the Battalion to calculate base statistics to be editted.
	void applyStrategyBonus(BattleStatistics, Battalion *, std::string country);
};
#endif
