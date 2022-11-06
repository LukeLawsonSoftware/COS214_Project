#ifndef ARMYSTRATEGY_H
#define ARMYSTRATEGY_H
class BattleStatistics;
class Battalion;
#include <iostream>

/**
 * @class ArmyStrategy ArmyStrategy.h
 * 
 * This class is only used to specify the strategy an Army is using.
 * 
 */

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
