#include <iostream>
#include <cstdlib> // for rand(), srand()
#include "Character.h"
using namespace std;

// Player Properties & Methods
Player::Player(string name, int health, int level,int MaxExp, int Atk, int Def)
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

string Player::GetName() const
{
    return Name;
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

void CharacterSelection(Player& player)
{
    int selection;
    while (true)
    {
        cout << "Select your character\n";
        std::cout << "1. Knight 2. Ranger 3. Mage\n";

        cin >> selection;

        switch (selection)
        {
        case 1:
            player.SetCharacterName("Knight");
            return;
        case 2:
            player.SetCharacterName("Ranger");
            return;
        case 3:
            player.SetCharacterName("Mage");
            return;
        default:
            cout << "Invalid Pick\n";
            //loop
        }
    }
}
// Enemy - Properties & Methods
Enemy::Enemy(string name, int HP, int Atk, int Def,int Exp)
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
        return Enemy("Slime", 20, 1, 2, 2);
    case 1:
        return Enemy("Goblin", 25, 3, 1, 3);
    case 2:
        return Enemy("Wolf", 30, 3, 1, 3);
    default:
        return Enemy("NULL", 0, 0, 0,0);
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

//Other properties method
void InitiateBattle(Player& player, Enemy& enemy)
{
    int commands;
    while (true)
    {
        cout << "PlayerStats: "<< player.GetName() <<" HP: " << player.GetHealth() << endl;
        cout << "EnemyStats: " << enemy.GetEnemyName() << " HP: " << enemy.GetEnemyHealth() << endl;
        cout << "Command: 1) Attack 2) Defend\n";
        cin >> commands;

        switch (commands)
        {
        case 1:
            cout << "Player Deals: " << player.Damage() << endl;
            enemy.TakeDamage(player.Damage());
            break;
        default:
            cout << "Invalid Cmd\n";
            continue;
        }

        player.TakeDamage(enemy.Damage());

        if (player.GetHealth() <= 0)
        {
            cout << "Battle Over\n";
            break; //Breaks Loop
        }
        else if (enemy.GetEnemyHealth() <= 0)
        {
            player.GainExp(enemy.GetEnemyEXP());
            cout << "Battle Over\n";
            break; //Breaks Loop
        }
          


    }
}

int main()
{
    Player player("Unknown", 100, 1 , 10, 5, 5);
    CharacterSelection(player);



  /*  cout << player.GetName() << " Health: "
        << player.GetHealth() << std::endl;*/

    //player.TakeDamage(25);

    while (player.GetHealth() > 0)
    {
        cout << player.GetName() << " Health: "
            << player.GetHealth() << std::endl;

        Enemy enemy = Enemy::GenerateBasicEnemy();

        cout << player.GetName() << " encounters " << enemy.GetEnemyName() << endl;

        InitiateBattle(player, enemy);
    }


    return 0;
}
