#include <iostream>
#include <cstdlib> // for rand(), srand()
#include "Character.h"
using namespace std;


//Other properties method

void CharacterCreation(Player& player)
{
    int selection;
    string nameInput;
    cout << "Input Character Name\n";
    cin >> nameInput;
    player.SetCharacterName(nameInput);
    while (true)
    {
        cout << "Select your character\n";
        std::cout << "1. Knight 2. Ranger 3. Mage\n";

        cin >> selection;

        switch (selection)
        {
        case 1:
            player.SetCharacterClass(CharacterClass::Knight);
            return;
        case 2:
            player.SetCharacterClass(CharacterClass::Ranger);
            return;
        case 3:
            player.SetCharacterClass(CharacterClass::Mage);
            return;
        default:
            cout << "Invalid Pick\n";
            //loop
        }
    }
}
void ShowCharacterStats(Player& player)
{
    cout << endl;
    cout << "Name: " << player.GetName() << endl;
    cout << "Class: " << player.GetClassName(player.GetCharacterClass()) << endl;
    cout << "Current HP: " << player.GetHealth() << endl;
    cout << "Level: " << player.GetLevel() << endl;
    cout << endl;


}
void GainBuff(Player& player)
{
    int choice;

    cout << "Which Buff do you want to receive\n";
    cout << "1) Heal 2) StatBonus\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        //Heals
        player.HealHealth(10);
        break;
    case 2:
        //Upgrade
        player.GainStat();
        break;
    default:
        cout << "Invalid Buff Cmd\n";

    }

}
void CastSkill(Player& player, Enemy& enemy)
{   
    const auto& skills = player.GetSkills();

    cout << "\nChoose a skill:\n";
    for (size_t i = 0; i < skills.size(); i++)
    {
        cout << i + 1 << ") "
            << skills[i].GetName()
            << " (Mana: " << skills[i].GetManaCost() << ")\n";
    }

    int choice;
    cin >> choice;
    choice--;

    if (choice < 0 || choice >= skills.size())
    {
        cout << "Invalid skill selection\n";
        return;
    }

    const Skills& skill = skills[choice];

    if (!player.UseMana(skill.GetManaCost()))
    {
        cout << "Not enough mana!\n";
        return;
    }

    int totalDamage = player.Damage() + skill.GetSkillDmg();

    cout << player.GetName()
        << " casts " << skill.GetName()
        << " for " << totalDamage << " damage!\n";

    enemy.TakeDamage(totalDamage);
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
        cout << "Command: 1) Attack 2) Defend 3) Skill\n";
        cin >> commands;

        switch (commands)
        {
        case 1:
            cout << "Player Deals: " << player.Damage() << endl;
            enemy.TakeDamage(player.Damage());
            break;
        case 2:
            cout << "Player Defends" << endl;
            player.HealHealth(5);
            break;
        case 3:
            if (player.HasSkills())
            {
                CastSkill(player,enemy);
                break;
            }
            else
            {
                cout << "No Skills" << endl;
                continue;
            }
               
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

int main()
{
    Player player("Unknown", 100,20, 4 , 10, 5, 5,25);
    CharacterCreation(player);
    ShowCharacterStats(player);


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
            enemy = Enemy::GenerateMediumEnemy();
        else
            enemy = Enemy::GenerateBasicEnemy();

        cout << player.GetName() << " encounters " << enemy.GetEnemyName() << endl;

        InitiateBattle(player, enemy);
    }


    return 0;
}
