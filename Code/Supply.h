#ifndef SUPPLY_H
#define SUPPLY_H

class Supply
{
public:
	/// @brief Class constructor for the Supply class that wil initialize the quantity member variable.
	/// @author Arno Jooste (u21457451)
	/// @param quantity The amount that is produced by the factory.
	Supply(int quantity)
	{
		this->quantity = quantity;
	}

	/// @brief Virtual Class destructor to reset member variable
	/// @author Arno Jooste (u21457451)
	virtual ~Supply()
	{
		quantity = 0;
	};

protected:
	int quantity;
};

#endif
