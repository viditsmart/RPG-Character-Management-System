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
    setCharacterType("Knight");
    setLevel(1);
    setHealth(750);
    setAttackPower(38);
    setDefense(30);
    setExperiencePoints(0);
    setStatus("Alive");
    Weapon sword = Weapon("Sword", 30);
    Weapon shield = Weapon("Shield", 20);
}

void Knight::swordAttack(Character &target)
{
    // Implement sword attack logic
    int damage = sword.getDamage();
    // You can add logic to apply damage to an enemy character here
    Character::setAttackPower(getAttackPower() + damage); 
    int enemyHealth = target.getHealth();
    enemyHealth -= damage; // Reduce target's health by damage
    target.setHealth(enemyHealth);
    std::cout << "Knight attacks " << target.getName() << " with the sword!" << std::endl;
}

void Knight::shieldBlock(Character &target)
{
    // Implement shield block logic
    Character::setDefense(getDefense() + 45);
    std::cout << "Knight blocks the attack with the shield!" << std::endl;

}

void Knight::shieldBash(Character &target)
{
    // Implement shield bash logic
    int damage = shield.getDamage();
    Character::setAttackPower(getAttackPower() + damage);
    int enemyHealth = target.getHealth();
    enemyHealth -= damage;
    target.setHealth(enemyHealth);
    std::cout << "Knight bashes " << target.getName() << " with the shield!" << std::endl;
}

void Knight::specialSkill(Character &target)
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
            swordAttack(target);
            break;
        }
        case 2:
        {
            shieldBlock(target);
            break;
        }
        case 3:
        {
            shieldBash(target);
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