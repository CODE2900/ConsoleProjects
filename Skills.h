#ifndef SKILLS_H
#define SKILLS_H

#include <string>
#include <vector>
#include "Character.h"  // CharacterClass must be defined before including this

using namespace std;

class Skills {
public:
    Skills(string name, int manacost, CharacterClass reqClass, int requiredlevel);

    string GetName() const;
    int GetManaCost() const;
    CharacterClass GetSkillClassType() const;
    int GetRequiredLevel() const;

    // Static function to return all skills (singleton pattern)
    static const vector<Skills>& GetAllSkills();

private:
    string skillName;
    int manaCost;
    CharacterClass skillType;
    int requiredLevel;
};

#endif
