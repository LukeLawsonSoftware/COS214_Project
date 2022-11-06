#include "MilitaryCommander.h"
#include "ChangeStrategy.h"
#include "AttackTransport.h"
#include "MoveIntoTheatre.h"
#include "WarTheatre.h"
#include "Transporter.h"

MilitaryCommander::MilitaryCommander()
{
	_changeStrategy = new ChangeStrategy();
	_enterTheatre = new MoveIntoTheatre();
	_attackTransport = new AttackTransport();
}

void MilitaryCommander::changeStrategy()
{
	_changeStrategy->execute();
}

void MilitaryCommander::setStrategy(Army *army, std::string newStrategy)
{
	_changeStrategy->setStrategy(newStrategy);
	_changeStrategy->setArmy(army);
}

void MilitaryCommander::enterTheatre()
{
	_enterTheatre->execute();
}

void MilitaryCommander::setTheatreTarget(Army *army, WarTheatre *theatreTarget)
{
	_enterTheatre->setArmy(army);
	_enterTheatre->setTheatre(theatreTarget);
}

void MilitaryCommander::attackTransport()
{
	_attackTransport->execute();
}

void MilitaryCommander::setTransportTarget(Country *transportTarget, Army *army)
{
	_attackTransport->setArmy(army);
	_attackTransport->setTransport(transportTarget);
}
