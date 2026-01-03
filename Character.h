#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

// Forward declare Skills for Player class
class Skills;
using namespace std;

// Define CharacterClass BEFORE Skills.h
enum class CharacterClass
{
    Knight,
    Ranger,
    Mage
};

// Include Skills.h AFTER CharacterClass is known
#include "Skills.h"

class Player {
public:
    Player(string name, int health, int mana, int level, int MaxExp, int Atk, int Def, int CritRate);

    string SetCharacterName(string name);
    void TakeDamage(int amount);
    int Damage();
    int GetHealth() const;
    int HealHealth(int amount);
    string GetName() const;
    int GetLevel() const;
    bool HasSkills() const;
    string GetClassName(CharacterClass classGet) const;
    CharacterClass GetCharacterClass() const;
    CharacterClass SetCharacterClass(CharacterClass setClass);
    void LevelUp(int amount);
    void GainExp(int amount);
    void GainStat();
    void CheckSkillUnlock();
    int GetMana() const;
    bool UseMana(int cost);
    const vector<Skills>& GetSkills() const;


private:
    string Name;
    int Health;
    int Mana;
    int Level;
    int CurrentEXP = 0;
    int MaxEXP;
    int ATK;
    int DEF;
    int CriticalRate;
    CharacterClass CharClass;
    vector<Skills> skills;
};

class Enemy {
public:
    Enemy(string name, int HP, int Atk, int Def, int EXP);
    static Enemy GenerateBasicEnemy();
    static Enemy GenerateMediumEnemy();
    void TakeDamage(int dmg);
    int Damage();
    int GetEnemyHealth() const;
    string GetEnemyName() const;
    int GetEnemyEXP() const;

private:
    string Name;
    int Health;
    int ATK;
    int DEF;
    int EXP;
};
#endif
