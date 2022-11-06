#ifndef MEDICTRANSPORTER_H
#define MEDICTRANSPORTER_H
#include "Transporter.h"
#include <iostream>

class Corresponder;

/**
 * @class MedicTransporter MedicTransporter.h
 * 
 * This class is derived from the Trnasporter class.
 * - We use this class to showcase the transport of medical supplies which a Country sends to its Army.
 * - This class notifies all armies of a country that the country has sent medical supplies to it.
 * @warning If this transport line is destroyed by an enemy country, the country will not be able to send any medical supplies. Thus being in a great disadvantage.
 */

class MedicTransporter : public Transporter
{
public:
	/// @brief Constructor for the MedicTransport class used to instantiate the object.
	/// @author Reuben Jooste (u21457060)
	MedicTransporter();

	/// @brief Destructor for the MedicTransport class used to deallocate the dynamic memory used by the member variable corresponderList.
	/// @author Reuben Jooste (u21457060)
	virtual ~MedicTransporter();

	/// @brief Notify all Corresponder objects in the corresponderList variable.
	/// @author Reuben Jooste (u21457060)
	/// @param corresponder pointer to the Corresponder in which a changed has happened.
	/// @note If the parameter is NULL the function would simply throw an exception and terminate.
	virtual void notify(Corresponder *corresponder);
};

#endif
