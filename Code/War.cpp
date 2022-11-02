#include "War.h"
#include "EarlyPeace.h"
#include "AirTerrain.h"
#include "SeaTerrain.h"
#include "LandTerrain.h"
#include "Country.h"
War::War()
{
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Land", new LandTerrain()));
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Air", new AirTerrain()));
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Sea", new SeaTerrain()));
	phase = new EarlyPeace();
	isActive = true;
}

void War::setWarPhase(WarPhase *in)
{
	phase = in;
}

WarTheatre *War::getLandTheatre()
{
	return warTheatres.at("Land");
}
WarTheatre *War::getAirTheatre()
{
	return warTheatres.at("Air");
}
WarTheatre *War::getSeaTheatre()
{
	return warTheatres.at("Sea");
}

void War::changePhase()
{
	phase->handleChange(this);
}

void War::startWarSim()
{
	while (phase->peaceChance != 0)
	{
		srand((unsigned)time(NULL));
		changePhase();
		bool peace = ((double)rand() / (double)RAND_MAX) < (phase->peaceChance);
		if (peace == true)
		{
			std::cout << "Peace was reached before an escalation to a War" << std::endl;
			stopWar();
			return;
		}
	}

	while (isActive)
	{
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
				Country::alliance1.at(i)->takeTurn(this);
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
				Country::alliance2.at(i)->takeTurn(this);
		}

		warTheatres.at("Land")->conflict();
		warTheatres.at("Sea")->conflict();
		warTheatres.at("Air")->conflict();

		bool alliance1AllSurrendered = true;
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				alliance1AllSurrendered = false;
			}
		}
		bool alliance2AllSurrendered = false;
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				alliance2AllSurrendered = false;
			}
		}
		if ((!alliance1AllSurrendered) != (!alliance2AllSurrendered))
		{
			isActive = false;
		}
		if (warTheatres.at("Land")->getContentionState() != 0 || warTheatres.at("Sea")->getContentionState() != 0 || warTheatres.at("Air")->getContentionState() != 0)
		{
			if (warTheatres.at("Land")->getContentionState() != 3 || warTheatres.at("Sea")->getContentionState() != 3 || warTheatres.at("Air")->getContentionState() != 3)
			{
				if (warTheatres.at("Land")->getContentionState() == warTheatres.at("Sea")->getContentionState() == warTheatres.at("Air")->getContentionState())
				{
					isActive = false;
				}
			}
		}

		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				srand((unsigned)time(NULL));
				int gdp = 50000 - (std::rand() % (100000 - 0 + 1));
				Country::alliance1.at(i)->earnGDP(gdp);
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				srand((unsigned)time(NULL));
				int gdp = 50000 - (std::rand() % (100000 - 0 + 1));
				Country::alliance2.at(i)->earnGDP(gdp);
			}
		}
	}
}

void War::startWarGame()
{
	while (phase->peaceChance != 0)
	{
		srand((unsigned)time(NULL));
		changePhase();
		bool peace = ((double)rand() / (double)RAND_MAX) < (phase->peaceChance);
		if (peace == true)
		{
			std::cout << "Peace was reached before an escalation to a War" << std::endl;
			stopWar();
			return;
		}
	}

	while (isActive)
	{
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				std::cout << "What action would you like " << Country::alliance1.at(i) << " to perform?" << std::endl;
				std::cout << "1. Form Alliance." << std::endl;
				std::cout << "2. Raise an army." << std::endl;
				std::cout << "3. Upgrade a Unit Factory." << std::endl;
				std::cout << "4. Upgrade a Supply Factory." << std::endl;
				std::cout << "5. Enter the Army into the war theatre." << std::endl;
				std::cout << "6. Change the army strategy." << std::endl;
				std::cout << "7. Attack a transport line." << std::endl;
				std::cout << "8. Surrender." << std::endl;
				std::cout << "9. Send supplies." << std::endl;
				std::cout << "10. Do Nothing." << std::endl;
				std::cout << "(Please enter the corresponding number):";
				std::string inLine;
				std::getline(std::cin, inLine);
				std::cout << std::endl;
				int decision = std::stoi(inLine);
				switch (decision)
				{
				case 1:
					Country::alliance1.at(i)->formAlliance();
					break;
				case 2:
					Country::alliance1.at(i)->raiseArmy();
					break;

				case 3:
					Country::alliance1.at(i)->upgradeUnitFactory();
					break;

				case 4:
					Country::alliance1.at(i)->upgradeSupplyFactory();
					break;

				case 5:
					Country::alliance1.at(i)->enterArmyIntoTheatre(this);
					break;

				case 6:
					Country::alliance1.at(i)->changeArmyStrategy();
					break;

				case 7:
					Country::alliance1.at(i)->attackTransport();
					break;

				case 8:
					Country::alliance1.at(i)->surrender();
					break;

				case 9:
					Country::alliance1.at(i)->sendSupplies(Country::alliance1.at(i)->getNewAmmoSupply(), Country::alliance1.at(i)->getNewMedicalSupply());
					break;

				case 10:

					break;
				}
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
				Country::alliance2.at(i)->takeTurn(this);
		}

		warTheatres.at("Land")->conflict();
		warTheatres.at("Sea")->conflict();
		warTheatres.at("Air")->conflict();

		bool alliance1AllSurrendered = true;
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				alliance1AllSurrendered = false;
			}
		}
		bool alliance2AllSurrendered = false;
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				alliance2AllSurrendered = false;
			}
		}
		if ((!alliance1AllSurrendered) != (!alliance2AllSurrendered))
		{
			isActive = false;
		}
		if (warTheatres.at("Land")->getContentionState() != 0 || warTheatres.at("Sea")->getContentionState() != 0 || warTheatres.at("Air")->getContentionState() != 0)
		{
			if (warTheatres.at("Land")->getContentionState() != 3 || warTheatres.at("Sea")->getContentionState() != 3 || warTheatres.at("Air")->getContentionState() != 3)
			{
				if (warTheatres.at("Land")->getContentionState() == warTheatres.at("Sea")->getContentionState() == warTheatres.at("Air")->getContentionState())
				{
					isActive = false;
				}
			}
		}

		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				srand((unsigned)time(NULL));
				int gdp = 50000 - (std::rand() % (100000 - 0 + 1));
				Country::alliance1.at(i)->earnGDP(gdp);
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				srand((unsigned)time(NULL));
				int gdp = 50000 - (std::rand() % (100000 - 0 + 1));
				Country::alliance2.at(i)->earnGDP(gdp);
			}
		}
	}
	stopWar();
}

void War::stopWar()
{
	std::cout << "The war has concluded." << std::endl;
}
