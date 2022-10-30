#ifndef EARLYUNSTABLEPEACE_H
#define EARLYUNSTABLEPEACE_H
#include "EarlyOpenConflict.h"

class EarlyUnstablePeace : public EarlyPhase
{
public:
    /// @brief Sets next to EarlyOpenConflict and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyUnstablePeace();
    void outputChange();
};

#endif
