#ifndef LATEPHASE_H
#define LATEPHASE_H
#include "WarPhase.h"

class LatePhase : public WarPhase
{

public:
	LatePhase *next;

	void handleChange();
};

#endif
