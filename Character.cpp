#include "Character.h"

Character::Character()
{
    name = "Unknown";
    characterType = "Unknown";
    level = 1;
    health = 100;
    attack_power = 20;
    defense = 10;
    experience_points = 0;
    status = "Alive";
}

void Character::setName(const std::string &n)
{
    name = n;
}

std::string Character::getName() const
{
    return name;
}

void Character::setCharacterType(const std::string &ct)
{
    characterType = ct;
}

std::string Character::getCharacterType() const
{
    return characterType;
}

void Character::setLevel(int l)
{
    level = l;
}

int Character::getLevel() const
{
    return level;
}

void Character::setHealth(int h)
{
    health = h;
}

int Character::getHealth() const
{
    return health;
}

void Character::setAttackPower(int ap)
{
    attack_power = ap;
}

int Character::getAttackPower() const
{
    return attack_power;
}

void Character::setDefense(int d)
{
    defense = d;
}

int Character::getDefense() const
{
    return defense;
}

void Character::setExperiencePoints(int xp)
{
    experience_points = xp;
}

int Character::getExperiencePoints() const
{
    return experience_points;
}

void Character::setStatus(const std::string &s)
{
    status = s;
}

std::string Character::getStatus() const
{
    return status;
}

Character::~Character()
{
    // Destructor implementation (if needed)
}