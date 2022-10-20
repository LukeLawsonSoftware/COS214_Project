#ifndef TRANSPORTER_H
#define TRANSPORTER_H
#include "Corresponder.h"

class Transporter
{

public:
	virtual void notify(Corresponder *corresponder);
};

#endif
