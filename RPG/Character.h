#ifndef Character_H
#define Character_H

#include <string>
using namespace std;

class Player {
public:
    Player(string name, int health, int Atk, int Def); // constructor

    string SetCharacterName(string name);
    void TakeDamage(int amount);
    int Damage();
    int GetHealth() const;
    string GetName() const;

private:
    string Name;
    int Health;
    int ATK;
    int DEF;
};

class Enemy {
public:
    Enemy(string name, int HP,int Atk,int Def);
    static Enemy GenerateBasicEnemy();
    void TakeDamage(int dmg);
    int Damage();
    int GetEnemyHealth() const;
    string GetEnemyName() const;

private:
    string Name;
    int Health;
    int ATK;
    int DEF;
};


#endif