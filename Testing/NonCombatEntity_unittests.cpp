// In these files you write the actual code to do the testing
#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/NonCombatEntity.h"
#include "../Code/Medic.h"
#include "../Code/Civilian.h"
#include <iostream>

namespace {
    /*
        For the NonCombatEntity hierarchy we will test whether or not the clone() method functions
        correctly. In order to tests this we create two objects: an original version and a cloned version.
        Then we compare the two objects' attribute and if the two objects have the same value (after cloning)
        then the test is successful.
        We will test both the Medic and Civilian classes.

        We will also test if the setDesignation() method defined inside the Civilian class, functions correctly.
        We will test this by testing two:
            Case 1:     testing if an original value differs from the new value after call the setter
            Case 2:     testing if the new value (after calling the setter) differs to the passed in parameter.  
        
        We will also test the parameterised constructers of both the Medic and Civilian classes.
        In order to test this we will compare the healing/designation
        attribute to a variable which is initialised with the same value as the parameter.
    */

    //=================================================
    //Test the Medic and Civilian class' clone() method
    //=================================================

    //Test the Medic class's clone() method
    TEST(CloneMedic, SuccessfulClone){
        NonCombatEntity* original = new Medic();
        NonCombatEntity* cloned = original->clone();

        int original_healing = ( (Medic*) original)->getHealing();
        int cloned_healing = ( (Medic*) cloned)->getHealing();

        ASSERT_EQ(original_healing, cloned_healing);

        //deallocate memory
        delete original;
    }

    //Test the Civilian class's clone() method
    TEST(CloneCivilian, SuccessfulClone){
        NonCombatEntity* original = new Civilian();
        NonCombatEntity* cloned = original->clone();

        std::string original_designation = ( (Civilian*) original)->getDesignation();
        std::string cloned_designation = ( (Civilian*) cloned)->getDesignation();

        ASSERT_EQ(original_designation, cloned_designation);

        //deallocate memory
        delete original;
    }

    //========================================================
    //Testing the Civilian class's setter method for two cases
    //========================================================

    //CASE 1:   comparing the original value to a string value
    TEST(CivilianSetter, SuccessfulSetting_CASE_1){
        NonCombatEntity* human = new Civilian();

        ( (Civilian*) human)->setDesignation("refugee");
        std::string original_designation = ( (Civilian*) human)->getDesignation();

        ASSERT_EQ(original_designation, "refugee");

        //deallocate memory
        delete human;
    }
 
    //CASE 2:   comparing the parameter value to a different string value
    TEST(CivilianSetter, SuccessfulSetting_CASE_2){
        NonCombatEntity* human = new Civilian("civilian");
        std::string original_designation = ( (Civilian*) human)->getDesignation();

        ( (Civilian*) human)->setDesignation("refugee");
        std::string new_designation = ( (Civilian*) human)->getDesignation();

        ASSERT_NE(original_designation, new_designation);

        //deallocate memory
        delete human;
    }

    //==================================
    //Test the parameterised constructor
    //==================================

    //Testing the Medic class
    TEST(TestMedicParamConstruct, SuccessfulConstruct){
        NonCombatEntity* m = new Medic(100); //initialised with healing=100;
        
        int medic_healing = ( (Medic*) m)->getHealing();

        ASSERT_EQ(100, medic_healing);

        //deallocate memory
        delete m;
    }

    //Testing the Civilian class
    TEST(TestCivilianParamConstruct, SuccessfulConstruct){
        NonCombatEntity* c = new Civilian("civilian"); //initialised with designation="civilian";
        
        std::string civilian_designation = ( (Civilian*) c)->getDesignation();

        ASSERT_EQ("civilian", civilian_designation);

        //deallocate memory
        delete c;
    }

}