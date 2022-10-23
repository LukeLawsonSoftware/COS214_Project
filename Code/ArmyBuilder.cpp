#include "ArmyBuilder.h"

ArmyBuilder :: ArmyBuilder(std::string t, std::vector<UnitFactory*>* u, std::vector<SupplyFactory*>* s){
	type = t;
	unitFactories = u;
	supplyFactories = s;
}

ArmyComponent** ArmyBuilder::createIndividuals() {
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
					}
				}
				else{
					++it;//go to the next factory
				}
			} 

		}
	}
}

ArmyComponent** ArmyBuilder::buildBattalions() {
	// TODO - implement ArmyBuilder::buildBattalions
	
}

Supply** ArmyBuilder::determineSupplies() {
	// TODO - implement ArmyBuilder::determineSupplies
	
}

Army* ArmyBuilder::putArmyTogether() { //We will assume each army will be the same size
	/*Army will consist of: (if we have the budget)
		50 soldiers
		20 vehicles
		2 battalions
		(these values may be changed)
	*/
	// TODO - implement ArmyBuilder::putArmyTogether
	ArmyComponent** b = buildBattalions();
	ArmyComponent** i = createIndividuals();
	Supply** s = determineSupplies();

	return new Army(b, i, s); //(battalions, individuals, supplies)
}

Army* ArmyBuilder::getArmy() {
	return this->army;
}
