#ifndef CORRESPONDER_H
#define CORRESPONDER_H
#include "Transporter.h"

class Corresponder{
	private:
		Transporter* medicalTransportLine;
		Transporter* ammoTransportLine;
	public:
		void regToTransport(Transporter* ammoTransportLine, Transporter* medTransportLine);
};

#endif
