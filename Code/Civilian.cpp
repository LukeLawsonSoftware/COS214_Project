#include "Civilian.h"

Civilian::Civilian()
{
	designation = "citizen";
}

Civilian::Civilian(std::string Designation)
{
	designation = Designation;
}

NonCombatEntity* Civilian::clone() {
	return new Civilian(designation);
}

void Civilian::setDesignation(std::string Designation)
{
	designation = Designation;
}

std::string Civilian::getDesignation()
{
	return designation;
}

