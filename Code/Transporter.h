#ifndef TRANSPORTER_H
#define TRANSPORTER_H
#include "Corresponder.h"
#include <list>
#include <iostream>

/**
 * @class Transporter Transporter.h
 * 
 * This class is used to create transport lines for a Country.
 * 
 * There are two types of transport lines:
 * - AmmoTransporter : the ammo transport line which is used by the Country to send suppplies to its armies.
 * - MedicTransporter : the medical transport line which is used by the Country to send medical supplies to its armies
 * 
 * @warning If a country does not have a ammo transport line it cannot send any ammo supplies to its army.
 * @warning If a country does not have a medical transport line it cannot send any medcial supplies to its army meaning the army will not be able to recuperate during the War.
 * 
 */

class Transporter{
	public:
		/// @brief Notify all Corresponder objects of the changes made by the parameter object. Implemented in derived classes.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to the Corresponder in which a changed has happened.
		virtual void notify(Corresponder *corresponder) = 0;
		
		/// @brief Register a Corresponder object by adding the passed in object to the list of corresponders.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to a Corresponder object which needs to be added to the list of corresponders.
		/// @note This function allows the Transport lines to know which Country is currently sending supplies to the armies.
		void registerCorresponder(Corresponder* corresponder);
	protected:
		std::list<Corresponder*> corresponderList; //we assume this list will only hold Army objects
};

#endif
