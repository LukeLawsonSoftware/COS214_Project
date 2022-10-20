#ifndef MEDICALSUPPLY_H
#define MEDICALSUPPLY_H
#include "Supply.h"

class MedicalSupply : public Supply
{

public:
	int medicalBonus;

	MedicalSupply(int factoryLevel, int quantity);

	int getMedicalBonus();

	void setMedicalBonus(int bonus);
};

#endif
