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
	std::string type;

public:
	void applyStrategyBonus();
	void recuperate();
	void addNewAmmoSupplies(AmmoSupply *);
	void addNewMedicalSupplies(MedicalSupply *);

	// these each need to have output telling the user whats happening
	void changeStrategy(std::string);
	void setBattleField(WarTheatre *); // theatre->add(this)
	void attackTransport(Country *);

	std::string getType();
};

#endif
