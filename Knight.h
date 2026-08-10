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
    void swordAttack();
    void shieldBlock();
    void shieldBash();
    void specialSkill() override;
    ~Knight();
};

#endif