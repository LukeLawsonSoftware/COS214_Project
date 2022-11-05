#include "Neutral.h"
#include "BattleStatistics.h"
#include "Battalion.h"

void Neutral::applyStrategyBonus(BattleStatistics in, Battalion *inArmy, std::string country)
{
	if (inArmy == NULL)
	{
		throw std::invalid_argument("Cannot accept an ArmyComponent of Null");
	}
	std::cout << "The " << country << " army is applying a neutral strategy." << std::endl;
	in.airAttack = inArmy->calculateAirOffense();
	in.airDefence = inArmy->calculateAirDefense();
	in.landAttack = inArmy->calculateLandOffense();
	in.landDefence = inArmy->calculateLandDefense();
	in.seaAttack = inArmy->calculateSeaOffense();
	in.seaDefence = inArmy->calculateSeaDefense();
}
