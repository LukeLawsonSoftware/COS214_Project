#include "LatePhase.h"

void LatePhase::handleChange(War *inWar)
{
	if (next != nullptr)
	{
		inWar->setWarPhase(next);
	}
	else
	{
		inWar->setWarPhase(NULL);
	}
}
