#include <iostream>
#include <random>
using namespace std;

class Enemy
{
    public:
    int enemyAttack;
    int enemyHealth;

    random_device rd;
    mt19937 gen{rd()}; //braces are magic?
    uniform_int_distribution<int> playerCritRange{1, 100};
    
    int roll = playerCritRange(gen);
    
    int enemyUpdhealth(int playerAttack)
    {
        if(roll <= 10)
        {
            enemyAttack = enemyAttack * 1.35;
        }

        cout << "\n" << enemyHealth - playerAttack << endl;
        return enemyHealth;
    }

    void enemyHealthbar()
    {
        cout << "|";

        for(int i = 0; i < enemyHealth; i++)
        {
            cout << "--|";
        }
    }
};

class Player
{
    public:
    int playerAttack;
    int playerHealth;

    random_device rd;
    mt19937 gen{rd()}; //braces are magic?
    uniform_int_distribution<int> enemyCritRange{1, 100};

    int roll = enemyCritRange(gen);

    int playerUpdhealth(int enemyAttack)
    {
        if(roll <= 10)
        {
            playerAttack = playerAttack * 1.35;
        }

        cout << "\n" << playerHealth - enemyAttack << endl;
        return playerHealth;
    }

        void playerHealthbar()
    {
        cout << "|";

        for(int i = 0; i < playerHealth; i++)
        {
            cout << "--|";
        }
    }
};

int main()
{
    Enemy alhadi = {2, 11};
    Player quinn = {4, 10};

    while(alhadi.enemyHealth <= 0 || quinn.playerHealth <= 0)
    {
        alhadi.enemyUpdhealth(quinn.playerAttack);
        quinn.playerUpdhealth(alhadi.enemyAttack);
    }
}