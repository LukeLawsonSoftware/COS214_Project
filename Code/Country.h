#ifndef COUNTRY_H
#define COUNTRY_H
#include "EconomicState.h"
#include "Corresponder.h"
#include "UnitFactory.h"
#include "SupplyFactory.h"
#include "Army.h"
#include <vector>
#include <string>

class Country : public Corresponder
{

private:
	double gdp;
	static std::vector<std::vector<Country *>> alliances;
	EconomicState *ecoState;
	UnitFactory **unitFactories;
	SupplyFactory **supplyFactories;

public:
	void earnGDP(double gdpEarned);

	void spendGDP(double gdpSpent);

	void takeTurn();

	void formAlliance(Country *newAlly);

	void raiseArmy();

	void upgradeUnitFactory();

	void upgradeSupplyFactory();

	void changeArmyStrategy(Army *army, std::string newStrategy);

	void attackTransport(Army *army, Transporter *transport);

	void surrender();

	void sendSupplies(double budget, Corresponder *corresponder);
};

#endif
