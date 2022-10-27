#include "Country.h"
#include "War.h"

Country::Country(std::string ecoState, std::string name)
{

	this->name = name;
	this->commander = new MilitaryCommander();
	this->hasSurrendered = false;
	this->ammoTransportLine = new AmmoTransporter();
	this->medicalTransportLine = new MedicTransporter();

	if (ecoState[0] == 'R' || ecoState[0] == 'r')
	{
		this->gdp = (int)(rand() % (1000000 - 800000 + 1) + 800000);
		this->ecoState = new Rich();
		this->unitFactories->push_back(new LandFactory(500000, 3, "Land"));
		this->unitFactories->push_back(new AirFactory(500000, 3, "Air"));
		this->unitFactories->push_back(new SeaFactory(500000, 3, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(500000));
		this->supplyFactories->push_back(new MedicalFactory(500000));
		this->army = NULL;
	}
	else if (ecoState[0] == 'P' || ecoState[0] == 'p')
	{
		this->gdp = (int)(rand() % (100000 - 50000 + 1) + 50000);
		this->ecoState = new Poor();

		this->unitFactories->push_back(new LandFactory(100000, 1, "Land"));
		this->unitFactories->push_back(new AirFactory(100000, 1, "Air"));
		this->unitFactories->push_back(new SeaFactory(100000, 1, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(100000));
		this->supplyFactories->push_back(new MedicalFactory(100000));
		this->army = NULL;
	}
	else
	{
		this->gdp = (int)(rand() % (500000 - 300000 + 1) + 300000);
		this->ecoState = new Average();

		this->unitFactories->push_back(new LandFactory(250000, 2, "Land"));
		this->unitFactories->push_back(new AirFactory(250000, 2, "Air"));
		this->unitFactories->push_back(new SeaFactory(250000, 2, "Sea"));

		this->supplyFactories->push_back(new AmmoFactory(250000));
		this->supplyFactories->push_back(new MedicalFactory(250000));
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
}

void Country::spendGDP(double gdpSpent)
{
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
}

void Country::takeTurn(War *currWar)
{
	int decision = this->ecoState->decideMyTurn();
	switch (decision)
	{
	case 1:
		// formAlliance
		break;
	case 2:
		// raiseArmy
		break;

	case 3:
		// upgradeUnitFactory
		break;

	case 4:
		// upgradeSupplyFactory
		break;

	case 5:
		//	enterArmyIntoTheatre
		break;

	case 6:
		// changeArmyStrategy
		break;

	case 7:
		// attackTransport
		break;

	case 8:
		// surrender
		break;

	case 9:
		// sendSupplies
		break;

	case 10:
		// do nothing
		break;
	}
}

void Country::formAlliance()
{
	std::cout << name << " decides to form a new alliance" << std::endl;
	if (neutral.size() == 0)
	{
		std::cout << "There are no Countries available to form an alliance with" << std::endl;
	}
	else
	{
		Country *c = neutral.at(neutral.size() - 1);
		neutral.pop_back();
		std::cout << c->getName() << " joins " << name << "'s alliance!" << std::endl;
		for (int i = 0; i < alliance1.size(); i++)
		{
			if (alliance1.at(i)->getName() == name)
			{
				alliance1.push_back(c);
				return;
			}
		}
		for (int i = 0; i < alliance2.size(); i++)
		{
			if (alliance2.at(i)->getName() == name)
			{
				alliance2.push_back(c);
				return;
			}
		}
	}
}

void Country::raiseArmy()
{
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
}

void Country::upgradeUnitFactory()
{
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
}

void Country::upgradeSupplyFactory()
{
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
}

void Country::enterArmyIntoTheatre(War *war)
{
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
}

void Country::changeArmyStrategy()
{
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
}

void Country::attackTransport()
{
	std::cout << name << " decides to attack a Transport line!" << std::endl;
	int enemyAlliance = 1;
	for (int i = 0; i < alliance1.size(); i++)
	{
		if (alliance1.at(i)->getName() == name)
		{
			enemyAlliance = 2;
			break;
		}
	}
	for (int i = 0; i < alliance2.size(); i++)
	{
		if (alliance2.at(i)->getName() == name)
		{
			enemyAlliance = 1;
		}
		break;
	}

	if (enemyAlliance == 1)
	{
		Country *target = alliance1.at(0);
		std::cout << name << " wants to attack the Transport line of " << target->getName() << std::endl;
		commander->setTransportTarget(target, army);
		commander->attackTransport();
	}
	else
	{
		Country *target = alliance2.at(0);
		std::cout << name << " wants to attack the Transport line of " << target->getName() << std::endl;
		commander->setTransportTarget(target, army);
		commander->attackTransport();
	}
}

void Country::surrender()
{
	std::cout << name << " decides to surrender from the war!" << std::endl;
	hasSurrendered = true;
}

void Country::sendSupplies(AmmoSupply *ammo, MedicalSupply *meds)
{
	std::cout << name << " decides to send supplies to its army" << std::endl;
}
