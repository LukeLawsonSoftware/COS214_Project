#include "Soldier.h"

Soldier::Soldier(int powerRating)
{
	this->trainingLevel = powerRating;
}

void Soldier::addMember(ArmyComponent *newMember)
{
	throw "Cannot add ArmyComponent to a Soldier object";
}

double Soldier::getSoldierCost(){
	return soldierCost;
}
