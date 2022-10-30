#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "NonCombatEntity.h"

class Civilian : public NonCombatEntity
{
	// string designation : is a refugee or a citizen
public:
	NonCombatEntity *clone();
};

#endif
