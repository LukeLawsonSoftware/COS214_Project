#ifndef EARLYPHASE_H
#define EARLYPHASE_H
#include "WarPhase.h"
class War;
class EarlyPhase : public WarPhase
{

public:
	EarlyPhase *next;
	/// @brief Sets Wars phase to next early phase or MidPhase.
	/// @author Thomas Blendulf (u21446131)
	/// @param War* passes in the war which must have its phase changed.
	void handleChange(War *);
	virtual void outputChange(){};
};

#endif
