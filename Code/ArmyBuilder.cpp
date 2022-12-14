#include "ArmyBuilder.h"
#include "Battalion.h"
#include "Army.h"
#include "UnitFactory.h"
#include "SupplyFactory.h"

ArmyBuilder ::ArmyBuilder(std::string t, std::vector<UnitFactory *> *u, std::vector<SupplyFactory *> *s)
{
	type = t;
	unitFactories = u;
	supplyFactories = s;
	individuals = NULL;
	battalions = NULL;
	supplies = NULL;
}

std::vector<ArmyComponent *> *ArmyBuilder::createIndividuals()
{
	// TODO - implement ArmyBuilder::createIndividuals
	std::vector<ArmyComponent *> *smallUnits = new std::vector<ArmyComponent *>();
	bool completedConstruction = false;
	int allowedSoldiers, allowedVehicles, minReqSoldiers, minReqVehicles;
	allowedSoldiers = 50;
	allowedVehicles = 10;
	int totalSoldiers, totalVehicles; // for every 5 soldiers we create 1 vehicle
	totalSoldiers = totalVehicles = 0;

	switch (type[0])
	{
	case 'L':
	{ // construct Land Units
		// start at first factory and start building army. If factory's budget runs out choose next factory
		std::vector<UnitFactory *>::iterator it;
		int soldiersCreated = 0;

		for (it = unitFactories->begin(); it != unitFactories->end();)
		{
			// std::cout << "look here" << std::endl;
			// std::cout << (*it) << std::endl;
			if ((*it)->getType() == "Land")
			{
				//	//std::cout << "here1" << std::endl;
				bool next = false;

				if (totalSoldiers < allowedSoldiers)
				{
					int increase = 0;
					for (int i = soldiersCreated; i < 5; i++)
					{ // create soldiers
						ArmyComponent *unit = (*it)->createSoldier();
						//	//std::cout << unit << std::endl;
						if (unit != nullptr)
						{ // if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
							increase += 1;
						}
						else
						{
							soldiersCreated += increase;
							++it; // go to the next factory
							next = true;
							break; // break out of for loop creating soldiers
						}
					}
					// only way we enter this stage is if we did create 5 soldiers
					soldiersCreated = 0; // reset
				}
				if (next)
					continue; // why try to create a vehicle if the factory cannot create a soldier?

				if (totalVehicles < allowedVehicles)
				{
					// create one vehicle
					ArmyComponent *unit = (*it)->createVehicle();

					if (unit != nullptr)
					{ // if we could actually afford to create the vehicle
						smallUnits->push_back(unit);
						totalVehicles += 1;
					}
					else
					{
						++it; // go to the next factory
						continue;
					}
				}

				if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
				{
					completedConstruction = true;
					break; // jump out of loop
				}
			}
			else
			{
				++it; // go to the next factory
			}
		}
		// std::cout << "lookee here" << std::endl;
		break;
	}
	case 'S':
	{ // construct Sea Units
		// start at first factory and start building army. If factory's budget runs out choose next factory
		std::vector<UnitFactory *>::iterator it;
		int soldiersCreated = 0;

		for (it = unitFactories->begin(); it != unitFactories->end();)
		{
			// std::cout << "look here" << std::endl;
			// std::cout << (*it) << std::endl;
			if ((*it)->getType() == "Sea")
			{
				//	//std::cout << "here1" << std::endl;
				bool next = false;

				if (totalSoldiers < allowedSoldiers)
				{
					int increase = 0;
					for (int i = soldiersCreated; i < 5; i++)
					{ // create soldiers
						ArmyComponent *unit = (*it)->createSoldier();
						// //std::cout << unit << std::endl;
						//	//std::cout << unit << std::endl;
						if (unit != nullptr)
						{ // if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
							increase += 1;
							// //std::cout << "here" << std::endl;
						}
						else
						{
							soldiersCreated += increase;
							++it; // go to the next factory
							next = true;
							break; // break out of for loop creating soldiers
						}
					}
					// only way we enter this stage is if we did create 5 soldiers
					soldiersCreated = 0; // reset
				}
				if (next)
					continue; // why try to create a vehicle if the factory cannot create a soldier?

				if (totalVehicles < allowedVehicles)
				{
					// create one vehicle
					ArmyComponent *unit = (*it)->createVehicle();

					if (unit != nullptr)
					{ // if we could actually afford to create the vehicle
						smallUnits->push_back(unit);
						totalVehicles += 1;
					}
					else
					{
						++it; // go to the next factory
						continue;
					}
				}

				if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
				{
					completedConstruction = true;
					break; // jump out of loop
				}
			}
			else
			{
				++it; // go to the next factory
			}
		}
		// std::cout << "lookee here" << std::endl;
		break;
	}
	case 'A':
	{ // construct Air Units
		// start at first factory and start building army. If factory's budget runs out choose next factory
		std::vector<UnitFactory *>::iterator it;
		int soldiersCreated = 0;

		for (it = unitFactories->begin(); it != unitFactories->end();)
		{
			// std::cout << "look here" << std::endl;
			// std::cout << (*it) << std::endl;
			if ((*it)->getType() == "Air")
			{
				// //std::cout << "here1" << std::endl;
				bool next = false;

				if (totalSoldiers < allowedSoldiers)
				{
					int increase = 0;
					for (int i = soldiersCreated; i < 5; i++)
					{ // create soldiers
						ArmyComponent *unit = (*it)->createSoldier();

						if (unit != nullptr)
						{ // if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
							increase += 1;
						}
						else
						{
							soldiersCreated += increase;
							++it; // go to the next factory
							next = true;
							break; // break out of for loop creating soldiers
						}
					}
					// only way we enter this stage is if we did create 5 soldiers
					soldiersCreated = 0; // reset
				}
				if (next)
					continue; // why try to create a vehicle if the factory cannot create a soldier?

				if (totalVehicles < allowedVehicles)
				{
					// create one vehicle
					ArmyComponent *unit = (*it)->createVehicle();

					if (unit != nullptr)
					{ // if we could actually afford to create the vehicle
						smallUnits->push_back(unit);
						totalVehicles += 1;
					}
					else
					{
						++it; // go to the next factory
						continue;
					}
				}

				if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
				{
					completedConstruction = true;
					break; // jump out of loop
				}
			}
			else
			{
				++it; // go to the next factory
			}
		}
		// std::cout << "lookee here" << std::endl;
		break;
	}
	}
	// std::cout << "got to here" << std::endl;
	//  set the individuals
	setIndividuals(smallUnits);
	// std::cout << "got to here 2" << std::endl;
	return smallUnits;
}

