#include "Vehicle.h"

Vehicle::Vehicle(int powerRating)
{
	this->armourRating = powerRating * 10;
	this->weaponClass = powerRating;
}

void Vehicle::addMember(ArmyComponent *newMember)
{
	throw "Cannot add ArmyComponent to a Vehicle object";
}

double Vehicle::getVehicleCost(){
	return vehicleCost;
}
