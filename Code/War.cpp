#include "War.h"
#include "EarlyPeace.h"
#include "AirTerrain.h"
#include "SeaTerrain.h"
#include "LandTerrain.h"
#include "Country.h"
War::War()
{
	// std::cout << "here" << std::endl;
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Land", new LandTerrain()));
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Air", new AirTerrain()));
	warTheatres.insert(std::pair<std::string, WarTheatre *>("Sea", new SeaTerrain()));
	// std::cout << "here" << std::endl;
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

void War::setUpCountries()
{
	std::cout << "How Many Countries in Alliance 1 would you like?" << std::endl;
	std::string str1;
	std::getline(std::cin, str1);
	int all1 = std::stoi(str1);
	for (int i = 0; i < all1; i++)
	{
		std::cout << "Please enter the new Country's name:";
		std::string name;
		std::getline(std::cin, name);
		std::cout << std::endl;
		std::cout << "Is this Country Rich, Average or Poor:";
		std::string eco;
		std::getline(std::cin, eco);
		std::cout << std::endl;
		Country *c = new Country(eco, name);
		Country::alliance1.push_back(c);
	}

	std::cout << "How Many Countries in Alliance 2 would you like?" << std::endl;
	std::string str2;
	std::getline(std::cin, str2);
	int all2 = std::stoi(str2);
	for (int i = 0; i < all2; i++)
	{
		std::cout << "Please enter the new Country's name:";
		std::string name;
		std::getline(std::cin, name);
		std::cout << std::endl;
		std::cout << "Is this Country Rich, Average or Poor:";
		std::string eco;
		std::getline(std::cin, eco);
		std::cout << std::endl;
		Country *c = new Country(eco, name);
		Country::alliance2.push_back(c);
	}

	std::cout << "How Many Neutral Countries would you like?" << std::endl;
	std::string str3;
	std::getline(std::cin, str3);
	int neut = std::stoi(str3);
	for (int i = 0; i < neut; i++)
	{
		std::cout << "Please enter the new Country's name:";
		std::string name;
		std::getline(std::cin, name);
		std::cout << std::endl;
		std::cout << "Is this Country Rich, Average or Poor:";
		std::string eco;
		std::getline(std::cin, eco);
		std::cout << std::endl;
		Country *c = new Country(eco, name);
		Country::neutral.push_back(c);
	}
}

void War::startWarSim()
{
	// setUpCountries();
	int seed = 146863583;

	/*
		// Hardcoded setup for debugging
		Country *russia = new Country("Rich", "Russia");
		Country *china = new Country("Rich", "China");
		Country *india = new Country("Average", "India");
		Country *rsa = new Country("Poor", "South Africa");
		Country::alliance1.push_back(russia);
		Country::alliance1.push_back(china);
		Country::alliance1.push_back(india);
		Country::alliance1.push_back(rsa);

		Country *uk = new Country("Rich", "The UK");
		Country *ukraine = new Country("Average", "Ukraine");
		Country *germany = new Country("Average", "Germany");
		Country *spain = new Country("Average", "Spain");
		Country::alliance2.push_back(uk);
		Country::alliance2.push_back(ukraine);
		Country::alliance2.push_back(germany);
		Country::alliance2.push_back(spain);

		Country *france = new Country("Poor", "France");
		Country *america = new Country("Rich", "USA");
		Country::neutral.push_back(france);
		Country::neutral.push_back(america);
	*/
	while (phase->peaceChance != 0)
	{
		static int seeder = 1298;
		seeder += 6753;
		srand((unsigned)time(0) + seeder); // to generate a different value each time
		changePhase();
		bool peace = ((double)rand() / (double)RAND_MAX) < (phase->peaceChance);
		// std::cout << "here" << std::endl;
		if (peace == true)
		{
			std::cout << "Peace was reached before an escalation to a War" << std::endl;
			stopWar();
			return;
		}
	}
	// std::cout << "got here" << std::endl;

	while (isActive)
	{
		// std::cout << Country::alliance1.size() << std::endl;
		// std::cout << Country::alliance1.size() << std::endl;

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "DECISION PHASE"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			// std::cout << "in here" << std::endl;
			if (Country::alliance1.at(i)->isSurrendered() == false)
				Country::alliance1.at(i)->takeTurn(this);
			std::cout << std::endl;
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
				Country::alliance2.at(i)->takeTurn(this);
			std::cout << std::endl;
		}
		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "WAR THEATRES"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		warTheatres.at("Land")->conflict();
		std::cout << std::endl;
		warTheatres.at("Sea")->conflict();
		std::cout << std::endl;
		warTheatres.at("Air")->conflict();

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		bool alliance1AllSurrendered = true;
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				alliance1AllSurrendered = false;
			}
		}
		bool alliance2AllSurrendered = true;
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				alliance2AllSurrendered = false;
			}
		}
		//	if ((!alliance1AllSurrendered) != (!alliance2AllSurrendered))
		//	{
		//		isActive = false;
		//	}
		if (alliance1AllSurrendered && alliance2AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Both alliances have surrendered! The war is effectively a tie and peace negotiations are made" << std::endl;
			std::cout << "\033[;0m";
			break;
		}
		if (alliance1AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 1 has totally withdraw from the war, alliance 2 wins!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		if (alliance2AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 2 has totally withdraw from the war, alliance 1 wins!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		/*
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
		*/

		if (warTheatres.at("Land")->getContentionState() == 1 && warTheatres.at("Sea")->getContentionState() == 1 && warTheatres.at("Air")->getContentionState() == 1)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 1 controls all the war theatres and subsequently wins the war!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}
		if (warTheatres.at("Land")->getContentionState() == 2 && warTheatres.at("Sea")->getContentionState() == 2 && warTheatres.at("Air")->getContentionState() == 2)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 2 controls all the war theatres and subsequently wins the war!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "EARNINGS PHASE"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				static int seeder = 12300;
				seeder += 67848;
				srand((unsigned)time(0) + seeder); // to generate a different value each time
				// seed *= 1.378;
				int gdp = 500000 - (std::rand() % (2000000 - 0 + 1));
				if (gdp < 0)
				{
					gdp = -1 * gdp;
					Country::alliance1.at(i)->spendGDP(gdp);
				}
				else
				{
					Country::alliance1.at(i)->earnGDP(gdp);
				}
				std::cout << std::endl;
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				static int seeder = 37890;
				seeder += 3000;
				srand((unsigned)time(0) + seeder); // to generate a different value each time
				// seed *= 1.378;
				int gdp = 500000 - (std::rand() % (2000000 - 0 + 1));
				if (gdp < 0)
				{
					gdp = -1 * gdp;
					Country::alliance2.at(i)->spendGDP(gdp);
				}
				else
				{
					Country::alliance2.at(i)->earnGDP(gdp);
				}
				std::cout << std::endl;
			}
		}
		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		// to pause during debugging
		std::string test;
		std::cin >> test;
		if (test == "stop")
		{
			break;
		}
	}
	stopWar();
}

