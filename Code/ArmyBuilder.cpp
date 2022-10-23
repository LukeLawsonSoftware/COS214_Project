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
	int totalSoldiers, totalVehicles; //for every 5 soldiers we create 1 vehicle
	totalSoldiers = totalVehicles = 0;
	
	switch(type[0]){
		case 'L':{ //construct Land Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Land"){
					for(int i = 0; i < 5; i++){//create soldiers
						ArmyComponent* unit = it->createSoldier();
						
						if (unit != nullptr){//if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
						}
						else{
							++it;//go to the next factory
							continue; //why try to create a vehicle if the factory cannot create a soldier?
						}
					}
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

					if(totalSoldiers == 50 && totalVehicles == 10){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			break;
		}
		case 'S':{ //construct Sea Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Sea"){
					for(int i = 0; i < 5; i++){//create soldiers
						ArmyComponent* unit = it->createSoldier();
						
						if (unit != nullptr){//if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
						}
						else{
							++it;//go to the next factory
							continue; //why try to create a vehicle if the factory cannot create a soldier?
						}
					}
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

					if(totalSoldiers == 50 && totalVehicles == 10){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			break;
		}
		case 'A':{ //construct Air Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Air"){
					for(int i = 0; i < 5; i++){//create soldiers
						ArmyComponent* unit = it->createSoldier();
						
						if (unit != nullptr){//if we could actually afford to create the soldier
							smallUnits->push_back(unit);
							totalSoldiers += 1;
						}
						else{
							++it;//go to the next factory
							continue; //why try to create a vehicle if the factory cannot create a soldier?
						}
					}
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

					if(totalSoldiers == 50 && totalVehicles == 10){
						completedConstruction = true;
						break; //jump out of loop
					}
				}
				else{
					++it;//go to the next factory
				}
			} 
			break;
		}
		default:{ //construct any type of unit 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				for(int i = 0; i < 5; i++){//create soldiers
					ArmyComponent* unit = it->createSoldier();
					
					if (unit != nullptr){//if we could actually afford to create the soldier
						smallUnits->push_back(unit);
						totalSoldiers += 1;
					}
					else{
						++it;//go to the next factory
						continue; //why try to create a vehicle if the factory cannot create a soldier?
					}
				}
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

				if(totalSoldiers == 50 && totalVehicles == 10){
					completedConstruction = true;
					break; //jump out of loop
				}
			} 
			break;
		}
	}
	return smallUnits;
}

std::vector<ArmyComponent*>* ArmyBuilder::buildBattalions() {
	// TODO - implement ArmyBuilder::buildBattalions
	std::vector<ArmyComponent*> *battalions;
	std::vector<ArmyComponent*> *smallUnits;
	bool completedConstruction = false;
	int totalSoldiers, totalVehicles; //for every 5 soldiers we create 1 vehicle
	int totalBattalions; //for every 30 soldiers and 6 vehicles we create one battalion - there is a minimum requirement to create a battalion
	totalSoldiers = totalVehicles = totalBattalions = 0;
	
	switch(type[0]){
		case 'L':{ //construct Land Units 
			//start at first factory and start building army. If factory's budget runs out choose next factory
			std::vector<UnitFactory*>::iterator *it;

			for (*it = unitFactories->begin(); *it != unitFactories->end(); ){
				if (it->getType() == "Land"){
					for(int b = 0; b < 6; b++){//we will create 30 (6 * 5) soldiers (if we are able to)
						for(int i = 0; i < 5; i++){//create soldiers
							ArmyComponent* unit = it->createSoldier();
							
							if (unit != nullptr){//if we could actually afford to create the soldier
								smallUnits->push_back(unit);
								totalSoldiers += 1;
							}
							else{
								++it;//go to the next factory
								continue; //why try to create a vehicle if the factory cannot create a soldier?
							}
						}
						//create one vehicle
						ArmyComponent* unit = it->createVehicle();
							
						if (unit != nullptr){//if we could actually afford to create the vehicle
							smallUnits->push_back(unit);
							totalVehicles += 1;
						}
						else{
							++it;//go to the next factory
							continue; //why try to create a vehicle if the factory cannot create a soldier?
						}
					}

					if (totalSoldiers >= 20 && totalVehicles >= 4){//minimum requirements to create a battalion
						ArmyComponent* battalion = new Battalion();

						std::vector<ArmyComponent*>::iterator it_2;

						for (it_2 = smallUnits->begin(); it_2 != smallUnits->end(); ++it_2){
							battalion->addMember( (*it_2) );
						}
					}
					else{
						//since we couldn't create a battalion we add them as individual units
					}

				}
				else{
					++it;//go to the next factory
				}
			} 
			break;
		}
	}
}

std::vector<Supply*>* ArmyBuilder::determineSupplies() {
	// TODO - implement ArmyBuilder::determineSupplies
	
}

Army* ArmyBuilder::putArmyTogether() { //We will assume each army will be the same size
	/*Army will consist of: (if we have the budget)
		50 soldiers
		10 vehicles
		2 battalions -> 30 soldiers & 6 vehicles
		(these values may be changed)
	*/
	// TODO - implement ArmyBuilder::putArmyTogether
	std::vector<ArmyComponent*>* b = buildBattalions();
	std::vector<ArmyComponent*>* i = createIndividuals();
	std::vector<Supply*>* s = determineSupplies();

	return new Army(b, i, s); //(battalions, individuals, supplies)
}

Army* ArmyBuilder::getArmy() {
	return this->army;
}
