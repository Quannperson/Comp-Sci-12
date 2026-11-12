#include <iostream>
using namespace std;

class playerEnemy
{
    public:

        int attack;
        int health;

        playerEnemy(int attackInput, int healthInput)
        {
            attack = attackInput;
            health = healthInput;
        }

        void displayHealth(int health)
        {
            cout << health;
        }

        void displayAttack(int attack)
        {
            cout << attack;
        }
};

int main()
{
    playerEnemy alhadi(2, 11);
    playerEnemy quinn(4, 10);

    while(alhadi.health <= 0 || quinn.health <= 0)
    {
        cout << alhadi.attack - quinn.health << endl;
    }

    while(alhadi.health <= 0 || quinn.health <= 0)
    {
        cout << alhadi.attack - quinn.health << endl;
    }
}