void War::startWarGame()
{
	int seed = 62857819;
	// setUpCountries();

	/*
		// Hardcoded setup for debugging
		Country *russia = new Country("Rich", "Russia");
		Country *china = new Country("Rich", "China");
		Country *india = new Country("Average", "India");
		Country *rsa = new Country("Poor", "South Africa");
		Country::alliance1.push_back(russia);
		Country::alliance1.push_back(china);
		Country::alliance1.push_back(india);
		Country::alliance1.push_back(rsa);

		Country *uk = new Country("Rich", "The UK");
		Country *ukraine = new Country("Average", "Ukraine");
		Country *germany = new Country("Average", "Germany");
		Country *spain = new Country("Average", "Spain");
		Country::alliance2.push_back(uk);
		Country::alliance2.push_back(ukraine);
		Country::alliance2.push_back(germany);
		Country::alliance2.push_back(spain);

		Country *france = new Country("Poor", "France");
		Country *america = new Country("Rich", "USA");
		Country::neutral.push_back(france);
		Country::neutral.push_back(america);
	*/

	while (phase->peaceChance != 0)
	{
		static int seeder = 9876;
		seeder += 1234;
		srand((unsigned)time(0) + seeder); // to generate a different value each time
		// seed *= 1.378;
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
		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "DECISION PHASE"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				std::cout << "What action would you like " << Country::alliance1.at(i)->getName() << " to perform?" << std::endl;
				std::cout << "1. Form Alliance.\t\t2. Raise an army." << std::endl;
				//	std::cout << "2. Raise an army." << std::endl;
				std::cout << "3. Upgrade a Unit Factory.\t\t4. Upgrade a Supply Factory." << std::endl;
				//	std::cout << "4. Upgrade a Supply Factory." << std::endl;
				std::cout << "5. Enter the Army into the war theatre.\t\t6. Change the army strategy." << std::endl;
				//	std::cout << "6. Change the army strategy." << std::endl;
				std::cout << "7. Attack a transport line.\t\t8. Surrender." << std::endl;
				//	std::cout << "8. Surrender." << std::endl;
				std::cout << "9. Send supplies.\t\t10. Do Nothing." << std::endl;
				//	std::cout << "10. Do Nothing." << std::endl;
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
					Country::alliance1.at(i)->sendSupplies();
					break;

				case 10:

					break;

				default:
					break;
				}
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
				Country::alliance2.at(i)->takeTurn(this);
			std::cout << std::endl;
		}
		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "WAR THEATRES"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		warTheatres.at("Land")->conflict();
		std::cout << std::endl;
		warTheatres.at("Sea")->conflict();
		std::cout << std::endl;
		warTheatres.at("Air")->conflict();

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		bool alliance1AllSurrendered = true;
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				alliance1AllSurrendered = false;
			}
		}
		bool alliance2AllSurrendered = true;
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				alliance2AllSurrendered = false;
			}
		}

		//	if ((!alliance1AllSurrendered) != (!alliance2AllSurrendered))
		//{
		//	isActive = false;
		//}

		if (alliance1AllSurrendered && alliance2AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Both alliances have surrendered! The war is effectively a tie and peace negotiations are made" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		if (alliance1AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 1 has totally withdraw from the war, alliance 2 wins!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		if (alliance2AllSurrendered)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 2 has totally withdraw from the war, alliance 1 wins!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		/*
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
		*/

		if (warTheatres.at("Land")->getContentionState() == 1 && warTheatres.at("Sea")->getContentionState() == 1 && warTheatres.at("Air")->getContentionState() == 1)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 1 controls all the war theatres and subsequently wins the war!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}
		if (warTheatres.at("Land")->getContentionState() == 2 && warTheatres.at("Sea")->getContentionState() == 2 && warTheatres.at("Air")->getContentionState() == 2)
		{
			std::cout << "\033[1;37m";
			std::cout << "Alliance 2 controls all the war theatres and subsequently wins the war!" << std::endl;
			std::cout << "\033[;0m";
			break;
		}

		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "EARNINGS PHASE"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";
		for (int i = 0; i < Country::alliance1.size(); i++)
		{
			if (Country::alliance1.at(i)->isSurrendered() == false)
			{
				static int seeder = 12300;
				seeder += 67848;
				srand((unsigned)time(0) + seeder); // to generate a different value each time
				// seed *= 1.378;
				int gdp = 500000 - (std::rand() % (2000000 - 0 + 1));
				if (gdp < 0)
				{
					gdp = -1 * gdp;
					Country::alliance1.at(i)->spendGDP(gdp);
				}
				else
				{
					Country::alliance1.at(i)->earnGDP(gdp);
				}
				std::cout << std::endl;
			}
		}
		for (int i = 0; i < Country::alliance2.size(); i++)
		{
			if (Country::alliance2.at(i)->isSurrendered() == false)
			{
				static int seeder = 37890;
				seeder += 3000;
				srand((unsigned)time(0) + seeder); // to generate a different value each time
				// seed *= 1.378;
				int gdp = 500000 - (std::rand() % (2000000 - 0 + 1));

				if (gdp < 0)
				{
					gdp = -1 * gdp;
					Country::alliance2.at(i)->spendGDP(gdp);
				}
				else
				{
					Country::alliance2.at(i)->earnGDP(gdp);
				}

				std::cout << std::endl;
			}
		}
		std::cout << "\033[1;37m";
		std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++ "
				  << "++++++++++++"
				  << " ++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "\033[;0m";

		// to pause during debugging
		std::string test;
		std::cin >> test;
		if (test == "stop")
		{
			break;
		}
	}
	stopWar();
}