std::vector<ArmyComponent *> *ArmyBuilder::buildBattalions()
{
	// TODO - implement ArmyBuilder::buildBattalions
	std::vector<ArmyComponent *> *armyBattalions = new std::vector<ArmyComponent *>();
	int allowedBattalions = 2;

	bool isDone = false;

	for (int b = 0; b < allowedBattalions; b++)
	{
		if (isDone)
		{
			break;
		}

		// create allowed number of battalions
		std::vector<ArmyComponent *> *smallUnits = new std::vector<ArmyComponent *>();
		int allowedSoldiers, allowedVehicles, minReqSoldiers, minReqVehicles;
		allowedSoldiers = 30;
		allowedVehicles = 6;
		minReqSoldiers = 20;
		minReqVehicles = 4;

		bool completedConstruction;
		int totalSoldiers, totalVehicles; // for every 5 soldiers we create 1 vehicle
		int totalBattalions;			  // for every 30 soldiers and 6 vehicles we create one battalion - there is a minimum requirement to create a battalion
		totalSoldiers = totalVehicles = totalBattalions = 0;

		switch (type[0])
		{
		case 'L':
		{ // construct Land Units
			// start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory *>::iterator it;
			int soldiersCreated = 0;

			for (it = unitFactories->begin(); it != unitFactories->end();)
			{
				if ((*it)->getType() == "Land")
				{
					bool next = false;

					if (totalSoldiers < allowedSoldiers)
					{
						int increase = 0;
						for (int i = soldiersCreated; i < 5; i++)
						{ // create soldiers
							ArmyComponent *unit = (*it)->createSoldier();

							if (unit != nullptr)
							{ // if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else
							{
								soldiersCreated += increase;
								++it; // go to the next factory
								next = true;
								break; // break out of for loop creating soldiers
							}
						}
						// only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0; // reset
					}
					if (next)
						continue; // why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles)
					{
						// create one vehicle
						ArmyComponent *unit = (*it)->createVehicle();

						if (unit != nullptr)
						{ // if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else
						{
							++it; // go to the next factory
							continue;
						}
					}

					if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
					{ // minimum requirements to create a battalion
						ArmyComponent *battalion = new Battalion();

						std::vector<ArmyComponent *>::iterator it_2;

						for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
						{
							battalion->addMember((*it_2));
						}

						armyBattalions->push_back(battalion);
						completedConstruction = true;
						break;
					}
				}
				else
				{
					++it; // go to the next factory
				}
			}

			// check if we can create a smaller battalion
			if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles))
			{ // minimum requirements to create a battalion
				ArmyComponent *battalion = new Battalion();

				std::vector<ArmyComponent *>::iterator it_2;

				for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
				{
					battalion->addMember((*it_2));
				}
				armyBattalions->push_back(battalion);
			}
			else
			{
				// since we couldn't create a battalion we add them as individual units
				std::vector<ArmyComponent *> *i = getIndividuals();

				std::vector<ArmyComponent *>::iterator it_3 = smallUnits->begin();

				for (; it_3 != smallUnits->end(); ++it_3)
				{
					i->push_back((*it_3));
				}
				// std::cout << i->size() << " before set" << std::endl;
				setIndividuals(i); // set new individuals
				isDone = true;
				//	delete i;
			}

			break;
		} // end case 'L'
		case 'S':
		{ // construct Sea Units
			// start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory *>::iterator it;
			int soldiersCreated = 0;

			for (it = unitFactories->begin(); it != unitFactories->end();)
			{
				if ((*it)->getType() == "Sea")
				{
					bool next = false;

					if (totalSoldiers < allowedSoldiers)
					{
						int increase = 0;
						for (int i = soldiersCreated; i < 5; i++)
						{ // create soldiers
							ArmyComponent *unit = (*it)->createSoldier();

							if (unit != nullptr)
							{ // if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else
							{
								soldiersCreated += increase;
								++it; // go to the next factory
								next = true;
								break; // break out of for loop creating soldiers
							}
						}
						// only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0; // reset
					}
					if (next)
						continue; // why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles)
					{
						// create one vehicle
						ArmyComponent *unit = (*it)->createVehicle();

						if (unit != nullptr)
						{ // if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else
						{
							++it; // go to the next factory
							continue;
						}
					}

					if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
					{ // minimum requirements to create a battalion
						ArmyComponent *battalion = new Battalion();

						std::vector<ArmyComponent *>::iterator it_2;

						for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
						{
							battalion->addMember((*it_2));
						}

						armyBattalions->push_back(battalion);
						completedConstruction = true;
						break;
					}
				}
				else
				{
					++it; // go to the next factory
				}
			}

			// std::cout << "maybe here" << std::endl;

			// check if we can create a smaller battalion
			if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles))
			{ // minimum requirements to create a battalion
				ArmyComponent *battalion = new Battalion();

				std::vector<ArmyComponent *>::iterator it_2;

				for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
				{
					battalion->addMember((*it_2));
				}
				armyBattalions->push_back(battalion);
			}
			else
			{
				// since we couldn't create a battalion we add them as individual units
				std::vector<ArmyComponent *> *i = getIndividuals();

				std::vector<ArmyComponent *>::iterator it_3 = smallUnits->begin();

				for (; it_3 != smallUnits->end(); ++it_3)
				{
					i->push_back((*it_3));
				}
				// std::cout << i->size() << " before set" << std::endl;
				setIndividuals(i); // set new individuals
				isDone = true;
				//	delete i;
			}

			break;
		} // end case 'S'
		case 'A':
		{ // construct Air Units
			// start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory *>::iterator it;
			int soldiersCreated = 0;

			for (it = unitFactories->begin(); it != unitFactories->end();)
			{
				if ((*it)->getType() == "Air")
				{
					bool next = false;

					if (totalSoldiers < allowedSoldiers)
					{
						int increase = 0;
						for (int i = soldiersCreated; i < 5; i++)
						{ // create soldiers
							ArmyComponent *unit = (*it)->createSoldier();

							if (unit != nullptr)
							{ // if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else
							{
								soldiersCreated += increase;
								++it; // go to the next factory
								next = true;
								break; // break out of for loop creating soldiers
							}
						}
						// only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0; // reset
					}
					if (next)
						continue; // why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles)
					{
						// create one vehicle
						ArmyComponent *unit = (*it)->createVehicle();

						if (unit != nullptr)
						{ // if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else
						{
							++it; // go to the next factory
							continue;
						}
					}

					if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles)
					{ // minimum requirements to create a battalion
						ArmyComponent *battalion = new Battalion();

						std::vector<ArmyComponent *>::iterator it_2;

						for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
						{
							battalion->addMember((*it_2));
						}

						armyBattalions->push_back(battalion);
						completedConstruction = true;
						break;
					}
				}
				else
				{
					++it; // go to the next factory
				}
			}

			// check if we can create a smaller battalion
			if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles))
			{ // minimum requirements to create a battalion
				ArmyComponent *battalion = new Battalion();

				std::vector<ArmyComponent *>::iterator it_2;

				for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2)
				{
					battalion->addMember((*it_2));
				}
				armyBattalions->push_back(battalion);
			}
			else
			{
				// since we couldn't create a battalion we add them as individual units
				std::vector<ArmyComponent *> *i = getIndividuals();

				std::vector<ArmyComponent *>::iterator it_3 = smallUnits->begin();

				for (; it_3 != smallUnits->end(); ++it_3)
				{
					i->push_back((*it_3));
				}
				// std::cout << i->size() << " before set" << std::endl;
				setIndividuals(i); // set new individuals
				isDone = true;
				// delete i;
			}

			break;
		} // end case 'A'

		} // end switch

	} // end big for-loop
	// set the battalions
	// std::cout << "made it here" << std::endl;
	setBattalions(armyBattalions);

	// finally return the battalions
	return armyBattalions;
}

