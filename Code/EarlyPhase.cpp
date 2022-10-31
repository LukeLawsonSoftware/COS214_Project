#include "EarlyPhase.h"
#include "War.h"
#include "MidPhase.h"

void EarlyPhase::handleChange(War *inWar)
{
	if (next != NULL)
	{
		next->outputChange();
		inWar->setWarPhase(next);
	}
	else
	{
		inWar->setWarPhase(new MidPhase());
	}
}
