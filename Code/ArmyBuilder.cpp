#include "ArmyBuilder.h"
#include <vector>

ArmyComponent** ArmyBuilder::createIndividuals() {
	// TODO - implement ArmyBuilder::createIndividuals
	std::vector<ArmyComponent*> *smallUnits;
	
	switch(type[0]){
		case 'L':{ //construct Land Units
			
		}
	}
}

ArmyComponent** ArmyBuilder::buildBattalions() {
	// TODO - implement ArmyBuilder::buildBattalions
	
}

Supply** ArmyBuilder::determineSupplies() {
	// TODO - implement ArmyBuilder::determineSupplies
	
}

Army* ArmyBuilder::putArmyTogether() {
	// TODO - implement ArmyBuilder::putArmyTogether
	ArmyComponent** b = buildBattalions();
	ArmyComponent** i = createIndividuals();
	Supply** s = determineSupplies();

	return new Army(b, i, s); //(battalions, individuals, supplies)
}

Army* ArmyBuilder::getArmy() {
	return this->army;
}
