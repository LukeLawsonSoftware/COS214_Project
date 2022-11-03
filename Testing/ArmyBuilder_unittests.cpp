#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/ArmyBuilder.h"
#include <iostream>

namespace{
    //Test the setIndividuals() to check if it actually adds objects
    TEST(Set_individuals, AddedItems){
        ArmyBuilder* builder = new ArmyBuilder("Land",NULL,NULL); //not testing the factories thus it can be NULL

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

        std::vector<ArmyComponent*> *result = builder->getIndividuals();//result should not be NULL since we called setter

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete indv;
        delete result;
    }

    //Test the setBattalions() to check if it actually adds objects
    TEST(Set_Battalions, AddedItems){
        ArmyBuilder* builder = new ArmyBuilder("Air",NULL,NULL); //not testing the factories thus it is NULL

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

        std::vector<ArmyComponent*> *result = builder->getBattalions();//result should not be NULL since we called setter

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete battalion;
        delete result;
    }

    //Test the setSupplies() to check if it actually adds objects
    TEST(Set_Supplies, AddedItems){
        ArmyBuilder* builder = new ArmyBuilder("Sea",NULL,NULL); //not testing the factories thus it is NULL

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

        std::vector<Supply*> *result = builder->getSupplies();//result should not be NULL since we called setter

        //Test: setter did set the vector thus the size is greater than 0
        ASSERT_GT(0, result->size());

        //deallocate memory
        delete builder;
        delete supplies;
        delete result;
    }

    //Test the getIndividuals() to check if it does not return NULL
    TEST(Get_individuals, DidNotReceiveItems){
        ArmyBuilder* builder = new ArmyBuilder("Land",NULL,NULL); //passing in NULL for the factories since we won't test them

        //Getter should return NULL since we did not call setter / createIndividuals()
        std::vector<ArmyComponent*> *result = builder->getIndividuals();

        //Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        //deallocate memory
        delete builder;
        delete result;
    }

    //Test the getBattalions() to check if it does return NULL
    TEST(Get_Battalions, DidNotReceiveItems){
        ArmyBuilder* builder = new ArmyBuilder("Air",NULL,NULL); //passing in NULL for the factories since we won't test them

        //Getter should return NULL since we did not call setter / buildBattalions()
        std::vector<ArmyComponent*> *result = builder->getBattalions();

        //Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        //deallocate memory
        delete builder;
        delete result;
    }

    //Test the getSupplies() to check if it does return NULL
    TEST(Get_Supplies, DidNotReceiveItems){
        ArmyBuilder* builder = new ArmyBuilder("Sea",NULL,NULL); //passing in NULL for the factories since we won't test them

        //Getter should return NULL since we did not call setter / determineSupplies()
        std::vector<Supply*> *result = builder->getSupplies();

        //Test: Does getter return NULL?
        ASSERT_EQ(NULL, result);

        //deallocate memory
        delete builder;
        delete result;
    }

    //Test the getIndividuals() to check if it does not return NULL
    TEST(Get_individuals, ReceivedItems){
        ArmyBuilder* builder = new ArmyBuilder("Land",NULL,NULL); //not testing the factories thus it can be NULL

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

        //Getter should not return NULL since we did call setter
        std::vector<ArmyComponent*> *result = builder->getIndividuals();

        //Test: Does getter return a value other than NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete indv;
        delete result;
    }

    //Test the getBattalions() to check if it does not return NULL
    TEST(Get_Battalions, ReceivedItems){
        ArmyBuilder* builder = new ArmyBuilder("Air",NULL,NULL); //not testing the factories thus it is NULL

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

        //Getter should return NULL since we did call setter
        std::vector<ArmyComponent*> *result = builder->getBattalions();

        //Test: Does getter return a value other than NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete battalion;
        delete result;
    }

    //Test the getSupplies() to check if it does not return NULL
    TEST(Get_Supplies, ReceivedItems){
        ArmyBuilder* builder = new ArmyBuilder("Sea",NULL,NULL); //not testing the factories thus it is NULL

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

        //Getter should return NULL since we did call setter
        std::vector<Supply*> *result = builder->getSupplies();

        //Test: Does getter return a value other than NULL?
        ASSERT_EQ(!NULL, result);

        //deallocate memory
        delete builder;
        delete supplies;
        delete result;
    }
}