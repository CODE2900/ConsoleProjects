#ifndef Character_H
#define Character_H

#include <string>
using namespace std;

class Player {
public:
    Player(string name, int health,int level,int MaxExp, int Atk, int Def); // constructor

    string SetCharacterName(string name);
    void TakeDamage(int amount);
    void Defend(int damageReceive);
    int Damage();
    int GetHealth() const;
    int SetHealth(int amount);
    string GetName() const;
    int GetLevel() const;
    void LevelUp(int anount);
    void GainExp(int amount);
    void GainStat();

private:
    string Name;
    int Health;
    int Level;
    int CurrentEXP = 0;
    int MaxEXP;
    int ATK;
    int DEF;
};

class Enemy {
public:
    Enemy(string name, int HP,int Atk,int Def,int EXP);
    static Enemy GenerateBasicEnemy();
    static Enemy GenerateMediunEnemy();
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