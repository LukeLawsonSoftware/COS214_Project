#ifndef SUPPLYFACTORY_H
#define SUPPLYFACTORY_H
#include "Supply.h"

class SupplyFactory
{

private:
	int budget;

protected:
	double totalSpent;

private:
	int level;

public:
	virtual Supply *makeSupply() = 0;

	void upgrade();

	void setBudget(int newBudget);

	int getBudget();

	int getLevel();

	int getTotalSpent();
};

#endif
