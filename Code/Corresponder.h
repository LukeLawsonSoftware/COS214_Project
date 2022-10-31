#ifndef CORRESPONDER_H
#define CORRESPONDER_H

class Transporter;

class Corresponder
{
protected:
	Transporter *medicalTransportLine;
	Transporter *ammoTransportLine;

public:
	void regToTransport(Transporter *ammoTransportLine, Transporter *medTransportLine);
};

#endif
