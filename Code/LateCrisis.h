#ifndef LATECRISIS_H
#define LATECRISIS_H
#include "LateOpenConflict.h"

class LateCrisis : public LatePhase
{
public:
    /// @brief Sets next to LateOpenConflict.
    /// @author Thomas Blendulf (u21446131)
    LateCrisis();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif
