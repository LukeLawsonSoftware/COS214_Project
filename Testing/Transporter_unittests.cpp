//In these files you write the actual code to do the testing
#include "../Code/Transporter.h"
#include "../Code/MedicTransporter.h"
#include "../Code/AmmoTransporter.h"

namespace{
    //Check if registering a Country to a transport line works
    TEST(CountryRegistration, SuccessfulRegistration){
        /*
         * Instantiating a country will call the regToTransport method, defined inside the Corresponder class
         * which then calls the registerCorresponder method.
        */
        try{
            Corresponder* c = new Country("Rich", "Russia");
            FAIL();
        }
        catch(std::invalid_argument &err){
            EXPECT_EQ(err.what(), std::string("Cannot register object of type NULL to corresponderList vector."));
        }
        catch(...){
            FAIL();
        }
    }

    //Test the notify() method with NULL passed in as paramter
    TEST(MedicNotifyNullParameter, NullCase){
        try{
            Transporter* m = new MedicTransporter();
            m->notify(NULL);
            FAIL();
        }
        catch(std::invalid_argument &err){
            EXPECT_EQ(err.what(), std::string("Country has no army to which it can send Medical supplies."));
        }
        catch(...){
            FAIL();
        }
    }

    //Test the notify() method with NULL passed in as paramter
    TEST(AmmoNotifyNullParameter, NullCase){
        try{
            Transporter* a = new AmmoTransporter();
            a->notify(NULL);
            FAIL();
        }
        catch(std::invalid_argument &err){
            EXPECT_EQ(err.what(), std::string("Country has no army to which it can send Ammo supplies."));
        }
        catch(...){
            FAIL();
        }
    }

    //Test the notify() method with an actual object passed in as paramter
    TEST(MedicNotifyObjectParameter, NotNullCase){
        try{
            Transporter* m = new MedicTransporter();
            Corresponder* c = new Country("Poor", "South Africa");
            m->notify(c);
        }
        catch(...){
            FAIL();
        }
    }

    //Test the notify() method with an actual object passed in as paramter
    TEST(AmmoNotifyObjectParameter, NotNullCase){
        try{
            Transporter* a = new MedicTransporter();
            Corresponder* c = new Country("Poor", "South Africa");
            a->notify(c);
        }
        catch(...){
            FAIL();
        }
    }
}