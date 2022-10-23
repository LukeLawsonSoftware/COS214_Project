#include "ArmyBuilder.h"
#include "Battalion.h"

ArmyBuilder :: ArmyBuilder(std::string t, std::vector<UnitFactory*>* u, std::vector<SupplyFactory*>* s){
	type = t;
	unitFactories = u;
	supplyFactories = s;
}

std::vector<ArmyComponent*>* ArmyBuilder::createIndividuals() {
	// TODO - implement ArmyBuilder::createIndividuals
	std::vector<ArmyComponent*> *smallUnits;
	bool completedConstruction = false;
	int allowedSoldiers , allowedVehicles, minReqSoldiers, minReqVehicles;
	allowedSoldiers = 50;
	allowedVehicles = 10;
	int totalSoldiers, totalVehicles; //for every 5 soldiers we create 1 vehicle
	totalSoldiers = totalVehicles = 0;
	
	switch(type[0]){
		case 'L':{ //construct Land Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;
			int soldiersCreated = 0;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Land"){
					bool next = false;

					if(totalSoldiers < allowedSoldiers){
						int increase = 0;
						for(int i = soldiersCreated; i < 5; i++){//create soldiers 
							ArmyComponent* unit = it->createSoldier();
							
							if (unit != nullptr){//if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else{
								soldiersCreated += increase;
								++it;//go to the next factory
								next = true;
								break; //break out of for loop creating soldiers
							}
						}
						//only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0;//reset
					}
					if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles){
						//create one vehicle
						ArmyComponent* unit = it->createVehicle();
							
						if (unit != nullptr){//if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else{
							++it;//go to the next factory
							continue; 
						}
					}

					if(totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			delete it;
			break;
		}
		case 'S':{ //construct Sea Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;
			int soldiersCreated = 0;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Sea"){
					bool next = false;

					if(totalSoldiers < allowedSoldiers){
						int increase = 0;
						for(int i = soldiersCreated; i < 5; i++){//create soldiers 
							ArmyComponent* unit = it->createSoldier();
							
							if (unit != nullptr){//if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else{
								soldiersCreated += increase;
								++it;//go to the next factory
								next = true;
								break; //break out of for loop creating soldiers
							}
						}
						//only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0;//reset
					}
					if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles){
						//create one vehicle
						ArmyComponent* unit = it->createVehicle();
							
						if (unit != nullptr){//if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else{
							++it;//go to the next factory
							continue; 
						}
					}

					if(totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			delete it;
			break;
		}
		case 'A':{ //construct Air Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;
			int soldiersCreated = 0;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Air"){
					bool next = false;

					if(totalSoldiers < allowedSoldiers){
						int increase = 0;
						for(int i = soldiersCreated; i < 5; i++){//create soldiers 
							ArmyComponent* unit = it->createSoldier();
							
							if (unit != nullptr){//if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
								increase += 1;
							}
							else{
								soldiersCreated += increase;
								++it;//go to the next factory
								next = true;
								break; //break out of for loop creating soldiers
							}
						}
						//only way we enter this stage is if we did create 5 soldiers
						soldiersCreated = 0;//reset
					}
					if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

					if (totalVehicles < allowedVehicles){
						//create one vehicle
						ArmyComponent* unit = it->createVehicle();
							
						if (unit != nullptr){//if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else{
							++it;//go to the next factory
							continue; 
						}
					}

					if(totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			delete it;
			break;
		}
		default:{ //construct any type of unit 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;
			int soldiersCreated = 0;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				bool next = false;

				if(totalSoldiers < allowedSoldiers){
					int increase = 0;
					for(int i = soldiersCreated; i < 5; i++){//create soldiers 
						ArmyComponent* unit = it->createSoldier();
						
						if (unit != nullptr){//if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
							increase += 1;
						}
						else{
							soldiersCreated += increase;
							++it;//go to the next factory
							next = true;
							break; //break out of for loop creating soldiers
						}
					}
					//only way we enter this stage is if we did create 5 soldiers
					soldiersCreated = 0;//reset
				}
				if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

				if (totalVehicles < allowedVehicles){
					//create one vehicle
					ArmyComponent* unit = it->createVehicle();
						
					if (unit != nullptr){//if we could actually afford to create the vehicle
						smallUnits->push_back(unit);
						totalVehicles += 1;
					}
					else{
						++it;//go to the next factory
						continue; 
					}
				}

				if(totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){
					completedConstruction = true;
					break; //jump out of loop
				}
			} 
			delete it;
			break;
		}
	}

	return smallUnits;
}

