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
    MedicalSupply* medSupply = ( (Country*) c)->getNewMedicalSupply();
    
    //Run through corresponder list and update all supplies if it is necessary
    std::list<Corresponder*>::iterator it;

    for (it = corresponderList.begin(); it != corresponderList.end(); ++it){
        Army* army = ( (Country*) (*it) )->getArmy();  //casting from Corresponder* to Country*

        int M_size = army->getMedicalSupplySize();     //the current size of the medical supply array
        int M_capacity = army->getMedSupplyCapacity(); //capacity is the maximum size of the medical supply array

        //check medical supplies
        if (M_size < 0.50*M_capacity){
            //send suppplies
            army->addNewMedicalSupplies(medSupply);
        }
    }
}