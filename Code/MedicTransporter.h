#ifndef MEDICTRANSPORTER_H
#define MEDICTRANSPORTER_H
#include "Transporter.h"
#include "Corresponder.h"
#include <list>

class MedicTransporter : public Transporter{
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
		virtual void notify(Corresponder *corresponder);
	
	private:
		std::list<Corresponder*> corresponderList;
};

#endif
