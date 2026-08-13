#include "Weapon.h"
#include <iostream>
using namespace std;

//Here are all the member functions for Weapon class implemented
Weapon::Weapon()
{
    weaponName = "sword";
    damage = 30;
}

Weapon::Weapon(string wn, int d)
{
    weaponName = wn;
    damage = d;
}

void Weapon::setWeaponName(string wn)
{
    weaponName = wn;
}

void Weapon::setDamage(int d)
{
    damage = d;
}

string Weapon::getWeaponName()
{
    return weaponName;
}

int Weapon::getDamage()
{
    return damage;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called" << std::endl;
}
