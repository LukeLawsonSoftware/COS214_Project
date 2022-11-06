#ifndef LATEOPENCONFLICT_H
#define LATEOPENCONFLICT_H
#include "LateUnstablePeace.h"

class LateOpenConflict : public LatePhase
{
public:
    /// @brief Sets next to LateUnstablePeace.
    /// @author Thomas Blendulf (u21446131)
    LateOpenConflict();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif
