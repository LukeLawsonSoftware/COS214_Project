#ifndef MEDICTRANSPORTER_H
#define MEDICTRANSPORTER_H
#include "Transporter.h"
#include "Corresponder.h"

class MedicTransporter : public Transporter{
	public:
		/// @brief Notify all Corresponder objects in the corresponderList variable.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to the Corresponder in which a changed has happened. 
		virtual void notify(Corresponder *corresponder);
	
	private:
		Corresponder *corresponderList;
};

#endif
