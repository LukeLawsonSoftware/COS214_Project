#include "Transporter.h"

void Transporter :: registerCorresponder(Corresponder* c){
    corresponderList.push_back(c);
}