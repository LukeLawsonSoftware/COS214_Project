#ifndef WARPHASE_H
#define WARPHASE_H
#include "War.h"
class WarPhase
{

protected:
	double peaceChance;

public:
	virtual void handleChange(War *) = 0;
};

#endif
