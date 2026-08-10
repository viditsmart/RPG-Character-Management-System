#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character
{
public:
    Mage();
    void Fireball();
    void IceShard();
    void lightningStrike();
    void specialSkill() override;
    ~Mage();
private:

};

#endif