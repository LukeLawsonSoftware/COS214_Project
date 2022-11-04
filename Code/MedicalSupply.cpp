#include "MedicalSupply.h"
// #include "Supply.h"

MedicalSupply::MedicalSupply(int factoryLevel, int quantity) : Supply(quantity)
{
	// TODO - implement MedicalSupply::MedicalSupply

	double bonus = 0;
	srand((unsigned)time(0)); // to generate a different value each time

	// generate bonus based on factory level
	if (factoryLevel == 1)
	{
		bonus = (double)(10 + (rand() % 20)) / 100;
	}
	else if (factoryLevel > 1 && factoryLevel < 4)
	{
		bonus = (double)(20 + (rand() % 40)) / 100;
	}
	else
	{
		bonus = (double)(40 + (rand() % 80)) / 100;
	}

	setMedicalBonus(bonus * quantity);

	this->quantity = quantity;
	// throw "Not yet implemented";
}

int MedicalSupply::getMedicalBonus()
{
	return this->medicalBonus;
}

void MedicalSupply::setMedicalBonus(int bonus)
{
	if (bonus < 0)
		throw std::invalid_argument("Cannot set medical bonus as a negative value");
	this->medicalBonus = bonus;
}
