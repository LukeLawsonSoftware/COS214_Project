#include "Neutral.h"
#include "BattleStatistics.h"
#include "Battalion.h"

void Neutral::applyStrategyBonus(BattleStatistics in, Battalion *inArmy)
{
	std::cout << "The army has applied a neutral strategy." << std::endl;
	in.airAttack = inArmy->calculateAirOffense();
	in.airDefence = inArmy->calculateAirDefense();
	in.landAttack = inArmy->calculateLandOffense();
	in.landDefence = inArmy->calculateLandDefense();
	in.seaAttack = inArmy->calculateSeaOffense();
	in.seaDefence = inArmy->calculateSeaDefense();
}
