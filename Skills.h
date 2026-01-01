#ifndef Skills_H
#define Skills_H

#include <string>
using namespace std;


enum class SkillType
{
    Knight,
    Ranger,
    Mage
};

class Skills
{
public:
	Skills(string name, int manacost,SkillType skills);


private:
    string skillName;
    int manaCost;
    SkillType skillType;
};

#endif