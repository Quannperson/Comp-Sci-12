#include <iostream>
using namespace std;

class Enemy
{
    public:
    int enemyAttack;
    int enemyHealth;

    int enemyUpdhealth(int playerAttack)
    {
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

    
    int playerUpdhealth(int enemyAttack)
    {
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