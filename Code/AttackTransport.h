#ifndef ATTACKTRANSPORT_H
#define ATTACKTRANSPORT_H
#include "Transporter.h"
#include "Command.h"

class AttackTransport : public Command
{

public:
	Transporter *transport;

	void execute();
};

#endif
