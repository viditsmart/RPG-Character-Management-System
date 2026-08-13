#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

//Weapon class
class Weapon
{
private:
//Member variables
    string weaponName;
    int damage;
public:
//Member functions
    Weapon();
    Weapon(string wn, int d);
    void setWeaponName(string wn);
    string getWeaponName();
    void setDamage(int d);
    int getDamage();
    ~Weapon();
};

#endif