void War::stopWar()
{
	while (phase->peaceChance != 1)
	{
		changePhase();
	}
	std::cout << "\033[1;37m";
	std::cout << "The war has concluded." << std::endl;
	std::cout << "\033[;0m";
}

void War::selectConfiguration()
{
	std::cout << "1. PRECONFIG: Allies (alliance 1) vs Axis Powers (alliance 2) [WW2]" << std::endl;
	std::cout << "2. PRECONFIG: BRICS (alliance 1) vs NAFTA (alliance 2) [Hypothetical]" << std::endl;
	std::cout << "3. CUSTOM: Configure your own war between two alliances!" << std::endl;

	std::string choice;
	std::getline(std::cin, choice);
	int option = std::stoi(choice);

	if (option == 1)
	{
		std::cout << "Alliance 1 [Allies]: Great Britain, France, Russia" << std::endl;
		std::cout << "Alliance 2 [Axis Powers]: Germany, Italy, Japan" << std::endl;
		std::cout << "Initially Neutral: USA, South Africa" << std::endl;

		Country *uk = new Country("Rich", "Great Britain");
		Country *russia = new Country("Rich", "Russia");
		Country *france = new Country("Poor", "France");

		Country *germany = new Country("Rich", "Germany");
		Country *italy = new Country("Average", "Italy");
		Country *japan = new Country("Average", "Japan");

		Country::alliance1.push_back(uk);
		Country::alliance1.push_back(russia);
		Country::alliance1.push_back(france);

		Country::alliance2.push_back(germany);
		Country::alliance2.push_back(italy);
		Country::alliance2.push_back(japan);

		Country *rsa = new Country("Poor", "South Africa");
		Country *america = new Country("Rich", "USA");

		Country::neutral.push_back(rsa);
		Country::neutral.push_back(america);
	}
	else if (option == 2)
	{
		std::cout << "Alliance 1 [BRICS]: Brazil, Russia, India, China, South Africa" << std::endl;
		std::cout << "Alliance 2 [NAFTA]: USA, Canada, Mexico" << std::endl;
		std::cout << "Initially Neutral: The UK, Germany, The Netherlands" << std::endl;

		Country *brazil = new Country("Average", "Brazil");
		Country *russia = new Country("Rich", "Russia");
		Country *india = new Country("Rich", "India");
		Country *china = new Country("Rich", "China");
		Country *rsa = new Country("Poor", "South Africa");

		Country *usa = new Country("Rich", "USA");
		Country *canada = new Country("Average", "Canada");
		Country *mexico = new Country("Poor", "Mexico");

		Country::alliance1.push_back(brazil);
		Country::alliance1.push_back(russia);
		Country::alliance1.push_back(india);
		Country::alliance1.push_back(china);
		Country::alliance1.push_back(rsa);

		Country::alliance2.push_back(usa);
		Country::alliance2.push_back(canada);
		Country::alliance2.push_back(mexico);

		Country *uk = new Country("Rich", "The UK");
		Country *germany = new Country("Rich", "Germany");
		Country *nether = new Country("Average", "The Netherlands");

		Country::neutral.push_back(uk);
		Country::neutral.push_back(germany);
		Country::neutral.push_back(nether);
	}
	else
	{
		setUpCountries();
	}
}
