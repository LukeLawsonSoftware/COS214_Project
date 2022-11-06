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

	/// @brief This function will be implemented by the derived classes. (EarlyCrisis, EarlyOpenConflict & EarlyPeace)
    /// @author Thomas Blendulf (u21446131)
	virtual void outputChange(){};
};

#endif
