#include "Country.h"
#include "War.h"

Country::Country(std::string ecoState, std::string name)
{
	this->name = name;
	if (ecoState[0] == 'R' || ecoState[0] == 'r')
	{
		this->gdp = (int)(rand() % (1000000 - 800000 + 1) + 800000);
		this->ecoState = new Rich();
		this->unitFactories = new UnitFactory *[3];
		unitFactories[0] = new LandFactory(500000, 3, "Land");
		unitFactories[1] = new AirFactory(500000, 3, "Air");
		unitFactories[2] = new SeaFactory(500000, 3, "Sea");
		this->army = NULL;
	}
	else if (ecoState[0] == 'P' || ecoState[0] == 'p')
	{
		this->gdp = (int)(rand() % (100000 - 50000 + 1) + 50000);
		this->ecoState = new Poor();
		this->unitFactories = new UnitFactory *[3];
		unitFactories[0] = new LandFactory(100000, 1, "Land");
		unitFactories[1] = new AirFactory(100000, 1, "Air");
		unitFactories[2] = new SeaFactory(100000, 1, "Sea");
		this->army = NULL;
	}
	else
	{
		this->gdp = (int)(rand() % (500000 - 300000 + 1) + 300000);
		this->ecoState = new Average();
		this->unitFactories = new UnitFactory *[3];
		unitFactories[0] = new LandFactory(250000, 1, "Land");
		unitFactories[1] = new AirFactory(250000, 1, "Air");
		unitFactories[2] = new SeaFactory(250000, 1, "Sea");
		this->army = NULL;
	}
}

Country::~Country()
{
	delete ecoState;
	delete army;
	for (int i = 0; i < 3; i++)
	{
		delete unitFactories[i];
	}
	delete[] unitFactories;
	for (int i = 0; i < 2; i++)
	{
		delete supplyFactories[i];
	}
	delete[] supplyFactories;
}

void Country::earnGDP(double gdpEarned)
{
	this->gdp += gdpEarned;
	if (this->gdp >= 500000)
	{
		delete this->ecoState;
		this->ecoState = new Rich();
	}
	else if (this->gdp >= 100000)
	{
		delete this->ecoState;
		this->ecoState = new Average();
	}
	else
	{
		delete this->ecoState;
		this->ecoState = new Poor();
	}
}

void Country::spendGDP(double gdpSpent)
{
	this->gdp -= gdpSpent;
	if (this->gdp >= 500000)
	{
		delete this->ecoState;
		this->ecoState = new Rich();
	}
	else if (this->gdp >= 100000)
	{
		delete this->ecoState;
		this->ecoState = new Average();
	}
	else
	{
		delete this->ecoState;
		this->ecoState = new Poor();
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

void Country::formAlliance(Country *newAlly)
{
	// TODO - implement Country::formAlliance
	throw "Not yet implemented";
}

void Country::raiseArmy()
{
	// TODO - implement Country::raiseArmy
	throw "Not yet implemented";
}

void Country::upgradeUnitFactory()
{
	// TODO - implement Country::upgradeUnitFactory
	throw "Not yet implemented";
}

void Country::upgradeSupplyFactory()
{
	// TODO - implement Country::upgradeSupplyFactory
	throw "Not yet implemented";
}

void enterArmyIntoTheatre(Army *army, WarTheatre *theatre)
{
	// TODO - implement Country::changeArmyStrategy
	throw "Not yet implemented";
}

void Country::changeArmyStrategy(Army *army, std::string newStrategy)
{
	// TODO - implement Country::changeArmyStrategy
	throw "Not yet implemented";
}

void Country::attackTransport(Army *army, Transporter *transport)
{
	// TODO - implement Country::attackTransport
	throw "Not yet implemented";
}

void Country::surrender()
{
	// TODO - implement Country::surrender
	throw "Not yet implemented";
}

void Country::sendSupplies(AmmoSupply *ammo, MedicalSupply *meds)
{
	// TODO - implement Country::sendSupplies
	throw "Not yet implemented";
}
