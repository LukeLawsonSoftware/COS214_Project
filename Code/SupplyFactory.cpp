#include "SupplyFactory.h"

SupplyFactory::SupplyFactory(int budget){
	level = 1;
	this->budget = budget;
	totalSpent = 0;
}

SupplyFactory::~SupplyFactory(){
	level = 0;
	totalSpent = 0;
	budget = 0;
}

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

std::string SupplyFactory :: getType(){
	return type;
}
