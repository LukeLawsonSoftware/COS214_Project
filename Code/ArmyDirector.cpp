#include "ArmyDirector.h"
#include "ArmyBuilder.h"

ArmyDirector ::ArmyDirector(ArmyBuilder *b)
{
	builder = b;
}

void ArmyDirector::constructArmy()
{
	// TODO - implement ArmyDirector::constructArmy
	builder->createIndividuals();
	builder->buildBattalions();
	builder->determineSupplies();
	builder->putArmyTogether();
}
