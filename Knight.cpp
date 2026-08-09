#include "Knight.h"
#include "Character.h"
#include "Weapon.h"

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