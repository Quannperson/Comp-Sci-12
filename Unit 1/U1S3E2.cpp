#include <iostream>

using namespace std;
int main ()

{
    int number;

    cout << "Please enter a number\n";
    cin >> number;

    if (number != 0)
    {

        if (number % 2 != 0)
        {
            if (number < 0)
            {
                cout << "\nYour number is negative and odd!" << endl;
            }
            else
            {
                cout << "\nYour number is positive and odd!" << endl;
            }
        }
        else
        {
            cout << "\nYour number is even!" << endl;
        }

    }
    else
    {
        cout << "\nYour number is zero!" << endl;
    }

}