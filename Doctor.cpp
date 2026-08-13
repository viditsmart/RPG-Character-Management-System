#include "Character.h"
#include "Doctor.h"
#include <iostream>

//Here are all the member functions implemented for Doctor class

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

int Doctor::Heal(Character &patient)
{
   if (patient.getStatus() == "Defeated")
   {
      std::cout << patient.getName() << " is dead and cannot be healed." << std::endl;
      return 0;
   }
   int hp = patient.getHealth();
   hp+=30;
   return hp;
}

void Doctor::specialSkill(Character &patient)
{
   Heal(patient);
}