#include <iostream>
#include <vector>
using namespace std;

class Enemy
{
    public:
        int enemyAttack = 2;
        int enemyHealth = 4;

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
    vector<vector<Enemy>> alhadis;

    for (int i = 0; i <= 7; i++)
    {
        cout << "Adding an Alhadi to the array" << endl;
        alhadis.push_back(vector<Enemy>{Enemy()});

    }
    Player quinn = {4, 10};
}