#include <iostream>
#include <cstdlib> // for rand(), srand()
#include "Character.h"
using namespace std;


//Other properties method

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
void InitiateBattle(Player& player, Enemy& enemy)
{
    int commands;
    int Turn = 1;
    while (true)
    {
        cout << endl;
        cout << "TURN: " << Turn << endl;
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
        Turn += 1;

        if (player.GetHealth() <= 0)
        {
            cout << "Battle Over\n";
            break; //Breaks Loop
        }
        else if (enemy.GetEnemyHealth() <= 0)
        {
            player.GainExp(enemy.GetEnemyEXP());
            cout << "Battle Over\n";
            GainBuff(player);
            break; //Breaks Loop
        }
          


    }
}

void GainBuff(Player& player)
{
    int choice;

    cout << "Which Buff do you want to receive\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        //Heals
        player.SetHealth(5);
        break;
    case 2:
        //Upgrade
        player.GainStat();
    default:
        cout << "Invalid Buff Cmd\n";

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
        cout << endl;
        cout << player.GetName() << " Health: "
            << player.GetHealth() << std::endl;


        Enemy enemy("NULL", 0, 0, 0, 0); 

        if (player.GetLevel() >= 10)
            enemy = Enemy::GenerateMediunEnemy();
        else
            enemy = Enemy::GenerateBasicEnemy();

        cout << player.GetName() << " encounters " << enemy.GetEnemyName() << endl;

        InitiateBattle(player, enemy);
    }


    return 0;
}
