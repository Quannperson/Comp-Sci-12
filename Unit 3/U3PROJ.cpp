#include <iostream>
using namespace std;

class Entity
{
    protected:
    int hp;
    int attack;
    int defence;
    string name;
};

class Alhadi: public Entity
{
    int hp = 23;
    int attack = 4;
    int defence = 3;
    string name = "Alhadi";
};

class Ashaw: public Entity
{
    int hp = 14;
    int attack = 10;
    int defence = 6;
    string name = "Ashaw";
};

class idk: public Entity
{
    int hp = 10;
    int attack = 17;
    int defence = 3;
};

class Player: public Entity
{
    int hp;
    int attack;
    int defence;
};

class Enemy: public Entity
{
    int hp = 5;
    int attack = 3;
    int defence = 1;
};

int main()
{
    string classSelect;
    string name;

    cout << "Welcome player! What is your name?" << endl;
    cin >> name;
    cout << "\nBattle is soon, please select what class you would like to play!\nAlhadi-Ashaw-Idk" << endl;
    cin >> classSelect;

    if(classSelect == "Alhadi")
    {
        Player name = {Alhadi.hp, Alhadi.}
    }
}