#include "Defensive.h"
// #include "ArmyStrategy.h"
#include "Battalion.h"
#include "BattleStatistics.h"

void Defensive::applyStrategyBonus(BattleStatistics in, Battalion *inArmy)
{
	std::cout << "The army has applied a defensive strategy." << std::endl;
	in.airAttack = inArmy->calculateAirOffense();
	in.airDefence = inArmy->calculateAirDefense();
	in.landAttack = inArmy->calculateLandOffense();
	in.landDefence = inArmy->calculateLandDefense();
	in.seaAttack = inArmy->calculateSeaOffense();
	in.seaDefence = inArmy->calculateSeaDefense();
	in.airDefence *= 1.2;
	in.airAttack *= 0.8;
	in.landDefence *= 1.5;
	in.landAttack *= 0.75;
	in.seaDefence *= 1.35;
	in.seaAttack *= 0.8;
}
