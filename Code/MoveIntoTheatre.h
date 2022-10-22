#ifndef MOVEINTOTHEATRE_H
#define MOVEINTOTHEATRE_H
#include "Command.h"
#include "WarTheatre.h"

class MoveIntoTheatre : public Command
{

public:
	WarTheatre *theatre;
	/// @brief sets the war theatre to be executed by the commmand pattern.
	/// @author Thomas Blendulf(u21446131)
	/// @param WarTheatre containing theatre to be updated to.
	void setTheatre(WarTheatre *);

	/// @brief sets the stored armies war theatre to fight in.
	/// @author Thomas Blendulf(u21446131)
	void execute();
};

#endif
