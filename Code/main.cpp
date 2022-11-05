#include <iostream>
#include "War.h"
#include "LandTerrain.h"
#include "Country.h"
int main()
{
    //  War war;
    //  war.startWarSim();

    WarTheatre *test = new LandTerrain();
    Country *c1 = new Country("Rich", "Russia");
    Country *c2 = new Country("Rich", "USA");
    Country::alliance1.push_back(c1);
    Country::alliance2.push_back(c2);

    c1->raiseArmy();
    c2->raiseArmy();
    test->addArmy(c1->getArmy());
    test->addArmy(c2->getArmy());

    test->conflict();
    test->conflict();
    test->conflict();
    test->conflict();
    test->conflict();
}