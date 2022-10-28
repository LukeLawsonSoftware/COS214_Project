#ifndef MIDPHASE_H
#define MIDPHASE_H
#include "LateCrisis.h"

class MidPhase : public WarPhase
{

public:
	MidPhase();
	/// @brief Sets Wars phase to LateCrisis.
	/// @author Thomas Blendulf (u21446131)
	/// @param War* passes in the war which must have its phase changed.
	void handleChange(War *);
};

#endif
