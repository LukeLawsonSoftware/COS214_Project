#ifndef LATEPHASE_H
#define LATEPHASE_H
#include "WarPhase.h"

class LatePhase : public WarPhase
{

public:
	LatePhase *next;
	/// @brief Sets Wars phase to next Late phase.
	/// @author Thomas Blendulf (u21446131)
	/// @param War* passes in the war which must have its phase changed.
	void handleChange(War *);
	virtual void outputChange(){};
};

#endif
