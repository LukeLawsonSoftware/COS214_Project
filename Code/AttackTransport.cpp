#include "AttackTransport.h"

void AttackTransport::execute()
{
	army->attackTransport(transport);
}

void AttackTransport::setTransport(Transporter *in)
{
	transport = in;
}