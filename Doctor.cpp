#include "Character.h"
#include "Doctor.h"

Doctor::Doctor()
{
   setCharacterType("Doctor");
   setLevel(1);
   setHealth(250);
   setAttackPower(15);
   setDefense(19);
   setExperiencePoints(0);
   setStatus("Alive");
}

int Doctor::Heal()
{
   int hp = Character::getHealth();
   hp+=30;
   return hp;
}