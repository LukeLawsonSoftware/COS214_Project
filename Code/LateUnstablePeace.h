#ifndef LATEUNSTABLEPEACE_H
#define LATEUNSTABLEPEACE_H
#include "LatePeace.h"

class LateUnstablePeace : public LatePhase
{
public:
    /// @brief Sets next to null.
    /// @author Thomas Blendulf (u21446131)
    LateUnstablePeace();

    /// @brief This function just shows when there was a change to the current WarPhase.
    /// @author Thomas Blendulf (u21446131)
    void outputChange();
};

#endif
