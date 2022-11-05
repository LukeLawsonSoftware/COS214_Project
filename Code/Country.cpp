#include "Country.h"
#include "War.h"
#include "EconomicState.h"
#include "Rich.h"
#include "Poor.h"
#include "Average.h"
#include "AmmoTransporter.h"
#include "MedicTransporter.h"
#include "Corresponder.h"
#include "LandFactory.h"
#include "AirFactory.h"
#include "SeaFactory.h"
#include "AmmoFactory.h"
#include "MedicalFactory.h"
#include "Army.h"
#include "WarTheatre.h"
#include "ArmyDirector.h"
#include "ArmyBuilder.h"
#include "MilitaryCommander.h"
// #include "Corresponder.h"
#include "SupplyFactory.h"

std::vector<Country *> Country::alliance1;
std::vector<Country *> Country::alliance2;
std::vector<Country *> Country::neutral;

Country::Country(std::string ecoState, std::string name)
{

	this->name = name;
	this->commander = new MilitaryCommander();
	this->hasSurrendered = false;
	this->ammoTransportLine = new AmmoTransporter();
	this->medicalTransportLine = new MedicTransporter();

	this->unitFactories = new std::vector<UnitFactory *>();
	this->supplyFactories = new std::vector<SupplyFactory *>();
	// we now register this Country to the above transport lines
	regToTransport(ammoTransportLine, medicalTransportLine);

	if (ecoState[0] == 'R' || ecoState[0] == 'r')
	{
		this->gdp = (int)(rand() % (1000000 - 800000 + 1) + 800000);
		this->ecoState = new Rich();
		this->unitFactories->push_back(new LandFactory(5000000, 3, "Land"));
		this->unitFactories->push_back(new AirFactory(5000000, 3, "Air"));
		this->unitFactories->push_back(new SeaFactory(5000000, 3, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(500000, "Ammo"));
		this->supplyFactories->push_back(new MedicalFactory(500000, "Medical"));
		this->army = NULL;
	}
	else if (ecoState[0] == 'P' || ecoState[0] == 'p')
	{
		this->gdp = (int)(rand() % (100000 - 50000 + 1) + 50000);
		this->ecoState = new Poor();

		this->unitFactories->push_back(new LandFactory(100000, 1, "Land"));
		this->unitFactories->push_back(new AirFactory(100000, 1, "Air"));
		this->unitFactories->push_back(new SeaFactory(100000, 1, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(100000, "Ammo"));
		this->supplyFactories->push_back(new MedicalFactory(100000, "Medical"));
		this->army = NULL;
	}
	else
	{
		this->gdp = (int)(rand() % (500000 - 300000 + 1) + 300000);
		this->ecoState = new Average();

		this->unitFactories->push_back(new LandFactory(250000, 2, "Land"));
		this->unitFactories->push_back(new AirFactory(250000, 2, "Air"));
		this->unitFactories->push_back(new SeaFactory(250000, 2, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(250000, "Ammo"));
		this->supplyFactories->push_back(new MedicalFactory(250000, "Medical"));
		this->army = NULL;
	}
}

bool Country::isSurrendered()
{
	return hasSurrendered;
}

std::string Country::getName()
{
	return name;
}

Country::~Country()
{
	delete ecoState;
	delete army;
	for (int i = 0; i < 3; i++)
	{
		delete unitFactories->at(i);
	}
	delete unitFactories;
	for (int i = 0; i < 2; i++)
	{
		delete supplyFactories->at(i);
	}
	delete supplyFactories;
}

void Country::earnGDP(double gdpEarned)
{
	setColour();
	std::cout << name << " earns GDP of " << gdpEarned << std::endl;
	this->gdp += gdpEarned;
	if (this->gdp >= 500000)
	{
		delete this->ecoState;
		this->ecoState = new Rich();
		std::cout << name << " is in a Rich economic state" << std::endl;
	}
	else if (this->gdp >= 100000)
	{
		delete this->ecoState;
		this->ecoState = new Average();
		std::cout << name << " is in an Average economic state" << std::endl;
	}
	else
	{
		delete this->ecoState;
		this->ecoState = new Poor();
		std::cout << name << " is in a Poor economic state" << std::endl;
	}
	std::cout << "\033[0m";
}

void Country::spendGDP(double gdpSpent)
{
	setColour();
	std::cout << name << " spends GDP of " << gdpSpent << std::endl;
	this->gdp -= gdpSpent;
	if (this->gdp >= 500000)
	{
		delete this->ecoState;
		this->ecoState = new Rich();
		std::cout << name << " is in a Rich economic state" << std::endl;
	}
	else if (this->gdp >= 100000)
	{
		delete this->ecoState;
		this->ecoState = new Average();
		std::cout << name << " is in an Average economic state" << std::endl;
	}
	else
	{
		delete this->ecoState;
		this->ecoState = new Poor();
		std::cout << name << " is in a Poor economic state" << std::endl;
	}
	std::cout << "\033[0m";
}

void Country::takeTurn(War *currWar)
{

	int decision = this->ecoState->decideMyTurn(this);
	switch (decision)
	{
	case 1:
		formAlliance();
		break;
	case 2:
		raiseArmy();
		break;

	case 3:
		upgradeUnitFactory();
		break;

	case 4:
		upgradeSupplyFactory();
		break;

	case 5:
		enterArmyIntoTheatre(currWar);
		break;

	case 6:
		changeArmyStrategy();
		break;

	case 7:
		attackTransport();
		break;

	case 8:
		surrender();
		break;

	case 9:
		sendSupplies();
		break;

	case 10:
		// do nothing
		std::cout << name << " decides to do nothing this turn" << std::endl;
		break;
	}
}

void Country::formAlliance()
{
	setColour();
	std::cout << name << " decides to form a new alliance" << std::endl;
	if (Country::neutral.size() == 0)
	{
		std::cout << "There are no Countries available to form an alliance with" << std::endl;
	}
	else
	{
		Country *c = Country::neutral.at(Country::neutral.size() - 1);
		Country::neutral.pop_back();
		std::cout << c->getName() << " joins " << name << "'s alliance!" << std::endl;
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->getName() == name)
			{
				Country::alliance1.push_back(c);

				return;
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->getName() == name)
			{
				Country::alliance2.push_back(c);
				return;
			}
		}
	}
	std::cout << "\033[0m";
}

void Country::raiseArmy()
{
	setColour();
	std::cout << name << " decides to raise an army" << std::endl;
	if (gdp > 300000)
	{
		if (this->army == NULL)
		{
			spendGDP(300000);
			int choice = rand() % 3;
			std::string type = "";
			if (choice == 0)
			{
				type = "Land";
			}
			else if (choice == 1)
			{
				type = "Sea";
			}
			else
			{
				type = "Air";
			}
			std::cout << name << " raises a " << type << " army!" << std::endl;
			ArmyBuilder *builder = new ArmyBuilder(type, unitFactories, supplyFactories);
			ArmyDirector dir(builder);
			dir.constructArmy();
			this->army = builder->getArmy();

			army->setName(name);
		}
		else
		{
			std::cout << name << " already has an army!" << std::endl;
		}
	}
	else
	{
		std::cout << name << " does not have enough GDP to raise an army!" << std::endl;
	}
	std::cout << "\033[0m";
}

void Country::upgradeUnitFactory()
{
	setColour();
	std::cout << name << " decides to upgrade its Unit Factories!" << std::endl;
	if (gdp > 100000)
	{
		spendGDP(100000);
		for (int i = 0; i < unitFactories->size(); i++)
		{
			unitFactories->at(i)->upgrade();
		}
		std::cout << name << " has upgraded its Unit Factories." << std::endl;
	}
	else
	{
		std::cout << name << " does not have enough GDP to perform the upgrade!" << std::endl;
	}
	std::cout << "\033[0m";
}

void Country::upgradeSupplyFactory()
{
	setColour();
	std::cout << name << " decides to upgrade its Supply Factories!" << std::endl;
	if (gdp > 100000)
	{
		spendGDP(100000);
		for (int i = 0; i < supplyFactories->size(); i++)
		{
			supplyFactories->at(i)->upgrade();
		}
		std::cout << name << " has upgraded its Supply Factories." << std::endl;
	}
	else
	{
		std::cout << name << " does not have enough GDP to perform the upgrade!" << std::endl;
	}
	std::cout << "\033[0m";
}

void Country::enterArmyIntoTheatre(War *war)
{
	setColour();
	std::cout << name << " decides to enter a War Theatre" << std::endl;
	std::string armyType = army->getType();
	WarTheatre *theatre = NULL;
	if (armyType[0] == 'L')
	{
		theatre = war->getLandTheatre();
	}
	else if (armyType[0] == 'A')
	{
		theatre = war->getAirTheatre();
	}
	else if (armyType[0] == 'S')
	{
		theatre = war->getSeaTheatre();
	}
	std::cout << name << "'s Military Commander commands army to enter " << theatre->getName() << std::endl;
	commander->setTheatreTarget(army, theatre);
	commander->enterTheatre();
	std::cout << "\033[0m";
}

void Country::changeArmyStrategy()
{
	setColour();
	std::cout << name << " decides to change their army's current strategy" << std::endl;
	int choice = rand() % 3;
	std::string newStrat = "Neutral";
	if (choice == 0)
	{
		newStrat = "Offensive";
	}
	else if (choice == 1)
	{
		newStrat = "Defensive";
	}
	else
	{
		newStrat = "Neutral";
	}
	std::cout << name << "'s Military Commander commands the army to adopt a " << newStrat << " strategy!" << std::endl;
	commander->setStrategy(army, newStrat);
	commander->changeStrategy();
	std::cout << "\033[0m";
}

void Country::attackTransport()
{
	setColour();
	std::cout << name << " decides to attack a Transport line!" << std::endl;
	int enemyAlliance = 1;
	for (int i = 0; i < Country::alliance1.size(); i++)
	{
		if (Country::alliance1.at(i)->getName() == name)
		{
			enemyAlliance = 2;
			break;
		}
	}
	for (int i = 0; i < Country::alliance2.size(); i++)
	{
		if (Country::alliance2.at(i)->getName() == name)
		{
			enemyAlliance = 1;
		}
		break;
	}

	if (enemyAlliance == 1)
	{
		Country *target = Country::alliance1.at(0);
		std::cout << name << " wants to attack the Transport line of " << target->getName() << std::endl;
		commander->setTransportTarget(target, army);
		commander->attackTransport();
	}
	else
	{
		Country *target = Country::alliance2.at(0);
		std::cout << name << " wants to attack the Transport line of " << target->getName() << std::endl;
		commander->setTransportTarget(target, army);
		commander->attackTransport();
	}
	std::cout << "\033[0m";
}

void Country::surrender()
{
	setColour();
	std::cout << name << " decides to surrender from the war!" << std::endl;
	hasSurrendered = true;
	std::cout << "\033[0m";
}

void Country::sendSupplies()
{
	setColour();
	// This function needs to do the following:
	//- create the new ammo and medical supplies to send using the factories such that this function no longer needs paramters
	//- set both ammo and medical supplies
	//-check if the ammoTransportLine and medicalTransportline are null before calling notify
	//-if they are null, they need to print out a message indicating that the ammo/medical supplies cant be send because the transport line is destroyed
	// im unsure how the whole transporting of supplies works so idk if maybe the chain of function calls needs to be reviewed to make sure it works as intended
	std::cout << name << " decides to send supplies to its army" << std::endl;

	Supply *newAmmo = NULL;
	Supply *newMedical = NULL;
	bool gotAmmo = false;
	bool gotMedical = false;
	for (int i = 0; i < supplyFactories->size(); i++)
	{
		if (gotAmmo && gotMedical)
		{
			break;
		}
		if (supplyFactories->at(i)->getType()[0] == 'A' && !gotAmmo)
		{
			newAmmo = supplyFactories->at(i)->makeSupply(5);
			gotAmmo = true;
		}
		if (supplyFactories->at(i)->getType()[0] == 'M' && !gotMedical)
		{
			newMedical = supplyFactories->at(i)->makeSupply(5);
			gotMedical = true;
		}
	}
	// set the new supplies
	setNewAmmoSupplies((AmmoSupply *)newAmmo);
	setNewMedicalSupplies((MedicalSupply *)newMedical);

	if (ammoTransportLine == NULL)
	{
		std::cout << name << " cannot send ammo supplies since the ammo transport line is destroyed!" << std::endl;
	}
	else
	{
		ammoTransportLine->notify(this);
	}

	if (medicalTransportLine == NULL)
	{
		std::cout << name << " cannot send medical supplies since the medical transport line is destroyed!" << std::endl;
	}
	else
	{
		medicalTransportLine->notify(this);
	}
	std::cout << "\033[0m";
}

AmmoSupply *Country::getNewAmmoSupply()
{
	return newAmmoSupply;
}

MedicalSupply *Country::getNewMedicalSupply()
{
	return newMedicalSupply;
}

void Country::setNewAmmoSupplies(AmmoSupply *newSupply)
{
	newAmmoSupply = newSupply;
}

void Country::setNewMedicalSupplies(MedicalSupply *newSupply)
{
	newMedicalSupply = newSupply;
}

Army *Country::getArmy()
{
	return army;
}

void Country::destroyArmy()
{
	this->army = NULL;
}

void Country::destroyTransport()
{
	if (this->medicalTransportLine != NULL)
	{
		this->medicalTransportLine = NULL;
		std::cout << name << "'s Medical Transport Line has been destroyed" << std::endl;
	}
	else if (this->ammoTransportLine != NULL)
	{
		this->ammoTransportLine = NULL;
		std::cout << name << "'s Ammo Transport Line has been destroyed" << std::endl;
	}
	else
	{
		std::cout << name << " has no transport lines to be destroyed" << std::endl;
	}
}

void Country::setColour()
{
	for (int i = 0; i < Country::alliance1.size(); i++)
	{
		if (this->getName() == alliance1.at(i)->getName())
		{
			std::cout << "\033[;32m";
			return;
		}
	}
	for (int i = 0; i < Country::alliance2.size(); i++)
	{
		if (this->getName() == alliance2.at(i)->getName())
		{
			std::cout << "\033[;31m";
			return;
		}
	}
}
