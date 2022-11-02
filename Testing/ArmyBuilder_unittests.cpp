#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "ArmyBuilder.h"
#include <iostream>

namespace{
    //Test the setIndividuals() to check if it actually adds objects
    TEST(Set_individuals, AddedItems){
        std::vector<UnitFactory*> *factories = new std::vector<UnitFactory*>;
        factories->push_bacK( new LandFactory(1000000000,2,"Land") );
        ArmyBuilder* builder = new ArmyBuilder("Land",factories,NULL); //not testing the supplies thus it can be NULL

        //build vector of armyComponents manually
        std::vector<ArmyComponent*> *indv;
        indv->push_back(new Soldier(1));
        indv->push_back(new Soldier(2));
        indv->push_back(new Vehicle(3));
        indv->push_back(new Vehicle(1));
        indv->push_back(new Soldier(5));
        indv->push_back(new Soldier(4));
        indv->push_back(new Soldier(2));
        indv->push_back(new Vehicle(3));
        indv->push_back(new Soldier(4));

        //set the individuals
        builder->setIndividuals(indv);

        std::vector<ArmyComponent*> *result = builder->getIndividuals();

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete indv;
        delete result;
        delete factories;
    }

    //Test the setBattalions() to check if it actually adds objects
    TEST(Set_Battalions, AddedItems){
        std::vector<UnitFactory*> *factories = new std::vector<UnitFactory*>;
        factories->push_bacK( new AirFactory(1000000000,3,"Air") );
        ArmyBuilder* builder = new ArmyBuilder("Air",factories,NULL); //not testing the supplies thus it is NULL

        //build vector of armyComponents manually
        std::vector<ArmyComponent*> *battalion;
        battalion->push_back(new Soldier(1));
        battalion->push_back(new Soldier(2));
        battalion->push_back(new Vehicle(3));
        battalion->push_back(new Vehicle(1));
        battalion->push_back(new Soldier(5));
        battalion->push_back(new Soldier(4));
        battalion->push_back(new Soldier(2));
        battalion->push_back(new Vehicle(3));
        battalion->push_back(new Soldier(4));

        //set the Battalions
        builder->setBattalions(battalion);

        std::vector<ArmyComponent*> *result = builder->getBattalions();

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete battalion;
        delete result;
        delete factories;
    }

    //Test the setSupplies() to check if it actually adds objects
    TEST(Set_Supplies, AddedItems){
        std::vector<SupplyFactory*> *factories = new std::vector<SupplyFactory*>;
        factories->push_bacK( new AmmoFactory(1000000000,"Ammo") );
        ArmyBuilder* builder = new ArmyBuilder("Sea",NULL,factories); //not testing the unitfactories thus it is NULL

        //build vector of Supply objects manually
        std::vector<Supply*> *supplies;
        supplies->push_back(new Soldier(1));
        supplies->push_back(new Soldier(2));
        supplies->push_back(new Vehicle(3));
        supplies->push_back(new Vehicle(1));
        supplies->push_back(new Soldier(5));
        supplies->push_back(new Soldier(4));
        supplies->push_back(new Soldier(2));
        supplies->push_back(new Vehicle(3));
        supplies->push_back(new Soldier(4));

        //set the Supplies
        builder->setSupplies(supplies);

        std::vector<Supply*> *result = builder->getSupplies();

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete supplies;
        delete result;
        delete factories;
    }

    //Test the getIndividuals() to check if it does not return NULL
    TEST(Get_individuals, ReceivedItems){
        std::vector<UnitFactory*> *factories = new std::vector<UnitFactory*>;
        factories->push_bacK( new LandFactory(1000000000,2,"Land") );
        ArmyBuilder* builder = new ArmyBuilder("Land",factories,NULL); //not testing the supplies thus it can be NULL

        //build vector of armyComponents manually
        std::vector<ArmyComponent*> *indv;
        indv->push_back(new Soldier(1));
        indv->push_back(new Soldier(2));
        indv->push_back(new Vehicle(3));
        indv->push_back(new Vehicle(1));
        indv->push_back(new Soldier(5));
        indv->push_back(new Soldier(4));
        indv->push_back(new Soldier(2));
        indv->push_back(new Vehicle(3));
        indv->push_back(new Soldier(4));

        //set the individuals
        builder->setIndividuals(indv);

        std::vector<ArmyComponent*> *result = builder->getIndividuals();

        //Test: Does getter return NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete indv;
        delete result;
        delete factories;
    }

    //Test the getBattalions() to check if it does not return NULL
    TEST(Get_Battalions, ReceivedItems){
        std::vector<UnitFactory*> *factories = new std::vector<UnitFactory*>;
        factories->push_bacK( new AirFactory(1000000000,3,"Air") );
        ArmyBuilder* builder = new ArmyBuilder("Air",factories,NULL); //not testing the supplies thus it is NULL

        //build vector of armyComponents manually
        std::vector<ArmyComponent*> *battalion;
        battalion->push_back(new Soldier(1));
        battalion->push_back(new Soldier(2));
        battalion->push_back(new Vehicle(3));
        battalion->push_back(new Vehicle(1));
        battalion->push_back(new Soldier(5));
        battalion->push_back(new Soldier(4));
        battalion->push_back(new Soldier(2));
        battalion->push_back(new Vehicle(3));
        battalion->push_back(new Soldier(4));

        //set the Battalions
        builder->setBattalions(battalion);

        std::vector<ArmyComponent*> *result = builder->getBattalions();

        //Test: Does getter return NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete battalion;
        delete result;
        delete factories;
    }

    //Test the getSupplies() to check if it does not return NULL
    TEST(Get_Supplies, ReceivedItems){
        std::vector<SupplyFactory*> *factories = new std::vector<SupplyFactory*>;
        factories->push_bacK( new AmmoFactory(1000000000,"Ammo") );
        ArmyBuilder* builder = new ArmyBuilder("Sea",NULL,factories); //not testing the unitfactories thus it is NULL

        //build vector of Supply objects manually
        std::vector<Supply*> *supplies;
        supplies->push_back(new Soldier(1));
        supplies->push_back(new Soldier(2));
        supplies->push_back(new Vehicle(3));
        supplies->push_back(new Vehicle(1));
        supplies->push_back(new Soldier(5));
        supplies->push_back(new Soldier(4));
        supplies->push_back(new Soldier(2));
        supplies->push_back(new Vehicle(3));
        supplies->push_back(new Soldier(4));

        //set the Supplies
        builder->setSupplies(supplies);

        std::vector<Supply*> *result = builder->getSupplies();

        //Test: Does getter return NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete supplies;
        delete result;
        delete factories;
    }
}