std::vector<ArmyComponent*>* ArmyBuilder::buildBattalions() {
	// TODO - implement ArmyBuilder::buildBattalions
	std::vector<ArmyComponent*> *battalions;
	int allowedBattalions = 2;
	
	for(int b = 0; b < allowedBattalions; b++){//create allowed number of battalions
		std::vector<ArmyComponent*> *smallUnits;
		int allowedSoldiers , allowedVehicles, minReqSoldiers, minReqVehicles;
		allowedSoldiers = 30;
		allowedVehicles = 6;
		minReqSoldiers = 20;
		minReqVehicles = 4;

		bool completedConstruction;
		int totalSoldiers, totalVehicles; //for every 5 soldiers we create 1 vehicle
		int totalBattalions; //for every 30 soldiers and 6 vehicles we create one battalion - there is a minimum requirement to create a battalion
		totalSoldiers = totalVehicles = totalBattalions = 0;

		switch(type[0]){
			case 'L':{ //construct Land Units 
				//start at first factory and start building army. If factory's budget runs out choose next factory
				std::vector<UnitFactory*>::iterator *it;
				int soldiersCreated = 0;

				for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
					if (it->getType() == "Land"){
						bool next = false;

						if(totalSoldiers < allowedSoldiers){
							int increase = 0;
							for(int i = soldiersCreated; i < 5; i++){//create soldiers 
								ArmyComponent* unit = it->createSoldier();
								
								if (unit != nullptr){//if we could actually afford to create the soldier
									smallUnits->push_back(unit);
									totalSoldiers += 1;
									increase += 1;
								}
								else{
									soldiersCreated += increase;
									++it;//go to the next factory
									next = true;
									break; //break out of for loop creating soldiers
								}
							}
							//only way we enter this stage is if we did create 5 soldiers
							soldiersCreated = 0;//reset
						}
						if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

						if (totalVehicles < allowedVehicles){
							//create one vehicle
							ArmyComponent* unit = it->createVehicle();
								
							if (unit != nullptr){//if we could actually afford to create the vehicle
								smallUnits->push_back(unit);
								totalVehicles += 1;
							}
							else{
								++it;//go to the next factory
								continue; 
							}
						}

						if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){//minimum requirements to create a battalion
							ArmyComponent* battalion = new Battalion();

							std::vector<ArmyComponent*>::iterator it_2;

							for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
								battalion->addMember( (*it_2) );
							}

							battalions->push_back(battalion);
							completedConstruction = true;
							break;
						}

					}
					else{
						++it;//go to the next factory
					}
				} 

				//check if we can create a smaller battalion
				if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles) ){//minimum requirements to create a battalion
					ArmyComponent* battalion = new Battalion();

					std::vector<ArmyComponent*>::iterator it_2;

					for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
						battalion->addMember( (*it_2) );
					}
				}
				else{
					//since we couldn't create a battalion we add them as individual units
					std::vector<ArmyComponent*>* i = getIndividuals();

					std::vector<ArmyComponent*>::iterator it_3 = smallUnits->begin();

					for (; it_3 != smallUnits->end(); ++it_3){
						i->push_back( (*it_3) );
					}

					setIndividuals(i);//set new individuals

					delete i;
				}

				break;
			}//end case 'L'
			case 'S':{ //construct Sea Units 
				//start at first factory and start building army. If factory's budget runs out choose next factory
				std::vector<UnitFactory*>::iterator *it;
				int soldiersCreated = 0;

				for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
					if (it->getType() == "Sea"){
						bool next = false;

						if(totalSoldiers < allowedSoldiers){
							int increase = 0;
							for(int i = soldiersCreated; i < 5; i++){//create soldiers 
								ArmyComponent* unit = it->createSoldier();
								
								if (unit != nullptr){//if we could actually afford to create the soldier
									smallUnits->push_back(unit);
									totalSoldiers += 1;
									increase += 1;
								}
								else{
									soldiersCreated += increase;
									++it;//go to the next factory
									next = true;
									break; //break out of for loop creating soldiers
								}
							}
							//only way we enter this stage is if we did create 5 soldiers
							soldiersCreated = 0;//reset
						}
						if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

						if (totalVehicles < allowedVehicles){
							//create one vehicle
							ArmyComponent* unit = it->createVehicle();
								
							if (unit != nullptr){//if we could actually afford to create the vehicle
								smallUnits->push_back(unit);
								totalVehicles += 1;
							}
							else{
								++it;//go to the next factory
								continue; 
							}
						}

						if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){//minimum requirements to create a battalion
							ArmyComponent* battalion = new Battalion();

							std::vector<ArmyComponent*>::iterator it_2;

							for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
								battalion->addMember( (*it_2) );
							}

							battalions->push_back(battalion);
							completedConstruction = true;
							break;
						}

					}
					else{
						++it;//go to the next factory
					}
				} 

				//check if we can create a smaller battalion
				if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles) ){//minimum requirements to create a battalion
					ArmyComponent* battalion = new Battalion();

					std::vector<ArmyComponent*>::iterator it_2;

					for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
						battalion->addMember( (*it_2) );
					}
				}
				else{
					//since we couldn't create a battalion we add them as individual units
					std::vector<ArmyComponent*>* i = getIndividuals();

					std::vector<ArmyComponent*>::iterator it_3 = smallUnits->begin();

					for (; it_3 != smallUnits->end(); ++it_3){
						i->push_back( (*it_3) );
					}

					setIndividuals(i);//set new individuals

					delete i;
				}

				break;
			}//end case 'S'
			case 'A':{ //construct Air Units 
				//start at first factory and start building army. If factory's budget runs out choose next factory
				std::vector<UnitFactory*>::iterator *it;
				int soldiersCreated = 0;

				for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
					if (it->getType() == "Air"){
						bool next = false;

						if(totalSoldiers < allowedSoldiers){
							int increase = 0;
							for(int i = soldiersCreated; i < 5; i++){//create soldiers 
								ArmyComponent* unit = it->createSoldier();
								
								if (unit != nullptr){//if we could actually afford to create the soldier
									smallUnits->push_back(unit);
									totalSoldiers += 1;
									increase += 1;
								}
								else{
									soldiersCreated += increase;
									++it;//go to the next factory
									next = true;
									break; //break out of for loop creating soldiers
								}
							}
							//only way we enter this stage is if we did create 5 soldiers
							soldiersCreated = 0;//reset
						}
						if(next) continue;//why try to create a vehicle if the factory cannot create a soldier?

						if (totalVehicles < allowedVehicles){
							//create one vehicle
							ArmyComponent* unit = it->createVehicle();
								
							if (unit != nullptr){//if we could actually afford to create the vehicle
								smallUnits->push_back(unit);
								totalVehicles += 1;
							}
							else{
								++it;//go to the next factory
								continue; 
							}
						}

						if (totalSoldiers == allowedSoldiers && totalVehicles == allowedVehicles){//minimum requirements to create a battalion
							ArmyComponent* battalion = new Battalion();

							std::vector<ArmyComponent*>::iterator it_2;

							for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
								battalion->addMember( (*it_2) );
							}

							battalions->push_back(battalion);
							completedConstruction = true;
							break;
						}

					}
					else{
						++it;//go to the next factory
					}
				} 

				//check if we can create a smaller battalion
				if (!completedConstruction && (totalSoldiers >= minReqSoldiers && totalVehicles >= minReqVehicles) ){//minimum requirements to create a battalion
					ArmyComponent* battalion = new Battalion();

					std::vector<ArmyComponent*>::iterator it_2;

					for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
						battalion->addMember( (*it_2) );
					}
				}
				else{
					//since we couldn't create a battalion we add them as individual units
					std::vector<ArmyComponent*>* i = getIndividuals();

					std::vector<ArmyComponent*>::iterator it_3 = smallUnits->begin();

					for (; it_3 != smallUnits->end(); ++it_3){
						i->push_back( (*it_3) );
					}

					setIndividuals(i);//set new individuals

					delete i;
				}

				break;
			}//end case 'A'

		}//end switch
		
	}//end big for-loop

	//finally return the battalions
	return battalions;

}

std::vector<Supply*>* ArmyBuilder::determineSupplies() {
	// TODO - implement ArmyBuilder::determineSupplies
	
}

Army* ArmyBuilder::putArmyTogether() { //We will assume each army will be the same size
	/*Army will consist of: (if we have the budget)
		50 soldiers
		10 vehicles
		2 battalions -> 30 soldiers & 6 vehicles each
		(these values may be changed)
	*/
	// TODO - implement ArmyBuilder::putArmyTogether
	std::vector<ArmyComponent*>* b = buildBattalions();
	std::vector<ArmyComponent*>* i = createIndividuals();
	setIndividuals(i);
	std::vector<Supply*>* s = determineSupplies();

	return new Army(b, i, s); //(battalions, individuals, supplies)
}

Army* ArmyBuilder::getArmy() {
	return this->army;
}
