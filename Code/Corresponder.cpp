#include "Corresponder.h"
#include "Transporter.h"

void Corresponder ::regToTransport(Transporter *ammoLine, Transporter *medLine)
{
    ammoTransportLine = ammoLine;
    medicalTransportLine = medLine;

    ammoTransportLine->registerCorresponder(this);
    medicalTransportLine->registerCorresponder(this);
}