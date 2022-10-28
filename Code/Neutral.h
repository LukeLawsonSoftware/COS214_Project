#ifndef NEUTRAL_H
#define NEUTRAL_H
#include "ArmyStrategy.h"

class Neutral : public ArmyStrategy
{

public:
	/// @brief Applies desired Neutral bonuses to BattleStatistics
	/// @author Thomas Blendulf (u21446131)
	/// @param BattleStatistics passes in the BattleStatistics to be edited.
	/// @param Battalion passes in the Battalion to calculate base statistics to be editted.
	void applyStrategyBonus(BattleStatistics, Battalion *);
};

#endif
