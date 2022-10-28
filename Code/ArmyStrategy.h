#ifndef ARMYSTRATEGY_H
#define ARMYSTRATEGY_H
#include "BattleStatistics.h"
#include "Battalion.h"

class ArmyStrategy
{

public:
	/// @brief Applies desired bonuses to BattleStatistics
	/// @author Thomas Blendulf (u21446131)
	/// @param BattleStatistics passes in the BattleStatistics to be edited.
	/// @param Battalion passes in the Battalion to calculate base statistics to be editted.
	virtual void applyStrategyBonus(BattleStatistics, Battalion *);
};

#endif
