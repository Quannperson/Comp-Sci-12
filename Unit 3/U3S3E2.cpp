#include <iostream>
using namespace std;

class Enemy
{
    public:
    int enemyAttack;
    int enemyHealth;

    int enemyUpdhealth(int playerAttack)
    {
        cout << enemyHealth - playerAttack;
        return enemyHealth;
    }
};

class Player
{
    public:
    int playerAttack;
    int playerHealth;

    int playerUpdhealth(int enemyAttack)
    {
        cout << playerHealth - enemyAttack;
        return playerHealth;
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
