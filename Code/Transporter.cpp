#include "Transporter.h"

void Transporter :: registerCorresponder(Corresponder* c){
    //test if parameter is not null
    if (c == NULL) throw std::invalid_argument("Cannot register object of type NULL to corresponderList vector.");
    //else add the object
    corresponderList.push_back(c);
}