#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/AmmoFactory.h"
#include "../Code/AmmoSupply.h"
#include "../Code/MedicalFactory.h"
#include "../Code/MedicalSupply.h"

namespace
{
    //Check for quantity input as negative
    TEST(QuantityInput, Negative_Zero_Positive_Test)
    {
        int quantity = 0;
        ASSERT_EQ(quantity, -1); /* negative */
        ASSERT_EQ(quantity, 0);  /* zero */
        ASSERT_GT(quantity, 0);  /* positive */
    }

    //Check for intput when setting bonus
    TEST(SettingAmmoBonus, NegativeCase)
    {
        try{
            AmmoSupply* a = new AmmoSupply(1,3);
            int newAmmoBonus = -1;
            a->setAmmoBonus(newAmmoBonus);
            FAIL();
        }
        catch(std::invalid_argument &err){
            EXPECT_EQ(err.what(), std::string("Cannot set ammo bonus as a negative value"));
        }
        catch(...){
            FAIL():
        }
    }

    //Check for intput when setting bonus
    TEST(SettingMedicalBonus, NegativeCase)
    {
        try{
            MedicalSupply* m = new MedicalSupply(1,3);
            int newMedicalBonus = -1;
            m->setMedicalBonus(newMedicalBonus);
            FAIL();
        }
        catch(std::invalid_argument &err){
            EXPECT_EQ(err.what(), std::string("Cannot set medical bonus as a negative value"));
        }
        catch(...){
            FAIL():
        }
    }

    //Check for intput when setting bonus
    TEST(SettingMedicalBonus, PositiveCase)
    {
        try{
            MedicalSupply* m = new MedicalSupply(1,3);
            int newMedicalBonus = 1;
            m->setMedicalBonus(newMedicalBonus);
        }
        catch(...){
            FAIL():
        }
    }

    //Check for intput when setting bonus
    TEST(SettingAmmoBonus, PositiveCase)
    {
        try{
            AmmoSupply* a = new AmmoSupply(1,3);
            int newAmmoBonus = 1;
            a->setAmmoBonus(newAmmoBonus);
        }
        catch(...){
            FAIL():
        }
    }

    //Check for valid return on the ammo bonus
    TEST(GettingAmmoBonus, TestCase)
    {
        AmmoSupply* a = new AmmoSupply(1,3);
        a->setAmmoBonus(3);
        ASSERT_EQ(a->getAmmoBonus(), 3);
        delete a;
    }

    //Check for valid return on the medical bonus
    TEST(GettingAmmoBonus, TestCase)
    {
        MedicalSupply* m = new MedicalSupply(1,3);
        m->setMedicalBonus(3);
        ASSERT_EQ(m->getMedicalBonus(), 3);
        delete m;
    }

    //Check if upgrade() method works
    TEST(UpgradeFactory, TestLevelIncrease)
    {
        AmmoFactory* a = new AmmoFactory(1, "ammoFactory");

        int currentLevel = a->getLevel();
        a->upgrade();

        ASSERT_EQ(currentLevel+1, currentLevel);
        delete a;
    }
}