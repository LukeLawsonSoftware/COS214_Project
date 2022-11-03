#ifndef TRANSPORTER_H
#define TRANSPORTER_H
#include "Corresponder.h"
#include <list>
#include <iostream>

class Transporter{
	public:
		/// @brief Notify all Corresponder objects of the changes made by the parameter object. Implemented in derived classes.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to the Corresponder in which a changed has happened.
		virtual void notify(Corresponder *corresponder) = 0;
		
		/// @brief Register a Corresponder object by adding the passed in object to the list of corresponders.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to a Corresponder object which needs to be added to the list of corresponders.
		void registerCorresponder(Corresponder* corresponder);
	protected:
		std::list<Corresponder*> corresponderList; //we assume this list will only hold Army objects
};

#endif
