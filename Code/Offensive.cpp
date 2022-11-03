#include "Offensive.h"
#include "BattleStatistics.h"
#include "Battalion.h"

void Offensive::applyStrategyBonus(BattleStatistics in, Battalion *inArmy)
{
	if (inArmy == NULL)
	{
		throw std::invalid_argument("Cannot accept an ArmyComponent of Null");
	}
	std::cout << "The army has applied a offensive strategy." << std::endl;
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
