#include "Character.h"
#include <iostream>
#include <cstdlib> // for rand(), srand()
using namespace std;

// Player Properties & Methods
Player::Player(string name, int health, int mana,int level, int MaxExp, int Atk, int Def, int CritRate)
{
    Name = name;
    Health = health;
    Mana = mana;
    Level = level;
    ATK = Atk;
    DEF = Def;
    MaxEXP = MaxExp;
    CriticalRate = CritRate;
}

void Player::TakeDamage(int dmg)
{
    int finalDamage = dmg - DEF;

    if (finalDamage < 1)
        finalDamage = 1;

    Health -= finalDamage;

    if (Health < 0)
        Health = 0;

    cout << Name << " takes " << finalDamage << " damage!\n";
}

string Player::SetCharacterName(string name)
{
    Name = name;
    return Name;
}

int Player::Damage()
{
    if (rand() % 100 < CriticalRate) // trigger critical chance
    {
        int critDMG = ATK * 2;
        return critDMG;
    }
    else
        return ATK;
}

int Player::GetHealth() const
{
    return Health;
}
int Player::HealHealth(int amount)
{
    return Health += amount;
}

string Player::GetName() const
{
    return Name;
}
int Player::GetLevel() const
{
    return Level;
}
bool Player::HasSkills() const
{
    if (skills.size() <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
string Player::GetClassName(CharacterClass classGet) const
{
    switch (classGet)
    {
    case CharacterClass::Knight: 
        return "Knight";
    case CharacterClass::Ranger: 
        return "Ranger";
    case CharacterClass::Mage:   
        return "Mage";
    default: 
        return "Unknown";
    }
}
CharacterClass Player::GetCharacterClass() const
{
    return CharClass;
}
CharacterClass Player::SetCharacterClass(CharacterClass setClass)
{
    CharClass = setClass;
    return CharClass;
}

void Player::LevelUp(int amount)
{
    Level += amount;
    cout << "LEVEL UP: " << Level << endl;;
    Mana += 10;

    CheckSkillUnlock();

}
void Player::GainExp(int amount)
{
    CurrentEXP += amount;
    cout << "EXP Gain: " << amount << endl;
    cout << "EXP: " << CurrentEXP << "/" << MaxEXP << endl;

    if (CurrentEXP >= MaxEXP)
    {
        CurrentEXP -= MaxEXP;
        LevelUp(1);
        MaxEXP += 10;
    }
}
void Player::GainStat()
{
    int random = rand() % 3;

    switch (random)
    {
    case 0:
        ATK += (rand() % 3) + 1;
        cout << "ATK increase to " << ATK;
        break;
    case 1:
        DEF += (rand() % 3) + 1;
        cout << "DEF increase to " << DEF;
        break;
    case 2:
        CriticalRate += (rand() % 3) + 1;
        cout << "CritRate increase to " << CriticalRate;
        break;
    default:
        break;
    }
}

void Player::CheckSkillUnlock() {
    for (const Skills& skill : Skills::GetAllSkills()) 
    {
        // Skip skills for other classes or higher level than player
        if (CharClass != skill.GetSkillClassType() || Level < skill.GetRequiredLevel())
            continue;

        // Prevent duplicates
        bool alreadyLearned = false;
        for (const auto& learned : skills) {
            if (learned.GetName() == skill.GetName()) {
                alreadyLearned = true;
                break;
            }
        }
        if (alreadyLearned) continue;

        skills.push_back(skill);
        std::cout << "Unlocked skill: " << skill.GetName() << std::endl;
    }
}
int Player::GetMana() const
{
    return Mana;
}

bool Player::UseMana(int cost)
{
    if (Mana < cost)
        return false;

    Mana -= cost;
    return true;
}

const vector<Skills>& Player::GetSkills() const
{
    return skills;
}



// Enemy - Properties & Methods
Enemy::Enemy(string name, int HP, int Atk, int Def, int Exp)
{
    Name = name;
    Health = HP;
    ATK = Atk;
    DEF = Def;
    EXP = Exp;
}
Enemy Enemy::GenerateBasicEnemy()
{
    int randomNum = rand() % 3;

    switch (randomNum)
    {
    case 0:
        return Enemy("Slime", 10, 1, 2, 2);
    case 1:
        return Enemy("Goblin", 15, 3, 1, 3);
    case 2:
        return Enemy("Wolf", 18, 3, 1, 3);
    default:
        return Enemy("NULL", 0, 0, 0, 0);
    }
}
Enemy Enemy::GenerateMediumEnemy()
{
    int randomNum = rand() % 3;

    switch (randomNum)
    {
    case 0:
        return Enemy("MediumSlim", 20, 3, 3, 4);
    case 1:
        return Enemy("Ogre", 30, 5, 3, 5);
    case 2:
        return Enemy("Boar", 25, 3, 2, 3);
    default:
        return Enemy("NULL", 0, 0, 0, 0);
    }
}
void Enemy::TakeDamage(int dmg)
{
    int finalDamage = dmg - DEF;

    if (finalDamage < 1)
        finalDamage = 1;

    Health -= finalDamage;

    if (Health < 0)
        Health = 0;

    cout << Name << " takes " << finalDamage << " damage!\n";
}
int Enemy::Damage()
{
    int extra = rand() % (ATK + 3);
    return ATK + extra;
}
int Enemy::GetEnemyHealth() const
{
    return Health;
}
string Enemy::GetEnemyName() const
{
    return Name;
}
int Enemy::GetEnemyEXP() const
{
    return EXP;
}
