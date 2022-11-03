#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/ArmyBuilder.h"
#include "../Code/ArmyDirector.h"
#include "../Code/Supply.h"
#include "../Code/ArmyComponent.h"
#include "../Code/Soldier.h"
#include "../Code/Vehicle.h"
#include "../Code/AmmoSupply.h"
#include "../Code/MedicalSupply.h"
#include "../Code/LandUnit.h"
#include "../Code/LandVehicle.h"

#include <iostream>

namespace
{
    // Test the setIndividuals() to check if it actually adds objects
    TEST(Set_individuals, AddedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Land", NULL, NULL); // not testing the factories thus it can be NULL

        // build vector of armyComponents manually
        std::vector<ArmyComponent *> *indv = new std::vector<ArmyComponent *>();
        indv->push_back(new LandUnit(1));
        indv->push_back(new LandUnit(2));
        indv->push_back(new LandVehicle(3));
        indv->push_back(new LandVehicle(1));
        indv->push_back(new LandUnit(5));
        indv->push_back(new LandUnit(4));
        indv->push_back(new LandUnit(2));
        indv->push_back(new LandVehicle(3));
        indv->push_back(new LandUnit(4));

        // set the individuals
        // std::cout << "here" << std::endl;
        builder->setIndividuals(indv);
        //  std::cout << "here" << std::endl;
        std::vector<ArmyComponent *> *result = builder->getIndividuals(); // result should not be NULL since we called setter

        // Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(result->size(), 0);

        // deallocate memory
        delete builder;
        delete indv;
        // delete result;
    }

    // Test the setBattalions() to check if it actually adds objects
    TEST(Set_Battalions, AddedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Air", NULL, NULL); // not testing the factories thus it is NULL

        // build vector of armyComponents manually
        std::vector<ArmyComponent *> *battalion = new std::vector<ArmyComponent *>();
        battalion->push_back(new LandUnit(1));
        battalion->push_back(new LandUnit(2));
        battalion->push_back(new LandVehicle(3));
        battalion->push_back(new LandVehicle(1));
        battalion->push_back(new LandUnit(5));
        battalion->push_back(new LandUnit(4));
        battalion->push_back(new LandUnit(2));
        battalion->push_back(new LandVehicle(3));
        battalion->push_back(new LandUnit(4));

        // set the Battalions
        builder->setBattalions(battalion);

        std::vector<ArmyComponent *> *result = builder->getBattalions(); // result should not be NULL since we called setter

        // Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(result->size(), 0);

        // deallocate memory
        delete builder;
        delete battalion;
        //  delete result;
    }

    // Test the setSupplies() to check if it actually adds objects
    TEST(Set_Supplies, AddedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Sea", NULL, NULL); // not testing the factories thus it is NULL

        // build vector of Supply objects manually
        std::vector<Supply *> *supplies = new std::vector<Supply *>();
        supplies->push_back(new AmmoSupply(1, 10));
        supplies->push_back(new MedicalSupply(1, 10));
        supplies->push_back(new AmmoSupply(2, 5));
        supplies->push_back(new MedicalSupply(2, 5));
        supplies->push_back(new AmmoSupply(3, 9));
        supplies->push_back(new MedicalSupply(3, 9));

        // set the Supplies
        builder->setSupplies(supplies);

        std::vector<Supply *> *result = builder->getSupplies(); // result should not be NULL since we called setter

        // Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(result->size(), 0);

        // deallocate memory
        delete builder;
        delete supplies;
        //   delete result;
    }

    // Test the getIndividuals() to check if it does not return NULL
    TEST(Get_individuals, DidNotReceiveItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Land", NULL, NULL); // passing in NULL for the factories since we won't test them

        // Getter should return NULL since we did not call setter / createIndividuals()
        std::vector<ArmyComponent *> *result = builder->getIndividuals();

        // Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        // deallocate memory
        delete builder;
        //    delete result;
    }

    // Test the getBattalions() to check if it does return NULL
    TEST(Get_Battalions, DidNotReceiveItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Air", NULL, NULL); // passing in NULL for the factories since we won't test them

        // Getter should return NULL since we did not call setter / buildBattalions()
        std::vector<ArmyComponent *> *result = builder->getBattalions();

        // Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        // deallocate memory
        delete builder;
        // delete result;
    }

