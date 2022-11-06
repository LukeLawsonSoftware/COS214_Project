// In these files you write the actual code to do the testing
#include <limits.h>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../Code/EconomicState.h"
#include "../Code/Rich.h"
#include "../Code/Average.h"
#include "../Code/Poor.h"
#include "../Code/Country.h"

namespace
{
    /*
        For the EconomicState hierarchy we will test whether or not the decideMyTurn() method functions
        correctly. In order to test this we will need to test if the return value (returned by the decideMyTurn() method)
        falls within the range one to ten (1 and 10 are both included).
        I.e. we test if the return value is greater than zero AND less than eleven.
    */
    // Rich state:    Test if the decideTurn function returns a value within the range (1,10) (included)
    TEST(DecideInRichState, ValidDecision)
    {
        EconomicState *rich = new Rich();
        int returnValue = rich->decideMyTurn(new Country("Rich", "Russia"));

        ASSERT_GT(returnValue, 0);  // we test if our return value is greater than zero
        ASSERT_LT(returnValue, 11); // we test if our return value is less than eleven

        // deallocate memory
        delete rich;
    }

    // Average state:    Test if the decideTurn function returns a value within the range (1,10) (included)
    TEST(DecideInAverageState, ValidDecision)
    {
        EconomicState *avg = new Average();
        int returnValue = avg->decideMyTurn(new Country("Average", "America"));

        ASSERT_GT(returnValue, 0);  // we test if our return value is greater than zero
        ASSERT_LT(returnValue, 11); // we test if our return value is less than eleven

        // deallocate memory
        delete avg;
    }

    // Poor state:    Test if the decideTurn function returns a value within the range (1,10) (included)
    TEST(DecideInPoorState, ValidDecision)
    {
        EconomicState *poor = new Poor();
        int returnValue = poor->decideMyTurn(new Country("Poor", "South Africa"));

        ASSERT_GT(returnValue, 0);  // we test if our return value is greater than zero
        ASSERT_LT(returnValue, 11); // we test if our return value is less than eleven

        // deallocate memory
        delete poor;
    }
}