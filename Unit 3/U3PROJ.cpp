#include <iostream>
#include <memory>
using namespace std;

class Entity
{
    protected:
        int hp;
        int attack;
        int defence;
        string name;
};

class Player: public Entity
{
    protected:
        int hp;
        int attack;
        int defence;
};

class Enemy: public Entity
{
    protected:
        int hp = 5;
        int attack = 3;
        int defence = 1;
};

class Alhadi: public Player
{
    public:
        Alhadi()
        {
            int hp = 23;
            int attack = 4;
            int defence = 3;
            string name;
        }
};

class Ashaw: public Player
{
    public:
        Ashaw()
        {
            int hp = 14;
            int attack = 10;
            int defence = 6;
            string name;
        }
};

class Quinn: public Player
{
    public:
        Quinn()
        {
            int hp = 10;
            int attack = 17;
            int defence = 3;
            string name;
        }
};

int main()
{
    string classSelect;
    string name;

    cout << "Welcome player! What is your name?" << endl;
    cin >> name;
    cout << "\nBattle is soon, please select what class you would like to play!\nAlhadi-Ashaw-Quinn" << endl;
    cin >> classSelect;

    unique_ptr<Player> player;

    if(classSelect == "Alhadi")
    {
        player = make_unique<Alhadi>();
    } 
    else if(classSelect == "Ashaw")
    {
        player = make_unique<Alhadi>();
    }
    else if(classSelect == "Quinn")
    {
        player = make_unique<Alhadi>();
    }

    cout << "Your health: " << player->hp;
    cout << "Your attack: " << player->attack;
    cout << "Your defence: " << player->defence;

}