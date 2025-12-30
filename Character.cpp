#include "Character.h"
#include <iostream>
#include <cstdlib> // for rand(), srand()
using namespace std;


// Player Properties & Methods
Player::Player(string name, int health, int level, int MaxExp, int Atk, int Def)
{
    Name = name;
    Health = health;
    Level = level;
    ATK = Atk;
    DEF = Def;
    MaxEXP = MaxExp;
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
    return ATK;
}

int Player::GetHealth() const
{
    return Health;
}
int Player::SetHealth(int amount)
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

void Player::LevelUp(int amount)
{
    Level += amount;
    cout << "LEVEL UP: " << Level << endl;;

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
    int random = rand() % 2;

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
    default:
        break;
    }
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
    int randomNum = rand() % 4;

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
Enemy Enemy::GenerateMediunEnemy()
{
    int randomNum = rand() % 4;

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
