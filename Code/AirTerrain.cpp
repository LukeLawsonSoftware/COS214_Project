#include "AirTerrain.h"
// #include "WarTheatre.h"

AirTerrain::AirTerrain() : WarTheatre("Air", "The Sky Arena")
{
}

void AirTerrain::adjustAttack()
{
	double Bonus = 1.2;
	double Detriment = 0.8;

	Army **armies = getArmies();
	BattleStatistics *Stats = NULL;

	// Apply Bonus to Air Attack
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setAirAttack(Bonus * Stats->getAirAttack());
	}

	// Apply Detriment to Land and Sea Attack
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setLandAttack(Detriment * Stats->getLandAttack());
		Stats->setSeaAttack(Detriment * Stats->getSeaAttack());
	}
}

void AirTerrain::adjustDefence()
{
	double Bonus = 1.2;
	double Detriment = 0.8;

	Army **armies = getArmies();
	BattleStatistics *Stats = NULL;

	// Apply Bonus to Land Defense
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setAirDefence(Bonus * Stats->getAirDefence());
	}

	// Apply Detriment to Land and Sea Defence
	for (int i = 0; i < 2; i++)
	{
		Stats = armies[i]->getBattleStatistics();
		Stats->setLandDefence(Detriment * Stats->getLandDefence());
		Stats->setSeaDefence(Detriment * Stats->getSeaDefence());
	}
}
