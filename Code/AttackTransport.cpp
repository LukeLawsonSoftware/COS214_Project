#include "AttackTransport.h"
#include "Transporter.h"
#include "Army.h"
// #include "Command.h"

void AttackTransport::execute()
{
	army->attackTransport(transport);
}

void AttackTransport::setTransport(Country *in)
{
	transport = in;
}