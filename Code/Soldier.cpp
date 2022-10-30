#include "Soldier.h"

Soldier::Soldier(int powerRating)
{
	this->trainingLevel = powerRating;
}

void Soldier::addMember(ArmyComponent *newMember)
{
	throw std::invalid_argument("Cannot add ArmyComponent to a Soldier object");
	// throw "Cannot add ArmyComponent to a Soldier object";
}

double Soldier::getSoldierCost()
{
	return soldierCost;
}
