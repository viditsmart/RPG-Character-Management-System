#ifndef DOCTOR_H
#define DOCTOR_H

#include "Character.h"

//Doctor class
class Doctor : public Character
{
public:
//memebr functions
    Doctor();
    int Heal(Character &patient);
    void specialSkill(Character &patient) override;
    ~Doctor();
private:

};

#endif 
