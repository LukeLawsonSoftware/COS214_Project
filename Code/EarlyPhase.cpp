#include "EarlyPhase.h"

void EarlyPhase::handleChange(War *inWar)
{
	if (next != nullptr)
	{
		inWar->setWarPhase(next);
	}
	else
	{
		inWar->setWarPhase(new MidPhase());
	}
}
