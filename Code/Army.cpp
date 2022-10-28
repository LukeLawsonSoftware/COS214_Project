#include "Army.h"

Army::Army(std::vector<ArmyComponent *> *battalions, std::vector<ArmyComponent *> *individuals, std::vector<Supply *> *supplies, std::string type)
{
	this->type = type;
	this->ammoSupply = new std::vector<AmmoSupply *>();
	this->medicalSupply = new std::vector<MedicalSupply *>();
	this->army = new Battalion();
	for (int i = 0; i < battalions->size(); i++)
	{
		this->army->addMember(battalions->at(i));
	}
	for (int i = 0; i < individuals->size(); i++)
	{
		this->army->addMember(individuals->at(i));
	}

	// Not finished, still need to do supplies and battlestatistics
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
	if (this->ammoSupply != NULL)
	{
		this->ammoSupply->push_back(ammo);
		std::cout << "Army has received ammunition" << std::endl;
	}
}

void Army::addNewMedicalSupplies(MedicalSupply *meds)
{
	if (this->medicalSupply != NULL)
	{
		this->medicalSupply->push_back(meds);
		std::cout << "Army has received medical supplies" << std::endl;
	}
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
