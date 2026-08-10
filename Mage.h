#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character
{
public:
    Mage();
    void Fireball(Character &target);
    void IceShard(Character &target);
    void lightningStrike(Character &target);
    void specialSkill(Character &target) override;
    ~Mage();
private:

};

#endif