    // Test the getSupplies() to check if it does return NULL
    TEST(Get_Supplies, DidNotReceiveItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Sea", NULL, NULL); // passing in NULL for the factories since we won't test them

        // Getter should return NULL since we did not call setter / determineSupplies()
        std::vector<Supply *> *result = builder->getSupplies();

        // Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        // deallocate memory
        delete builder;
        //  delete result;
    }

    // Test the getIndividuals() to check if it does not return NULL
    TEST(Get_individuals, ReceivedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Land", NULL, NULL); // not testing the factories thus it can be NULL

        // build vector of armyComponents manually
        std::vector<ArmyComponent *> *indv = new std::vector<ArmyComponent *>();
        indv->push_back(new LandUnit(1));
        indv->push_back(new LandUnit(2));
        indv->push_back(new LandVehicle(3));
        indv->push_back(new LandVehicle(1));
        indv->push_back(new LandUnit(5));
        indv->push_back(new LandUnit(4));
        indv->push_back(new LandUnit(2));
        indv->push_back(new LandVehicle(3));
        indv->push_back(new LandUnit(4));

        // set the individuals
        builder->setIndividuals(indv);

        // Getter should not return NULL since we did call setter
        std::vector<ArmyComponent *> *result = builder->getIndividuals();

        // Test: Does getter return a value other than NULL?
        ASSERT_NE(nullptr, result);

        // deallocate memory
        delete builder;
        delete indv;
        // delete result;
    }

    // Test the getBattalions() to check if it does not return NULL
    TEST(Get_Battalions, ReceivedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Air", NULL, NULL); // not testing the factories thus it is NULL

        // build vector of armyComponents manually
        std::vector<ArmyComponent *> *battalion = new std::vector<ArmyComponent *>();
        battalion->push_back(new LandUnit(1));
        battalion->push_back(new LandUnit(2));
        battalion->push_back(new LandVehicle(3));
        battalion->push_back(new LandVehicle(1));
        battalion->push_back(new LandUnit(5));
        battalion->push_back(new LandUnit(4));
        battalion->push_back(new LandUnit(2));
        battalion->push_back(new LandVehicle(3));
        battalion->push_back(new LandUnit(4));

        // set the Battalions
        builder->setBattalions(battalion);

        // Getter should return NULL since we did call setter
        std::vector<ArmyComponent *> *result = builder->getBattalions();

        // Test: Does getter return a value other than NULL?
        ASSERT_NE(nullptr, result);

        // deallocate memory
        delete builder;
        delete battalion;
        //  delete result;
    }

    // Test the getSupplies() to check if it does not return NULL
    TEST(Get_Supplies, ReceivedItems)
    {
        ArmyBuilder *builder = new ArmyBuilder("Sea", NULL, NULL); // not testing the factories thus it is NULL

        // build vector of Supply objects manually
        std::vector<Supply *> *supplies = new std::vector<Supply *>();
        supplies->push_back(new AmmoSupply(1, 10));
        supplies->push_back(new MedicalSupply(1, 10));
        supplies->push_back(new AmmoSupply(2, 5));
        supplies->push_back(new MedicalSupply(2, 5));
        supplies->push_back(new AmmoSupply(3, 9));
        supplies->push_back(new MedicalSupply(3, 9));

        // set the Supplies
        builder->setSupplies(supplies);

        // Getter should return NULL since we did call setter
        std::vector<Supply *> *result = builder->getSupplies();

        // Test: Does getter return a value other than NULL?
        ASSERT_NE(nullptr, result);

        // deallocate memory
        delete builder;
        delete supplies;
        //   delete result;
    }

    //=======================================================================================
    //=== ArmyDirector testing ==============================================================
    //=======================================================================================

    // Check to see if exception is thrown when we call construct without having a builder
    TEST(ConstructWithNoBuilder, BuilderNull)
    {
        try
        {
            ArmyDirector *d = new ArmyDirector(NULL);
            d->constructArmy(); // should throw exception since we do not have a builder
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("Cannot build army because there is no ArmyBuilder"));
        }
        catch (...)
        {
            FAIL();
        }
    }
}
