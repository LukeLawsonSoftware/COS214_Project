// In these files you write the actual code to do the testing
#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/WarTheatre.h"
#include "../Code/LandTerrain.h"
#include "../Code/AirTerrain.h"
#include "../Code/SeaTerrain.h"

namespace {
    /*
        For the WarTheatre hierarchy we will test only the getters defined inside the WarTheatre class
        -   getters include:    getType(), getName(), getContentionState()
        
        NOTE: We will test this for all three terrains: Land, Air, Sea
    */

    //==============================================================
    //=================== Testing the Land Terrain =================
    //==============================================================

    //Testing the getType() method

    TEST(LandTerrain_GetType, ReceivedCorrectType){
        WarTheatre* wt = new LandTerrain(); //type = "Land"

        std::string type = ( (LandTerrain*) wt)->getType();

        ASSERT_EQ("Land", type);

        //deallocate memory
        delete wt;
    }

    //Testing the getName() method

    TEST(LandTerrain_GetName, ReceivedCorrectName){
        WarTheatre* wt = new LandTerrain(); //name = "The plain of doom"

        std::string name = ( (LandTerrain*) wt)->getName();

        ASSERT_EQ("The plain of doom", name);

        //deallocate memory
        delete wt;
    }

    //Testing the getContentionState() method

    TEST(LandTerrain_GetContentionState, ReceivedCorrectType){
        WarTheatre* wt = new LandTerrain(); //contentionState = 0

        int contentionState = ( (LandTerrain*) wt)->getContentionState();

        ASSERT_EQ(0, contentionState);

        //deallocate memory
        delete wt;
    }

    //==============================================================
    //=================== Testing the Air Terrain =================
    //==============================================================

    //Testing the getType() method

    TEST(AirTerrain_GetType, ReceivedCorrectType){
        WarTheatre* wt = new AirTerrain(); //type = "Air"

        std::string type = ( (AirTerrain*) wt)->getType();

        ASSERT_EQ("Air", type);

        //deallocate memory
        delete wt;
    }

    //Testing the getName() method

    TEST(AirTerrain_GetName, ReceivedCorrectName){
        WarTheatre* wt = new AirTerrain(); //name = "The sky arena"

        std::string name = ( (AirTerrain*) wt)->getName();

        ASSERT_EQ("The sky arena", name);

        //deallocate memory
        delete wt;
    }

    //Testing the getContentionState() method

    TEST(AirTerrain_GetContentionState, ReceivedCorrectType){
        WarTheatre* wt = new AirTerrain(); //contentionState = 0

        int contentionState = ( (AirTerrain*) wt)->getContentionState();

        ASSERT_EQ(0, contentionState);

        //deallocate memory
        delete wt;
    }

    //==============================================================
    //=================== Testing the Sea Terrain =================
    //==============================================================

    //Testing the getType() method

    TEST(SeaTerrain_GetType, ReceivedCorrectType){
        WarTheatre* wt = new SeaTerrain(); //type = "Sea"

        std::string type = ( (SeaTerrain*) wt)->getType();

        ASSERT_EQ("Sea", type);

        //deallocate memory
        delete wt;
    }

    //Testing the getName() method

    TEST(SeaTerrain_GetName, ReceivedCorrectName){
        WarTheatre* wt = new SeaTerrain(); //name = "The seven seas"

        std::string name = ( (SeaTerrain*) wt)->getName();

        ASSERT_EQ("The seven seas", name);

        //deallocate memory
        delete wt;
    }

    //Testing the getContentionState() method

    TEST(SeaTerrain_GetContentionState, ReceivedCorrectType){
        WarTheatre* wt = new SeaTerrain(); //contentionState = 0

        int contentionState = ( (SeaTerrain*) wt)->getContentionState();

        ASSERT_EQ(0, contentionState);

        //deallocate memory
        delete wt;
    }
}