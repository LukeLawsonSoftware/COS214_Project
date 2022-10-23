#ifndef TRANSPORTER_H
#define TRANSPORTER_H
#include "Corresponder.h"

class Transporter{
	public:
		/// @brief Notify all Corresponder objects of the changes made by the parameter object. Implemented in derived classes.
		/// @author Reuben Jooste (u21457060)
		/// @param corresponder pointer to the Corresponder in which a changed has happened.
		virtual void notify(Corresponder *corresponder);
};

#endif
