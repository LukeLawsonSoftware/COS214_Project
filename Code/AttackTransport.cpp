#include "AttackTransport.h"

void AttackTransport::execute()
{
	army->attackTransport(transport);
}

void AttackTransport::setTransport(Country *in)
{
	transport = in;
}