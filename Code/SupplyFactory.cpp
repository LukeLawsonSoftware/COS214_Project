#include "SupplyFactory.h"

void SupplyFactory::upgrade() {
	// TODO - implement SupplyFactory::upgrade

	setBudget( getBudget()*1.5 );//increase budget by 50%

	level++;

	// throw "Not yet implemented";
}

void SupplyFactory::setBudget(int newBudget) {
	this->budget = newBudget;
}

int SupplyFactory::getBudget() {
	return this->budget;
}

int SupplyFactory::getLevel() {
	return this->level;
}

int SupplyFactory::getTotalSpent() {
	// TODO - implement SupplyFactory::getTotalSpent

	return totalSpent;

	// throw "Not yet implemented";
}
