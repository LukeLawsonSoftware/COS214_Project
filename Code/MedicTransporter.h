#ifndef MEDICTRANSPORTER_H
#define MEDICTRANSPORTER_H
#include "Transporter.h"
#include "Corresponder.h"

class MedicTransporter : public Transporter
{

public:
	Corresponder *corresponderList;

	virtual void notify(Corresponder *corresponder) = 0;
};

#endif
