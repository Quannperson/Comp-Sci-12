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

    for(int i = 0; i < 7; i++)
    {
        cout << "Adding an Alhadi to the list" << endl;
        alhadis.push_back(Enemy());
    }

    Player quinn = {4, 10};

    for(int i = 0; i < 7; i++)
    {
        Enemy& alhadi = alhadis[i];

        cout << "Alhadi" << i + 1 << "challenges Quinn!\n";
 
        while(alhadis[i].enemyHealth > 0 && quinn.playerHealth > 0)
        {
            cout << alhadis[i].enemyUpdHealth(quinn.playerAttack) << endl;
            cout << quinn.playerUpdHealth(alhadi.enemyAttack) << endl;
        }
        i++;
    }

    if(quinn.playerHealth == 0)
    {
        cout << "Defeat";
    }
    else
    {
        cout << "Big win!";
    }
}