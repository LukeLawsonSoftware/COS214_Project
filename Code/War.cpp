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

void War::setupTheatres()
{
	// TODO - implement War::setupTheatres
	throw "Not yet implemented";
}
void War::setWarPhase(WarPhase *)
{
	throw "Not yet implemented";
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

		/*
			EDIT GDP HERE
		*/
	}
}

void War::startWarGame()
{
	// TODO - implement War::startWarGame
	throw "Not yet implemented";
}

void War::stopWar()
{
	// TODO - implement War::stopWar
	throw "Not yet implemented";
}
