#include "Skills.h"
#include <iostream>

Skills::Skills(string name, int cost, CharacterClass reqClass, int requiredlevel)
{
    skillName = name;
    manaCost = cost;
    skillType = reqClass;
    requiredLevel = requiredlevel;
}

string Skills::GetName() const 
{ 
    return skillName; 
}
int Skills::GetManaCost() const 
{ 
    return manaCost; 
}
CharacterClass Skills::GetSkillClassType() const 
{ 
    return skillType; 
}
int Skills::GetRequiredLevel() const 
{ 
    return requiredLevel; 
}

const vector<Skills>& Skills::GetAllSkills() {
    static vector<Skills> allSkills = {
        Skills("Slash", 5, CharacterClass::Knight, 5),
        Skills("Shield Bash", 8, CharacterClass::Knight, 10),
        Skills("Power Shot", 6, CharacterClass::Ranger, 5),
        Skills("Multi Shot", 10, CharacterClass::Ranger, 10),
        Skills("Fireball", 7, CharacterClass::Mage, 5),
        Skills("Lightning", 12, CharacterClass::Mage, 10)
    };
    return allSkills;
}
