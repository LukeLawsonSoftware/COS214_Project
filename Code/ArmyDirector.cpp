#include "ArmyDirector.h"
#include "ArmyBuilder.h"

ArmyDirector ::ArmyDirector(ArmyBuilder *b)
{
	builder = b;
}

void ArmyDirector::constructArmy()
{
	if (builder == NULL)
		throw std::invalid_argument("Cannot build army because there is no ArmyBuilder");
	// TODO - implement ArmyDirector::constructArmy
	builder->createIndividuals();
	builder->buildBattalions();
	builder->determineSupplies();
	builder->putArmyTogether();
}
