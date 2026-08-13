#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"
#include "Weapon.h"

//Knight class
class Knight : public Character
{
private:
//member variables
    Weapon shield;
    Weapon sword;

public:
//member functions
    Knight();
    void swordAttack(Character &target);
    void shieldBlock(Character &target);
    void shieldBash(Character &target);
    void specialSkill(Character &target) override;
    ~Knight();
};

#endif