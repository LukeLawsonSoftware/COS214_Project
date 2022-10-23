#include "ArmyDirector.h"

ArmyDirector :: ArmyDirector(ArmyBuilder* b){
	builder = b;
}

void ArmyDirector::constructArmy() {
	// TODO - implement ArmyDirector::constructArmy
	builder->putArmyTogether();
}
