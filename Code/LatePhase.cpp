#include "LatePhase.h"

void LatePhase::handleChange(War *inWar)
{
	if (next != nullptr)
	{
		next->outputChange();
		inWar->setWarPhase(next);
	}
	else
	{
		inWar->setWarPhase(NULL);
		std::cout << "The war has concluded and peace is restored." << std::endl;
	}
}
