#include <iostream>

using namespace std;
int main ()
{
    //Variables
    int number = 0;
    unsigned int maxInt = number - 1;
    unsigned short maxShort = maxInt;
    unsigned long maxLong = number - 1; 
    //Trying to make variable go lower than min --> max, overflowing int --> short reaches short's max (divisible)

    //Main
    cout << "The minimum of int is: " << number;
    cout << "\nThe maximum of int is: " << maxInt << endl;

    cout << "\nThe minimum of short is: " << number;
    cout << "\nThe maximum of short is: " << maxShort << endl;

    cout << "\nThe minimum of long is: " << number;
    cout << "\nThe maximum of long is: " << maxLong;

}