#include <iostream>
#include <vector>
using namespace std;

class Enemy
{
    public:
        int enemyAttack = 2;
        int enemyHealth = 4;

        int enemyUpdHealth(int playerAttack)
        {
            enemyHealth = enemyHealth - playerAttack;
            return enemyHealth;
        }
};

class Player
{
    public:
        int playerAttack;
        int playerHealth;

        int playerUpdHealth(int enemyAttack)
        {
            playerHealth = playerHealth - enemyAttack;
            return playerHealth;
        }
};

int main()
{
    vector<Enemy> alhadis;

    for (int i = 0; i < 7; i++)
    {
        cout << "Adding an Alhadi to the list" << endl;
        alhadis.push_back(Enemy());
    }

    Player quinn = {4, 10};
    int choice = 0;

    while (true)
    {
        bool anyAlive = false;
        for (int i = 0; i < 7; i++)
        {
            if (alhadis[i].enemyHealth > 0)
            {
                anyAlive = true;
                break;
            }
        }

        if (!anyAlive || quinn.playerHealth <= 0)
        {
            break;
        }

        cout << "\nThe Alhadis attack!\n";
        for (int i = 0; i < 7; i++)
        {
            if (alhadis[i].enemyHealth > 0)
            {
                cout << "Alhadi " << i + 1 << " attacks!\n";
                quinn.playerUpdHealth(alhadis[i].enemyAttack);
                cout << "Quinn health: " << quinn.playerHealth << endl;
            }
        }

        if (quinn.playerHealth <= 0)
        {
            break;
        }

        cout << "Choose an enemy to attack (1-7): ";
        cin >> choice;

        while (choice < 1 || choice > 7 || alhadis[choice - 1].enemyHealth <= 0)
        {
            cout << "Invalid target. Choose a living enemy (1-7): ";
            cin >> choice;
        }

        alhadis[choice - 1].enemyUpdHealth(quinn.playerAttack);
        cout << "You hit Alhadi " << choice << ".\n";
        cout << "Alhadi " << choice << " health: " << alhadis[choice - 1].enemyHealth << endl;
    }

    if (quinn.playerHealth <= 0)
    {
        cout << "Defeat";
    }
    else
    {
        cout << "Big win!";
    }

    return 0;
}