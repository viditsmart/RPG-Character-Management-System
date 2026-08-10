#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"
#include "Weapon.h"

class Knight : public Character
{
private:
    Weapon shield;
    Weapon sword;

public:
    Knight();
    void swordAttack(Character &target);
    void shieldBlock(Character &target);
    void shieldBash(Character &target);
    void specialSkill(Character &target) override;
    ~Knight();
};

#endif