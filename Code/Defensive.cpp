#include "Defensive.h"
// #include "ArmyStrategy.h"
#include "Battalion.h"
#include "BattleStatistics.h"
#include "Country.h"

void Defensive::applyStrategyBonus(BattleStatistics in, Battalion *inArmy, std::string country)
{
	if (inArmy == NULL)
	{
		throw std::invalid_argument("Cannot accept an ArmyComponent of Null");
	}

	for (int i = 0; i < Country::alliance1.size(); i++)
	{
		if (country == Country::alliance1.at(i)->getName())
		{
			std::cout << "\033[;32m";
		}
	}
	for (int i = 0; i < Country::alliance2.size(); i++)
	{
		if (country == Country::alliance2.at(i)->getName())
		{
			std::cout << "\033[;31m";
		}
	}

	std::cout << "The " << country << " army is applying a defensive strategy." << std::endl;
	std::cout << "\033[;0m";
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
