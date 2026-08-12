#ifndef DOCTOR_H
#define DOCTOR_H

#include "Character.h"

class Doctor : public Character
{
public:
    Doctor();
    int Heal(Character &patient);
    void specialSkill(Character &patient) override;
    ~Doctor();
private:

};

#endif 
