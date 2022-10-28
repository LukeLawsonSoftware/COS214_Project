#include "Offensive.h"

void Offensive::applyStrategyBonus(BattleStatistics in, Battalion *inArmy)
{
	in.airAttack = inArmy->calculateAirOffense();
	in.airDefence = inArmy->calculateAirDefense();
	in.landAttack = inArmy->calculateLandOffense();
	in.landDefence = inArmy->calculateLandDefense();
	in.seaAttack = inArmy->calculateSeaOffense();
	in.seaDefence = inArmy->calculateSeaDefense();
	in.airDefence *= 0.8;
	in.airAttack *= 1.5;
	in.landDefence *= 0.75;
	in.landAttack *= 1.25;
	in.seaDefence *= 0.8;
	in.seaAttack *= 1.3;
}
