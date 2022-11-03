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
        ASSERT_LT(quantity, -1); /* negative */
        ASSERT_EQ(quantity, 0);  /*   zero   */
        ASSERT_GT(quantity+1, 0);  /* positive */
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
            FAIL();
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
            FAIL();
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
            FAIL();
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
            FAIL();
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
    TEST(GettingMedicalBonus, TestCase)
    {
        MedicalSupply* m = new MedicalSupply(1,3);
        m->setMedicalBonus(3);
        ASSERT_EQ(m->getMedicalBonus(), 3);
        delete m;
    }

    //Check if upgrade() method works
    TEST(UpgradeFactory, TestLevelAndBudgetIncrease)
    {
        AmmoFactory* a = new AmmoFactory(1,"ammoFactory");

        int prevLevel = 1;
        int prevBudget = 1;
        a->upgrade();
        int newLevel = a->getLevel();
        int newBudget = a->getBudget();

        ASSERT_GT(newLevel, prevLevel);
        ASSERT_GT(newBudget,prevBudget);

        delete a;
    }

    //Check if getLevel() works
    TEST(GetLevel, TestReturnValueLevel)
    {
        AmmoFactory* a = new AmmoFactory(1,"ammoFactory");

        int level = a->getLevel();

        ASSERT_GE(level, 1);

        delete a;
    }

    //Check if getTotalSpent() works
    TEST(getTotalSpent, TestReturnValueSpent)
    {
        AmmoFactory* a = new AmmoFactory(1,"ammoFactory");

        int spent = a->getTotalSpent();

        ASSERT_GE(spent, 0);

        delete a;
    }
}