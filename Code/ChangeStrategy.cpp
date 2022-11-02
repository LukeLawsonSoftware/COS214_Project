#include "ChangeStrategy.h"
// #include "Command.h"
#include "Army.h"

ChangeStrategy::ChangeStrategy() {}

void ChangeStrategy::execute()
{
	army->changeStrategy(newStrategy);
}

void ChangeStrategy::setStrategy(std::string in)
{
	newStrategy = in;
}
