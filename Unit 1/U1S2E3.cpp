#include <iostream>

using namespace std;
int main ()

{

    string name;
    char hand;
    short int age;
    short int phone;

    cout << "What is your name?\n";
    cin >> name;

    cout << "Are you left or right handed?\n";
    cin >> hand;

    cout << "What is your age?\n";
    cin >> age;

    cout << "What is your phone number?\n";
    cin >> phone;

    cout << "\n Cool!, your name is " << name << " ,you are " << age << " years old and your phone number is " << phone << "!" << endl;

}