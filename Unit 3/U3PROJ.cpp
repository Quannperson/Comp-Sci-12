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
    public:
        int hp;
        int attack;
        int defence;
        string element;
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
            hp = 23;
            attack = 4;
            defence = 3;
            string name;
        }
};

class Ashaw: public Player
{
    public:
        Ashaw()
        {
            hp = 14;
            attack = 10;
            defence = 6;
            string name;
        }
};

class Quinn: public Player
{
    public:
        Quinn()
        {
            hp = 10;
            attack = 17;
            defence = 3;
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
        player = make_unique<Ashaw>();
    }
    else if(classSelect == "Quinn")
    {
        player = make_unique<Quinn>();
    }
    else
    {
        cout << "Huh? try again\n";
    }

    cout << "Your...\nHealth: " << player->hp;
    cout << "\nAttack: " << player->attack;
    cout << "\nDefence: " << player->defence;
    cout << "\nMagic: "<< player->element;

}