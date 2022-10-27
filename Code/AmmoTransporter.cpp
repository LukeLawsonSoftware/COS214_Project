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
        Army* army = ( (Country*) (*it) )->getArmy();  //casting from Corresponder* to Country*

        int Ammo_size = army->getAmmoSupplySize();     //the current size of the ammo supply array
        int Ammo_capacity = army->getAmmoSupplyCapacity(); //capacity is the maximum size of the ammo supply array
        
        //check ammo supplies
        if (Ammo_size < 0.30*Ammo_capacity){
            //send suppplies
            army->addNewAmmoSupplies(ammoSupply);
        }
    }
}