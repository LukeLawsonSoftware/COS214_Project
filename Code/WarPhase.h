#ifndef WARPHASE_H
#define WARPHASE_H
// #include "War.h"
class War;
#include <iostream>
class WarPhase
{

public:
	virtual void handleChange(War *war) = 0;
	double peaceChance;
};

#endif
