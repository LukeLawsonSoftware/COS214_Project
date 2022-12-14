#include <iostream>
#include "War.h"
#include "LandTerrain.h"
#include "Country.h"

void presentMenu(War *war)
{
    std::cout << "\033[1;37m";
    std::cout << "War, war never changes..." << std::endl;
    std::cout << "\033[;0m";
    std::cout << std::endl;
    std::cout << "\033[4;37m";
    std::cout << "Welcome to Hyper-Realistic War Simulator! (Patent pending)" << std::endl;
    std::cout << "\033[;0m";
    std::cout << "A proud product of COS214 group OOPs!" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1;37m";
    std::cout << "How would you like to run the simulation?" << std::endl;
    std::cout << "\033[;0m";
    std::cout << "1. Provide a configuration and observe the carnage in Simulation Mode" << std::endl;
    std::cout << "2. Mastermind your alliance to victory in Gameplay Mode" << std::endl;

    std::string choice;
    std::getline(std::cin, choice);
    int option = std::stoi(choice);

    if (option != 2)
    {
        std::cout << "\033[1;34m";
        std::cout << "You have selected Simulation Mode." << std::endl;
        std::cout << "\033[;0m";
        std::cout << "Configure your simulation:" << std::endl;
        war->selectConfiguration();
        std::cout << "\033[1;33m";
        std::cout << "Note that you can end the simulation by typing 'stop' in the console" << std::endl;
        std::cout << "\033[;0m";
        std::cout << "Begin?" << std::endl;
        std::string test;
        std::cin >> test;
        if (test == "stop")
        {
            return;
        }
        war->startWarSim();
    }
    else
    {
        std::cout << "\033[1;34m";
        std::cout << "You have selected Gameplay Mode." << std::endl;
        std::cout << "\033[;0m";
        std::cout << "You will play as alliance 1. Select a configuration for your game:" << std::endl;
        war->selectConfiguration();
        std::cout << "\033[1;33m";
        std::cout << "Note that you can end the simulation by typing 'stop' in the console" << std::endl;
        std::cout << "\033[;0m";
        std::cout << "Begin?" << std::endl;
        std::string test;
        std::cin >> test;
        if (test == "stop")
        {
            return;
        }
        war->startWarGame();
    }
    return;
}

int main()
{
    War *war = new War();
    presentMenu(war);
    delete war;
    /*
        WarTheatre *test = new LandTerrain();
        Country *c1 = new Country("Poor", "Russia");
        Country *c2 = new Country("Rich", "USA");
        Country::alliance1.push_back(c1);
        Country::alliance2.push_back(c2);

        c1->raiseArmy();
        //  c1->destroyArmy();
        // c1->raiseArmy();
        // c1->destroyArmy();
        // c1->raiseArmy();
        // c1->destroyArmy();
        c2->raiseArmy();
        test->addArmy(c1->getArmy());
        test->addArmy(c2->getArmy());

        c1->getArmy()->changeStrategy("Offensive");

        test->conflict();
        test->conflict();
        test->conflict();
        test->conflict();
        test->conflict();
        */
}