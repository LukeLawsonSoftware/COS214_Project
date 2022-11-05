#include "LandTerrain.h"
#include <iostream>

LandTerrain::LandTerrain() : WarTheatre("Land", "The Plains of Doom")
{
}

void LandTerrain::adjustAttack()
{

	double Bonus = 1.2;
	double Detriment = 0.8;

	Army **armies = getArmies();
	BattleStatistics *Stats = NULL;

	// Apply Bonus to Land Attack
	for (int i = 0; i < 2; i++)
	{
		// std::cout << "here bb" << std::endl;
		Stats = armies[i]->getBattleStatistics();
		//	std::cout << "got here" << std::endl;
		Stats->setLandAttack(Bonus * Stats->getLandAttack());
		// std::cout << "got here too" << std::endl;
	}

	// Apply Detriment to Air and Sea Attack
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setAirAttack(Detriment * Stats->getAirAttack());
		Stats->setSeaAttack(Detriment * Stats->getSeaAttack());
	}
}

void LandTerrain::adjustDefence()
{
	double Bonus = 1.2;
	double Detriment = 0.8;

	Army **armies = getArmies();
	BattleStatistics *Stats = NULL;

	// Apply Bonus to Land Defense
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setLandDefence(Bonus * Stats->getLandDefence());
	}

	// Apply Detriment to Air and Sea Defence
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setAirDefence(Detriment * Stats->getAirDefence());
		Stats->setSeaDefence(Detriment * Stats->getSeaDefence());
	}
}
