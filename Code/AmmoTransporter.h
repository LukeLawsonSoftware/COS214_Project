#ifndef AMMOTRANSPORTER_H
#define AMMOTRANSPORTER_H
#include "Transporter.h"
#include "Corresponder.h"

class AmmoTransporter : public Transporter
{

public:
	Corresponder *corresponderList;

	virtual void notify(Corresponder *corresponder) = 0;
};

#endif
