#ifndef EARLYPHASE_H
#define EARLYPHASE_H
#include "WarPhase.h"

class EarlyPhase : public WarPhase
{

public:
	EarlyPhase *next;

	void handleChange();
};

#endif
