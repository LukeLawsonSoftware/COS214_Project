#include "AmmoTransporter.h"
#include "AmmoSupply.h"
#include "MedicalSupply.h"
#include "Country.h"
// #include "Transporter.h"
#include "Corresponder.h"
#include "Army.h"

AmmoTransporter ::AmmoTransporter() {}

AmmoTransporter ::~AmmoTransporter()
{
    // Deallocate memory used by the member variable
    std::list<Corresponder *>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it)
    {
        delete (*it); // delete object
    }
}

void AmmoTransporter ::notify(Corresponder *c)
{
    AmmoSupply *ammoSupply = ((Country *)c)->getNewAmmoSupply();

    Army *army = ((Country *)c)->getArmy(); // casting from Corresponder* to Country*

    if (army == NULL)
        throw std::invalid_argument("Country has no army to which it can send Ammo supplies.");

    int Ammo_size = 5;     // army->getAmmoSupplySize();         // the current size of the ammo supply array
    int Ammo_capacity = 5; // army->getAmmoSupplyCapacity(); // capacity is the maximum size of the ammo supply array

    // check ammo supplies
    if (Ammo_size < 0.30 * Ammo_capacity)
    {
        // send suppplies
        army->addNewAmmoSupplies(ammoSupply);
    }

    //=================================================
    //  might use the code below at a later stage
    //=================================================
    // //Run through corresponder list and update all supplies if it is necessary
    // std::list<Corresponder*>::iterator it;

    // for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
    //     Army* army = ( (Country*) (*it) )->getArmy();  //casting from Corresponder* to Country*

    //     int Ammo_size = army->getAmmoSupplySize();     //the current size of the ammo supply array
    //     int Ammo_capacity = army->getAmmoSupplyCapacity(); //capacity is the maximum size of the ammo supply array

    //     //check ammo supplies
    //     if (Ammo_size < 0.30*Ammo_capacity){
    //         //send suppplies
    //         army->addNewAmmoSupplies(ammoSupply);
    //     }
    // }
}