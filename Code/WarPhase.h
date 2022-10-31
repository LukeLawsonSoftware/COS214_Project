#ifndef WARPHASE_H
#define WARPHASE_H
// #include "War.h"
class War;
#include <iostream>
class WarPhase
{

protected:
	double peaceChance;

public:
	virtual void handleChange(War *war) = 0;
};

#endif
