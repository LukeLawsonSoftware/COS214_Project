#ifndef ARMY_H
#define ARMY_H
#include "ArmyComponent.h"
#include "AmmoSupply.h"
#include "Corresponder.h"
#include "ArmyStrategy.h"
#include "MedicalSupply.h"

class Army : public Corresponder
{

private:
	ArmyComponent *army;
	AmmoSupply *ammoSupply;
	MedicalSupply *medicalSupply;
	ArmyStrategy *currentStrategy;

public:
	void applyStrategyBonus();

	void recuperate();
};

#endif
