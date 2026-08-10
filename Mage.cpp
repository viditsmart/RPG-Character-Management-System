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

void Mage::Fireball(Character &target)
{
    int damage = getAttackPower() * 2; // Example damage calculation
    int enemyHealth = target.getHealth();
    enemyHealth -= damage;
    target.setHealth(enemyHealth);
    std::cout << "Mage casts Fireball on " << target.getName() << "!" << std::endl;
}

void Mage::IceShard(Character &target)
{
    int damage = getAttackPower() * 1.5; // Example damage calculation
    int enemyHealth = target.getHealth();
    enemyHealth -= damage;
    target.setHealth(enemyHealth);
    std::cout << "Mage casts Ice Shard on " << target.getName() << "!" << std::endl;
}

void Mage::lightningStrike(Character &target)
{
    int damage = getAttackPower() * 3; // Example damage calculation
    int enemyHealth = target.getHealth();
    enemyHealth -= damage;
    target.setHealth(enemyHealth);
    std::cout << "Mage casts Lightning Strike on " << target.getName() << "!" << std::endl;
}

void Mage::specialSkill(Character &target)
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
            Fireball(target);
            break;
        }
        case 2:
        {
            IceShard(target);
            break;
        }
        case 3:
        {
            lightningStrike(target);
            break;
        }
        default:
        {
            std::cout << "Invalid choice. No special skill used." << std::endl;
            break;
        }
    }
}

