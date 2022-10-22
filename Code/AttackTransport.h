#ifndef ATTACKTRANSPORT_H
#define ATTACKTRANSPORT_H
#include "Transporter.h"
#include "Command.h"

class AttackTransport : public Command
{

public:
	Transporter *transport;
	/// @brief sets the Transporter to be attacked by the army.
	/// @author Thomas Blendulf(u21446131)
	/// @param Transporter containing transporter target to be updated to.
	void setTransport(Transporter *);
	/// @brief executes the attack on the Transporter.
	/// @author Thomas Blendulf(u21446131)
	void execute();
};

#endif
