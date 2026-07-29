#include "Character.h"
#include "Doctor.h"

Doctor::Doctor()
{

}

int Doctor::Heal()
{
   int hp = Character::getHealth();
   hp+=30;
   return hp;
}