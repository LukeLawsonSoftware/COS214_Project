#ifndef ARMYBUILDER_H
#define ARMYBUILDER_H
#include "Army.h"

class ArmyBuilder
{

private:
	Army *army;

public:
	ArmyComponent **createIndividuals();

	ArmyComponent **buildBattalions();

	Supply **determineSupplies();

	Army *putArmyTogether();

	Army *getArmy();
};

#endif
