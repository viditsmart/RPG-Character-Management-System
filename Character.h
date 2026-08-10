#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
class Character {
    // Class definition
public:
    // Public members
    Character();
    void setName(const std::string &n);
    std::string getName() const;
    void setLevel(int l);
    int getLevel() const;
    void setHealth(int h);
    int getHealth() const;
    void setAttackPower(int ap);
    int getAttackPower() const;
    void setDefense(int d);
    int getDefense() const;
    void setExperiencePoints(int xp);
    int getExperiencePoints() const;
    void setStatus(const std::string &s);
    std::string getStatus() const;
    virtual void specialSkill() = 0; // Pure virtual function for special skill
    ~Character();

private:
    // Private members
    std::string name;
    int level;
    int health;
    int attack_power;
    int defense;
    int experience_points;
    std::string status;

};

#endif // CHARACTER_H