#ifndef NONCOMBATENTITY_H
#define NONCOMBATENTITY_H

class NonCombatEntity
{

public:
	virtual NonCombatEntity *clone() = 0;

	// a number of non combat entities exist in a war theatre and do different things
	//  civilians have a designation (citizen or refugee) and some die at the end of each round in a theatre
	// medics can also die and at the end of each theatre round heal each army

	// i have added specific attributes and operations to add to each class

	// FYI: you might need to add copy constructors/parameterised constructors to be able to clone

	// The killing of NonCombatEntities will be managed in the WarTheeatre class
};

#endif
