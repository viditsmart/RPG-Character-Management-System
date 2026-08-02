#include "Knight.h"
#include "Character.h"
#include "Weapon.h"

Knight::Knight()
{
    // Initialize the knight's weapons
    sword = Weapon("Sword", 30);
    shield = Weapon("Shield", 20);
}

void Knight::swordAttack()
{
    // Implement sword attack logic
    int damage = sword.getDamage();
    // You can add logic to apply damage to an enemy character here
}

void Knight::shieldBlock()
{
    // Implement shield block logic

}

void Knight::shieldBash()
{
    // Implement shield bash logic
    
}