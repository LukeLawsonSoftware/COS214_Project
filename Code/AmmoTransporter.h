#ifndef AMMOTRANSPORTER_H
#define AMMOTRANSPORTER_H

#include "Transporter.h"
#include <iostream>

class Corresponder;

/**
 * @class AmmoTransporter AmmoTransporter.h
 * 
 * This class is derived from the Trnasporter class.
 * - We use this class to showcase the transport of ammo supplies which a Country sends to its Army.
 * - This class notifies all armies of a country that the country has sent ammo supplies to it.
 * @warning If this transport line is destroyed by an enemy country, the country will not be able to send any ammo supplies. Thus being in a great disadvantage.
 */

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
	/// @note If the parameter is NULL the function would simply throw an exception and terminate.
	virtual void notify(Corresponder *corresponder);
};

#endif
