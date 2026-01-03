#ifndef SKILLS_H
#define SKILLS_H

#include <string>
#include <vector>
#include "Character.h"  // CharacterClass must be defined before including this

using namespace std;

class Skills {
public:
    Skills(string name, int manacost,int dmg, CharacterClass reqClass, int requiredlevel);

    string GetName() const;
    int GetManaCost() const;
    CharacterClass GetSkillClassType() const;
    int GetRequiredLevel() const;
    int GetSkillDmg() const;

    static const vector<Skills>& GetAllSkills();

private:
    string skillName;
    int manaCost;
    CharacterClass skillType;
    int requiredLevel;
    int damage;
};

#endif
