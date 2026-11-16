#include <iostream>
using namespace std;

class Mammal
{
    protected:
        int legs = 4;
        int eyes = 2;
        bool isVertebrate = true;
        bool isWarmBlooded = true;
};

class Whale: public Mammal
{
    public:
        string species = "Whale";
        int legs = 0;

        void makeSound()
        {
            "aaaoooooo click-click-click";
        }
};