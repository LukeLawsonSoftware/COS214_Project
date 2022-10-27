#include "AmmoTransporter.h"
#include "AmmoSupply.h"
#include "MedicalSupply.h"
#include "Country.h"

AmmoTransporter :: AmmoTransporter(){}

AmmoTransporter :: ~AmmoTransporter(){
    //Deallocate memory used by the member variable
    std::list<Corresponder*>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
        delete (*it); //delete object
    }
}

void AmmoTransporter :: notify(Corresponder* c){
    AmmoSupply* ammoSupply = ( (Country*) c)->getNewAmmoSupply();

    //Run through corresponder list and update all supplies if it is necessary
    std::list<Corresponder*>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
        int A_size = (*it)->getAmmoSupplyCapacity();
        int A_capacity = (*it)->getAmmoSupplyCapacity();
        
        //check ammo supplies
        if (A_size < 0.30*A_capacity){
            //send suppplies
            (*it)->addNewAmmoSupplies(ammoSupply);
        }
    }
}