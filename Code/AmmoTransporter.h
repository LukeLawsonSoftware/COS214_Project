#ifndef AMMOTRANSPORTER_H
#define AMMOTRANSPORTER_H

#include "Transporter.h"
class Corresponder;

class AmmoTransporter : public Transporter
{
public:
	/// @brief Constructor for the AmmoTransporter class used to instantiate the object.
	/// @author Reuben Jooste (u21457060)
	AmmoTransporter();

	/// @brief Destructor for the AmmoTransporter class used to deallocate the dynamic memory used by the member variable corresponderList.
	/// @author Reuben Jooste (u21457060)
	virtual ~AmmoTransporter();

	/// @brief Notify all Corresponder objects in the corresponderList variable.
	/// @author Reuben Jooste (u21457060)
	/// @param corresponder pointer to the Corresponder in which a changed has happened.
	virtual void notify(Corresponder *corresponder);
};

#endif
