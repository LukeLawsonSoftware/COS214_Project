#ifndef WAR_H
#define WAR_H
#include "WarPhase.h"
#include "WarTheatre.h"

class War
{

private:
	WarTheatre *warTheatre;
	WarPhase *phase;
	bool isActive;

public:
	void setupTheatres();

	void changePhase();

	void startWarSim();

	void startWarGame();

	void stopWar();
};

#endif
