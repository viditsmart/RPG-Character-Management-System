#include "Character.h"
#include "Mage.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

Mage::Mage()
{
    setLevel(1);
    setHealth(315);
    setAttackPower(25);
    setDefense(20);
    setExperiencePoints(0);
    setStatus("Alive");
}

void Mage::Fireball()
{

}

void Mage::IceShard()
{

}

void Mage::lightningStrike()
{

}

void Mage::specialSkill()
{
    // Implement the mage's special skill logic
    // For example, a powerful attack or defensive move
    short int seed = static_cast<short int>(time(0));
    srand(seed);
    std::cout << "Choose a special skill for the Mage:" << std::endl;
    std::cout << "1. Fireball" << std::endl;
    std::cout << "2. Ice Shard" << std::endl;
    std::cout << "3. Lightning Strike" << std::endl;
    int choice;
    choice = rand() % 3 + 1; // Randomly choose a skill 
    
    switch (choice)
    {
        case 1:
        {
            Fireball();
            break;
        }
        case 2:
        {
            IceShard();
            break;
        }
        case 3:
        {
            lightningStrike();
            break;
        }
        default:
        {
            std::cout << "Invalid choice. No special skill used." << std::endl;
            break;
        }
    }
}

