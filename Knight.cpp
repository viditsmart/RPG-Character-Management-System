#include "Knight.h"
#include "Character.h"
#include "Weapon.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

Knight::Knight()
{
    // Initialize the knight's weapons
    setLevel(1);
    setHealth(750);
    setAttackPower(38);
    setDefense(30);
    setExperiencePoints(0);
    setStatus("Alive");
    Weapon sword = Weapon("Sword", 30);
    Weapon shield = Weapon("Shield", 20);
}

void Knight::swordAttack()
{
    // Implement sword attack logic
    int damage = sword.getDamage();
    // You can add logic to apply damage to an enemy character here
    Character::setAttackPower(getAttackPower() + damage); 
}

void Knight::shieldBlock()
{
    // Implement shield block logic
    Character::setDefense(getDefense() + 45);

}

void Knight::shieldBash()
{
    // Implement shield bash logic
    int damage = shield.getDamage();
    Character::setAttackPower(getAttackPower() + damage);
    
}

void Knight::specialSkill()
{
    // Implement the knight's special skill logic
    // For example, a powerful attack or defensive move
    short int seed = static_cast<short int>(time(0));
    srand(seed);
    std::cout << "Choose a special skill for the Knight:" << std::endl;
    std::cout << "1. Sword Attack" << std::endl;
    std::cout << "2. Shield Block" << std::endl;
    std::cout << "3. Shield Bash" << std::endl;
    int choice;
    choice = rand() % 3 + 1; // Randomly choose a skill (1, 2, or 3)
    std::cout << "Randomly selected skill: " << choice << std::endl;
    switch (choice)
    {
        case 1:
        {
            swordAttack();
            break;
        }
        case 2:
        {
            shieldBlock();
            break;
        }
        case 3:
        {
            shieldBash();
            break;
        }
        default:
        {
            std::cout << "Invalid choice. No special skill used." << std::endl;
            break;
        }
    }
    std::cout << "Knight uses a special skill!" << std::endl;
}