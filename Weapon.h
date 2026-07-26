#ifndef WEAPON_H
#include <string>
using namespace std;

class Weapon
{
private:
    string weaponName;
    int damage;
public:
    Weapon();
    Weapon(string wn, int d);
    void setWeaponName(string wn);
    string getWeaponName();
    void setDamage(int d);
    int getDamage();
};

#endif