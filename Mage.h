#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
//Mage class inheritied from Character
class Mage : public Character
{
public:
//Member functions
    Mage();
    void Fireball(Character &target);
    void IceShard(Character &target);
    void lightningStrike(Character &target);
    void specialSkill(Character &target) override;
    ~Mage();
private:

};

#endif