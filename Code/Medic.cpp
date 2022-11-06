#include "Medic.h"
#include <ctime>
#include <cstdlib>

Medic::Medic()
{
	static int seeder = 41819;
	seeder += 3121;
	srand((unsigned)time(0) + seeder); // to generate a different value each time
	healing = (rand() % 10 + 1);
}

Medic::Medic(int Healing)
{
	healing = Healing;
}

NonCombatEntity *Medic::clone()
{
	return new Medic(healing);
}

int Medic::getHealing()
{
	return healing;
}