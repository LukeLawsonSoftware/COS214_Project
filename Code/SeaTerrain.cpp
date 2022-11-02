#include "SeaTerrain.h"

void SeaTerrain::adjustAttack() {
	double Bonus = 1.2;
	double Detriment = 0.8;

	Army* armies = getArmies();
	BattleStatistics* Stats = NULL;

	// Apply Bonus to Sea Attack
	for (int i = 0; i < 2; i++)
	{
		Stats = (armies + i)->getBattleStatistics();
		Stats->setSeaAttack(Bonus*Stats->getSeaAttack());
	}

	// Apply Detriment to Air and Land Attack
	for (int i = 0; i < 2; i++)
	{
		Stats = (armies + i)->getBattleStatistics();
		Stats->setAirAttack(Detriment*Stats->getAirAttack());
		Stats->setLandAttack(Detriment*Stats->getLandAttack());
	}
}

void SeaTerrain::adjustDefence() {
	double Bonus = 1.2;
	double Detriment = 0.8;

	Army* armies = getArmies();
	BattleStatistics* Stats = NULL;

	// Apply Bonus to Sea Defense
	for (int i = 0; i < 2; i++)
	{
		Stats = (armies + i)->getBattleStatistics();
		Stats->setSeaDefence(Bonus*Stats->getSeaDefence());
	}

	// Apply Detriment to Air and Land Defence
	for (int i = 0; i < 2; i++)
	{
		Stats = (armies + i)->getBattleStatistics();
		Stats->setAirDefence(Detriment*Stats->getAirDefence());
		Stats->setLandDefence(Detriment*Stats->getLandDefence());
	}
}