std::vector<Supply *> *ArmyBuilder::determineSupplies()
{
	// TODO - implement ArmyBuilder::determineSupplies
	std::vector<Supply *> *armySupplies = new std::vector<Supply *>();
	int allowedAmmoSupplies, allowedMedSupplies, minReqSoldiers, minReqVehicles;
	allowedAmmoSupplies = 10;
	allowedMedSupplies = 10;
	int totalAmmoSupplies, totalMedSupplies; // for every 5 soldiers we create 1 vehicle
	totalAmmoSupplies = totalMedSupplies = 0;

	// start at first factory and start building supplies. If factory's budget runs out choose next factory
	std::vector<SupplyFactory *>::iterator it;

	// ammo suppplies
	for (it = supplyFactories->begin(); it != supplyFactories->end();)
	{
		if ((*it)->getType() == "Ammo")
		{
			if (totalAmmoSupplies < allowedAmmoSupplies)
			{
				for (int i = 0; i < allowedAmmoSupplies; i++)
				{ // create soldiers
					static int seeder = 28781;
					seeder += 899999;
					srand((unsigned)time(0) + seeder);			   // to generate a different value each time
					int quantity = (double)(200 + (rand() % 400)); // random number between 200 and 400 bullets

					Supply *unit = (*it)->makeSupply(quantity);

					if (unit != nullptr)
					{ // if we could actually afford to create the soldier
						armySupplies->push_back(unit);
						totalAmmoSupplies += 1;
					}
					else
					{
						++it;  // go to the next factory
						break; // break out of for loop creating soldiers
					}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			++it; // go to next factory
		}
	}
	armySupplies->push_back(NULL); // to seperate ammo and meds
	// medical supplies
	for (it = supplyFactories->begin(); it != supplyFactories->end();)
	{
		if ((*it)->getType() == "Medical")
		{
			if (totalMedSupplies < allowedMedSupplies)
			{
				for (int i = 0; i < allowedMedSupplies; i++)
				{ // create soldiers
					static int seeder = 9999999;
					seeder += 99999;
					srand((unsigned)time(0) + seeder);			  // to generate a different value each time
					int quantity = (double)(50 + (rand() % 100)); // random number between 50 and 100 meds

					Supply *unit = (*it)->makeSupply(quantity);

					if (unit != nullptr)
					{ // if we could actually afford to create the soldier
						armySupplies->push_back(unit);
						totalMedSupplies += 1;
					}
					else
					{
						++it;  // go to the next factory
						break; // break out of for loop creating soldiers
					}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			++it; // go to the next factory
		}
	}
	// set supplies
	setSupplies(armySupplies);
	// std::cout << "success" << std::endl;
	return armySupplies;
}

Army *ArmyBuilder::putArmyTogether()
{ // We will assume each army will be the same size
	/*Army will consist of: (if we have the budget)
		50 soldiers
		10 vehicles
		2 battalions -> 30 soldiers & 6 vehicles each
		10 ammo supplies
		10 medical supplies
		(these values may be changed)
	*/

	// also need to pass in type of army
	// std::cout << "vibes" << std::endl;
	army = new Army(getBattalions(), getIndividuals(), getSupplies(), this->type);
	// std::cout << "vibesx2" << std::endl;
	return army; //(battalions, individuals, supplies)
}

Army *ArmyBuilder::getArmy()
{
	return this->army;
}

std::vector<ArmyComponent *> *ArmyBuilder::getIndividuals()
{
	return individuals;
}

std::vector<ArmyComponent *> *ArmyBuilder::getBattalions()
{
	return battalions;
}

std::vector<Supply *> *ArmyBuilder::getSupplies()
{
	return supplies;
}

void ArmyBuilder::setIndividuals(std::vector<ArmyComponent *> *newIndv)
{
	// std::cout << newIndv->size() << std::endl;
	if (newIndv == NULL)
		return;

	// make deep copy
	if (individuals != NULL)
	{
		// //std::cout << individuals << std::endl;
		//   clear individuals (the buildBattalions() function passes in the old individuals with additional individuals)
		std::vector<ArmyComponent *>::iterator it;
		// individuals->push_back(NULL);
		// std::cout << "hele" << std::endl;
		// std::cout << newIndv->size() << std::endl;
		for (it = individuals->begin(); it != individuals->end(); ++it)
		{
			// //std::cout << "testing here 2" << std::endl;
			//	delete (*it);
		}
		// //std::cout << "testing here 2" << std::endl;
		// std::cout << newIndv->size() << "here" << std::endl;
		// delete individuals;
		// std::cout << newIndv->size() << "here" << std::endl;
		individuals = new std::vector<ArmyComponent *>;

		// now make the copy
		std::vector<ArmyComponent *>::iterator it1;
		// std::cout << newIndv->size() << std::endl;
		for (it1 = newIndv->begin(); it1 != newIndv->end(); ++it1)
		{
			//	//std::cout << "testing here 2" << std::endl;
			individuals->push_back((*it1));
		}
		// std::cout << "testing here 2" << std::endl;
	}
	else
	{
		individuals = newIndv;
	}
}

void ArmyBuilder::setBattalions(std::vector<ArmyComponent *> *newBattalions)
{
	if (newBattalions == NULL)
		return;

	// make deep copy
	if (battalions != NULL)
	{
		// clear battalions
		std::vector<ArmyComponent *>::iterator it;

		for (it = battalions->begin(); it != battalions->end(); ++it)
		{
			//	delete (*it);
		}
		delete battalions;

		battalions = new std::vector<ArmyComponent *>;

		// now make the copy
		std::vector<ArmyComponent *>::iterator it1;

		for (it1 = newBattalions->begin(); it1 != newBattalions->end(); ++it1)
		{
			battalions->push_back((*it1));
		}
	}
	else
	{
		battalions = newBattalions;
	}
}

void ArmyBuilder::setSupplies(std::vector<Supply *> *newSupplies)
{
	// std::cout << "here it is" << std::endl;
	if (newSupplies == NULL)
		return;

	// make deep copy
	if (supplies != NULL)
	{
		// clear supplies
		std::vector<Supply *>::iterator it;

		for (it = supplies->begin(); it != supplies->end(); ++it)
		{
			// delete (*it);
		}
		// delete supplies;

		supplies = new std::vector<Supply *>;
		// std::cout << "here it is" << std::endl;
		//  now make the copy
		std::vector<Supply *>::iterator it1;

		for (it1 = newSupplies->begin(); it1 != newSupplies->end(); ++it1)
		{
			supplies->push_back((*it1));
		}
	}
	else
	{
		// std::cout << "here it is" << std::endl;
		supplies = newSupplies;
	}
}
