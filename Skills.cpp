#include "Skills.h"
#include <iostream>

Skills::Skills(string name, int cost,int dmg, CharacterClass reqClass, int requiredlevel)
{
    skillName = name;
    manaCost = cost;
    damage = dmg;
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
int Skills::GetSkillDmg() const
{
    return damage;
}

const vector<Skills>& Skills::GetAllSkills() {
    static vector<Skills> allSkills = {
        Skills("Slash", 5, 10,CharacterClass::Knight, 5),
        Skills("Shield Bash", 8,15, CharacterClass::Knight, 10),
        Skills("Power Shot", 6,10, CharacterClass::Ranger, 5),
        Skills("Multi Shot", 10,15, CharacterClass::Ranger, 10),
        Skills("Fireball", 7, 10,CharacterClass::Mage, 5),
        Skills("Lightning", 12,15, CharacterClass::Mage, 10)
    };
    return allSkills;
}
