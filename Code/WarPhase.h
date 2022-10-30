#ifndef WARPHASE_H
#define WARPHASE_H
#include "War.h"
#include <iostream>
class WarPhase
{

protected:
	double peaceChance;

public:
	virtual void handleChange(War *) = 0;
};

#endif
