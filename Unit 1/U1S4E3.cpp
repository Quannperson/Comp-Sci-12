#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main ()

{
    cout << "Lets see a cool pattern!";

    //sets variable that counts up, other variable counts up when less than first count
    //outputs asterisk until a = i, repeats till 5
    for (int i = 0; i < 5; i++)
    {
        for (int a = 0; a < i; a++)
        {
            cout << "*";
        }
        cout << endl;
    }
}