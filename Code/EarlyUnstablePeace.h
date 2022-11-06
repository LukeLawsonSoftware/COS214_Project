#ifndef EARLYUNSTABLEPEACE_H
#define EARLYUNSTABLEPEACE_H
#include "EarlyOpenConflict.h"

class EarlyUnstablePeace : public EarlyPhase
{
public:
    /// @brief Sets next to EarlyOpenConflict and peaceChance.
    /// @author Thomas Blendulf (u21446131)
    EarlyUnstablePeace();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif
