#ifndef CORRESPONDER_H
#define CORRESPONDER_H

class Transporter;

/**
 * @class Corresponder Corresponder.h
 * 
 * This class is used to register a Country to its transport lines when the country object is instantiated.
 * 
 * @warning The transport lines are the only way a Country can transport supplies (AmmoSupply & MedicalSupply) to its armies.
 * 
 */

class Corresponder
{
protected:
	Transporter *medicalTransportLine;
	Transporter *ammoTransportLine;

public:
	/// @brief This function is used to register the Country to the ammo and medical transport lines.
	/// @param ammoTransportLine The AmmoTransporter for the country. We use this transport line to send ammo supplies to the country's army.
	/// @param medTransportLine The MedicalTransporter for the country. We use this transport line to send medical supplies to the country's army.
	/// @note It is possible to pass in NULL values for both argumenys but if done so then the Country would be in a great DISADVANTAGE to the other enemy countries.
	void regToTransport(Transporter *ammoTransportLine, Transporter *medTransportLine);
};

#endif
