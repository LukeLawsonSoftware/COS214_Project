#include "ArmyDirector.h"
#include "ArmyBuilder.h"

ArmyDirector ::ArmyDirector(ArmyBuilder *b)
{
	builder = b;
}

void ArmyDirector::constructArmy()
{
	// check if we have a builder
	if (builder == NULL) throw std::invalid_argument("Cannot build army because there is no ArmyBuilder");

	//else command builder to create the different parts of the army
	builder->createIndividuals();
	builder->buildBattalions();
	builder->determineSupplies();
	builder->putArmyTogether();
}
