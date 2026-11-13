#include <iostream>
using namespace std;

class Enemy
{
    private:
        int enemyAttack;
        int enemyHealth;

    public:
        void setEnemy(int A1, int H1)
        {
            enemyAttack = A1;
            enemyHealth = H1;
        }

        int getEnemyHealth()
        {
            return enemyHealth;
        }

        int getEnemyAttack()
        {
            return enemyAttack;
        }

        int enemyUpdHealth(int playerAttack)
        {
            cout << enemyHealth - playerAttack;
            return enemyHealth;
        }
};

class Player
{
    private:
        int playerAttack;
        int playerHealth;

    public:
        void setPlayer(int A2, int H2)
        {
            playerAttack = A2;
            playerHealth = H2;
        }

        int getPlayerHealth()
        {
            return playerHealth;
        }

        int getPlayerAttack()
        {
            return playerAttack;
        }

        int playerUpdHealth(int enemyAttack)
        {
            cout << playerHealth - enemyAttack;
            return playerHealth;
        }
};

int main()
{ 
    Enemy alhadi;
    alhadi.setEnemy(2, 11);
    alhadi.getEnemyAttack();
    alhadi.getEnemyHealth();

    Player quinn;
    quinn.setPlayer(4, 10);
    quinn.getPlayerAttack();
    quinn.getPlayerHealth();

    while(alhadi.getEnemyHealth() <= 0 || quinn.getPlayerHealth() <= 0)
    {
        alhadi.enemyUpdHealth(quinn.getPlayerAttack());
        quinn.playerUpdHealth(alhadi.getEnemyAttack());
    }
}
