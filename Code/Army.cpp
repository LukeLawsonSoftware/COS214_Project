#include "Army.h"
#include "ArmyComponent.h"
#include "AmmoSupply.h"
#include "Country.h"
#include "WarTheatre.h"
// #include "Corresponder.h"
#include "Offensive.h"
#include "Defensive.h"
#include "Neutral.h"
#include "MedicalSupply.h"
#include "Battalion.h"
#include "BattleStatistics.h"

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
		// std::cout << "here perhaps" << std::endl;
		this->army->addMember(individuals->at(i));
	}
	// std::cout << "maybe?" << std::endl;
	bool flag = true;
	for (int i = 0; i < supplies->size(); i++)
	{
		if (supplies->at(i) == NULL)
		{
			flag = false;
		}
		if (flag)
		{
			this->ammoSupply->push_back((AmmoSupply *)supplies->at(i));
		}
		else
		{
			this->medicalSupply->push_back((MedicalSupply *)supplies->at(i));
		}
	}

	this->currentStrategy = new Neutral();
	this->stats = new BattleStatistics();
	// std::cout << "maybe?" << std::endl;
	stats->setAirAttack(this->army->calculateAirOffense());
	// std::cout << "maybe?" << std::endl;
	stats->setAirDefence(this->army->calculateAirDefense());
	stats->setLandAttack(this->army->calculateLandOffense());
	stats->setLandDefence(this->army->calculateLandDefense());
	stats->setSeaAttack(this->army->calculateSeaOffense());
	stats->setSeaDefence(this->army->calculateSeaDefense());
	stats->setMorale(this->army->calculateAirOffense() +
					 this->army->calculateAirDefense() +
					 this->army->calculateLandOffense() +
					 this->army->calculateLandDefense() +
					 this->army->calculateSeaOffense() +
					 this->army->calculateSeaDefense());

	int ammoSum = 0;
	// std::cout << "maybe?" << std::endl;
	for (int i = 0; i < ammoSupply->size(); i++)
	{
		if (ammoSupply->at(i) != NULL)
		{
			ammoSum += ammoSupply->at(i)->getAmmoBonus();
		}
	}
	stats->setAvailableAmmo(ammoSum);
	// std::cout << "maybe?" << std::endl;
	int medSum = 0;
	for (int i = 0; i < medicalSupply->size(); i++)
	{
		if (medicalSupply->at(i) != NULL)
		{
			medSum += medicalSupply->at(i)->getMedicalBonus();
		}
	}

	stats->setMedical(medSum);
	// std::cout << "maybe?" << std::endl;
}

void Army::applyStrategyBonus()
{
	this->currentStrategy->applyStrategyBonus(*(this->stats), (Battalion *)(this->army));
	std::cout << "Army has had its Battle Statistics altered" << std::endl;
}

void Army::recuperate()
{
	for (int i = 0; i < this->medicalSupply->size(); i++)
	{
		if (medicalSupply->at(i) != NULL)
		{
			this->stats->setMorale(this->stats->getMorale() + medicalSupply->at(i)->getMedicalBonus());
		}
	}
}

void Army::addNewAmmoSupplies(AmmoSupply *ammo)
{
	if (this->ammoSupply != NULL)
	{
		this->ammoSupply->push_back(ammo);
		this->stats->setAvailableAmmo(stats->getAvailableAmmo() + ammo->getAmmoBonus());
		std::cout << "Army has received ammunition" << std::endl;
	}
}

void Army::addNewMedicalSupplies(MedicalSupply *meds)
{
	if (this->medicalSupply != NULL)
	{
		this->medicalSupply->push_back(meds);
		this->stats->setMedical(stats->getMedical() + meds->getMedicalBonus());
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
