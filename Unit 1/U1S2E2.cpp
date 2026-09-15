#include <iostream>

using namespace std;
int main ()

{
    //Variables
    int number;
    short broken = number;

    //Main
    cout << "Input your favourite 8- digit number!\n";
    cin >> number;

    cout << "\nWas this your number?\n";
    cout << "Number: " << broken << "\n Oh, it looks like your number broke" << endl;

}