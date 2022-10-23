#include "MedicTransporter.h"
#include "AmmoSupply.h"
#include "MedicalSupply.h"
#include "Country.h"

MedicTransporter :: MedicTransporter(){}

MedicTransporter :: ~MedicTransporter(){
    //Deallocate memory used by the member variable
    std::list<Corresponder*>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
        delete (*it); //delete object
    }
}

void MedicTransporter :: notify(Corresponder* c){
    MedicalSupply* medSupply = (Country) c->getNewMedicalSupplies();
    
    //Run through corresponder list and update all supplies if it is necessary
    std::list<Corresponder*>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
        int M_size = (*it)->getMedicalSupplySize();
        int M_capacity = (*it)->getMedSupplyCapacity();

        //check medical supplies
        if (M_size < 0.50*M_capacity){
            //send suppplies
            (*it)->addNewMedicalSupplies(medSupply);
        }
    }
}