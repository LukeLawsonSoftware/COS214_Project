#include "Army.h"

Army::Army(std::vector<ArmyComponent *> *battalions, std::vector<ArmyComponent *> *individuals, std::vector<Supply *> *supplies, std::string type)
{
}

void Army::applyStrategyBonus()
{
	// TODO - implement Army::applyStrategyBonus
	throw "Not yet implemented";
}

void Army::recuperate()
{
	// TODO - implement Army::recuperate
	throw "Not yet implemented";
}

void Army::addNewAmmoSupplies(AmmoSupply *ammo)
{
}

void Army::addNewMedicalSupplies(MedicalSupply *meds)
{
}

void Army::changeStrategy(std::string newStrat)
{
	if (newStrat[0] == 'O' || newStrat[0] == 'o')
	{
		delete this->currentStrategy;
		this->currentStrategy = new Offensive();
		std::cout << "The army adopts an Offensive strategy" << std::endl;
	}
	else if (newStrat[0] == 'D' || newStrat[0] == 'd')
	{
		delete this->currentStrategy;
		this->currentStrategy = new Defensive();
		std::cout << "The army adopts an Defensive strategy" << std::endl;
	}
	else
	{
		delete this->currentStrategy;
		this->currentStrategy = new Neutral();
		std::cout << "The army adopts an Neutral strategy" << std::endl;
	}
}
void Army::setBattleField(WarTheatre *theatre)
{
	theatre->addArmy(this);
}
void Army::attackTransport(Country *country)
{
	country->destroyTransport();
}

std::string Army::getType()
{
	return this->type;
}
