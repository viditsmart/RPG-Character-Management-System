#ifndef DOCTOR_H
#define DOCTOR_H

#include "Character.h"

class Doctor : public Character
{
public:
    Doctor();
    void Heal();
    ~Doctor();
};

#endif 
