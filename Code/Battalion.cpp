#include "Battalion.h"
// #include "ArmyComponent.h"

int Battalion::calculateAirOffense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateAirOffense();
	}
	return sum;
}

int Battalion::calculateAirDefense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateAirDefense();
	}
	return sum;
}

int Battalion::calculateSeaOffense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateSeaOffense();
	}
	return sum;
}

int Battalion::calculateSeaDefense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateSeaDefense();
	}
	return sum;
}

int Battalion::calculateLandOffense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateLandOffense();
	}
	return sum;
}

int Battalion::calculateLandDefense()
{
	int sum = 0;
	for (int i = 0; i < this->members.size(); i++)
	{
		sum += members.at(i)->calculateLandDefense();
	}
	return sum;
}

void Battalion::addMember(ArmyComponent *newMember)
{
	this->members.push_back(newMember);
}
