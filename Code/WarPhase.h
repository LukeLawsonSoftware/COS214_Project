#ifndef WARPHASE_H
#define WARPHASE_H
// #include "War.h"
class War;
#include <iostream>

/**
 * @class This class is used to specify in which phase the on going War is.
 * 
 */
class WarPhase
{

public:
	/// @brief This function will be implemented by the derived classes (EarlyPhase, MidPhase & LatePhase)
	/// @author Thomas Blendulf (u21446131)
	/// @param war The on going war which needs to change its phase
	virtual void handleChange(War *war) = 0;
	double peaceChance;
};

#endif
