#ifndef WAR_H
#define WAR_H
#include "WarPhase.h"
#include "WarTheatre.h"

class WarPhase; // forward Declaration

class War
{

private:
	WarTheatre *warTheatre; // should rather have an airTheatre, a seaTheatre and a landTheatre
	WarPhase *phase;
	bool isActive;

public:
	void setupTheatres();
	void setWarPhase(WarPhase *);
	WarTheatre *getLandTheatre();
	WarTheatre *getAirTheatre();
	WarTheatre *getSeaTheatre();

	void changePhase();

	void startWarSim();

	void startWarGame();

	void stopWar();
};

#endif
